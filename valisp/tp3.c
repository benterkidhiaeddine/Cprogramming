#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>
#include "lib_memoire.h"
#include "lib_tests.h"
#include "lib_repl.h"
#include "erreurs.h"
#include "couleurs.h"
#include "parseur.h"
#include "allocateur.h"
#include "types.h"
#include "primitives.h"
#include "environnement.h"

#include <readline/readline.h>
#include <readline/history.h>




/******************/
/*                */
/*  Déclarations  */
/*                */
/******************/

/* Les déclarations ci-dessous me permettent d’utiliser du code que
   l’étudiant n’a pas encore déclaré. Cette fonctionnalité ne fait pas
   partie du standart ANSI, mais cela permet de fortement simplifier
   le TP pour les étudiants */

#pragma weak environnement_global
sexpr environnement_global(void);

#pragma weak initialiser_memoire
void initialiser_memoire(void);

#pragma weak charger_primitives
void charger_primitives(void);


#pragma weak trouver_variable
int trouver_variable(sexpr env, sexpr variable, sexpr *resultat);

#pragma weak defvar_valisp
sexpr defvar_valisp(sexpr, sexpr);

#pragma weak setq_valisp
sexpr setq_valisp(sexpr, sexpr);



/********************/
/*                  */
/*  Le REPL du TP2  */
/*                  */
/********************/

void afficher_banniere_tp3(void) {
    printf("%sVa%sλ%sisp TP3%s\n\n",
           couleur_vert,
           couleur_jaune,
           couleur_vert,
           couleur_defaut);
}


int repl_tp3(void) {
    char* invite_defaut = "\001\033[1;33m\002tp3>\001\033[1;0m\002 ";
    char* invite = invite_defaut;
    char* ligne;
    char BUFFER_READ[10000];
    int POSITION = 0;
    sexpr val;
    sexpr e;
    int res;
    jmp_buf *buf  = jump_buffer();

    using_history();

    printf("%s@aide%s pour afficher les directives du REPL\n",
           couleur_bleu, couleur_defaut);                              /********/
    while (1) {                                                        /* LOOP */
                                                                       /********/
        ligne = readline(invite);
        if (ligne == NULL) break;
        if (ligne[0] == '\0')  continue ;


        if (!setjmp(*buf)) { /* En cas d’erreur, le code reprend à partir du else */

            /* On gère les directives */
            if (ligne[0] == '@') {
                int numero_tp = 3;
                add_history(ligne);
                lire_directive(ligne, numero_tp);
                free(ligne);
                continue;
            }

            /* La ligne est ajoutée à un buffer pour permettre des
             * expressions sur plusieurs lignes. Un expression
             * incopmlète renvoie le code -2 et la prochaine ligne lue
             * sera alors ajoutée à la suite du buffer à l’indice
             * POSITION qui n’aura pas été réinitialisé */

            POSITION = ajout_buffer(BUFFER_READ, POSITION, ligne);
            free(ligne);                                               /********/
            res = valisp_read(BUFFER_READ, &val);                      /* READ */
                                                                       /********/

            /* L’expression est vide, on ignore et on continue */
            if (res == -1) {
                continue;
            }

            /* L’expression n’est pas finie, on refait un tour pour la finir */
            if (res == -2)  {
                invite = "       ";
                continue;
            }

            /* Il n'y pas d’autre code d’erreur négatif possible */
            if (res < 0) {
                char msg[100];
                sprintf(msg, "erreur du parseur invalide [%d]\n", res);
                ERREUR_FATALE(msg);
            }

            /* On sauvegarde l’entrée dans l’historique et on
             * réinitialise le tout */
            supprime_retour_ligne_finale_buffer(BUFFER_READ);
            add_history(BUFFER_READ);
            invite = invite_defaut;
            POSITION=0;

            if (res > 0) {
                erreur_parseur("Pas plus d’une sexpr par ligne");
            }


            /* On a réussi à lire l’expression. On peut alors           ********
             * l’évaluer. Dans le REPL, l’utilisateur peut entrer :     * EVAL *
             * - un entier   : qui s’auto-évalue                        ********
             * - une chaîne  : qui s'auto-évalue
             * - nil         : qui s'auto-évalue
             * - un symmbole : on recherche sa valeur dans l’environnement
             * - un cons     : de la formae (f . arg) ; on cherche f dans
                               l’environnement avant d’appeler la primitive
             */


            if (val==NULL || integer_p(val) || string_p(val)) {
                e = val;
                goto afficher;
            }

            if (trouver_variable == NULL) {
                printf("Il faut implémenter la fonction « trouver variables »\n");
                continue;
            }

            if (cons_p(val)) {
                sexpr a = cdr(val);

                if (!symbol_p(car(val))) {
                    erreur(TYPAGE, "Runtime/repl", "Pas un symbole", car(val));
                }

                if (trouver_variable(environnement_global(), car(val), &e)) {
                    erreur(NOM, "Runtime/repl", "Variable inconnue", car(val));
                }

                e = run_prim(e, a, environnement_global());
            }

            if (symbol_p(val)) {
                if (trouver_variable(environnement_global(), val, &e)) {
                    erreur(NOM, "Runtime/repl", NULL, val);
                }
            }

            afficher:
            printf("%s", couleur_vert);                                  /*********/
            afficher(e);                                                 /* PRINT */
            printf("%s", couleur_defaut);                                /*********/

        } else {
            /* Si on rencontre une « exception » */
            printf("%s", couleur_rouge);
            afficher_erreur();
            printf("%s", couleur_defaut);
        }

        printf("\n\n");
    }

    return 0;
}


int tp3_main(int argc, char *argv[]) {
    cacher_tests();
    test_tp1_obligatoire(); /* On teste uniquement les fonctions jusqu’à malloc */
    test_tp2();
    montrer_tests();
    test_tp3();

    afficher_banniere_tp3();
    printf("Initialisation mémoire");
    /* initialiser_memoire_dynamique(); */
    initialiser_memoire();
    printf(" [OK]\n");

    /* Pour ceux qui souhaite lancer uniquement les tests sans lancer
     * le REPL il suffit de donner un paramètre au programme par exemple :
     * ./valisp --test
     */
    if (argc<2) {
        repl_tp3();
    }
    return 0;
}
