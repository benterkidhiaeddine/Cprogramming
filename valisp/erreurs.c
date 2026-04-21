#include <stdio.h>
#include <setjmp.h>
#include <stdlib.h>
#include "couleurs.h"
#include "erreurs.h"



sexpr SEXPR_ERREUR;
char *FONCTION_ERREUR;
char *MESSAGE_ERREUR;
enum erreurs TYPE_ERREUR;


/**********************/
/*                    */
/* Erreurs Non Fatales */
/*                    */
/**********************/




/**********************/
/*                    */
/*  Erreurs Fatales   */
/*                    */
/**********************/

/* Pour s’arrêter lorsque le développeur tombe sur cas qui ne devrait
   jamais arriver. Normalement, si le programme est écrit sans bugs,
   les erreurs fatales ne devrait jamais être rencontrées.

   La variable TEST_ERREUR_FATALE permet l’écriture de test pour
   intercepter l’erreur lors des tests
*/

int TEST_ERREUR_FATALE = 0;


void erreur_fatale(char  *fichier, int ligne, char *causes) {
    if (TEST_ERREUR_FATALE--) return;
    fprintf(stderr,"%s", couleur_rouge);
    fprintf(stderr,"\n   /!\\ Erreur fatale /!\\");
    fprintf(stderr,"%s", couleur_defaut);
    fprintf(stderr,"   %s ligne %d\n\n", fichier, ligne);
    fprintf(stderr,"%s\n", causes);
    exit(1);
}



/**************************/
/*                        */
/*  Gestion du long jump  */
/*                        */
/**************************/

/* Merci de lire le cours pour comprendre ce que fait le type
   jmp_buf. Rapidement, c’est une structure qui sauvegarde l’état du
   programme que l’on pourra restaurer en cas d’erreur. On l’utilisera
   lors de l’exercice 11 */

jmp_buf buf;

jmp_buf *jump_buffer(void) {
    return &buf;
}
 
void erreur(enum erreurs type, char *fonction, char *explication, sexpr s){
    SEXPR_ERREUR = s;
    FONCTION_ERREUR = fonction;
    MESSAGE_ERREUR = explication;
    TYPE_ERREUR = type;
    longjmp(&buf, 1);
}

/*
    Erreur d’exécution [TYPAGE] : nécessite un entier
    Fonction fautive : « + »
    Valeur fautive : «"saucisse"»
*/


char* afficher_type_erreur(enum erreurs type){
    switch (type)
    {
    case TYPAGE:
        return ("TYPAGE");
     case ARITE:
        return ("ARITE");
     case NOM:
        return ("NOM");
     case MEMOIRE:
        return ("MEMOIRE");
        break;
     case DIVISION_PAR_ZERO:
        return ("DIVISION_PAR_ZERO");
     case SYNTAXE:
        return ("SYNTAXE");
    case MEMOIRE_PARSEUR:
        return ("MEMOIRE_PARSEUR");
    case RUNTIME:
        return ("RUNTIME"); break;
    default:
        return "";
    }
}

void afficher_erreur(void){
   printf("%s", couleur_rouge); 
   printf("Erreur d’exécution [%s] : %s\n",afficher_type_erreur(TYPE_ERREUR), MESSAGE_ERREUR);
   printf("fonction fautive :  « %s »\n", FONCTION_ERREUR);
   printf("Valeur fautive  « ");
   afficher(SEXPR_ERREUR);
   printf(" »");
   printf("%s", couleur_defaut); 
}




/************************/
/*                      */
/*  Erreur du parseur   */
/*                      */
/************************/

void erreur_parseur(char *explication) {
    erreur(SYNTAXE,"parseur vaλisp", explication, NULL);

}