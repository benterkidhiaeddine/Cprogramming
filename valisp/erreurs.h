#include <setjmp.h>
#include  "types.h"
#ifndef VALISP_ERREUR_H
#define VALISP_ERREUR_H

void erreur_fatale(char  *fichier, int ligne, char* causes);
#define ERREUR_FATALE(CAUSE) erreur_fatale(__FILE__, __LINE__ , #CAUSE )

void erreur_parseur(char *explication);

jmp_buf *jump_buffer(void);




enum erreurs {
    TYPAGE, /* Paramètre du mauvais type */
    ARITE, /* Mauvais nombres de paramètres */
    NOM, /* Variables non définie */
    MEMOIRE, /* Plus de mémoire */
    DIVISION_PAR_ZERO, /* Tentative d’invocation de l’infini */
    SYNTAXE, /* Parseur : le code écrit n’est pas du Lisp */
    MEMOIRE_PARSEUR, /* Parseur : la sexpr est trop grosse */
    RUNTIME /* Vos propres erreurs lancée depuis valisp */
};

void afficher_erreur(void);
void erreur(enum erreurs type, char *fonction, char *explication, sexpr s);
#endif