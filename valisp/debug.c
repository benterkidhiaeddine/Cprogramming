#include <stdio.h>
#include "debug.h"
#include "couleurs.h"


void debug(char  *description, char* fichier, int ligne){
    fprintf(stderr,"%s", couleur_bleu);
    fprintf(stderr,"   %s ligne %d\n\n", fichier, ligne);
    fprintf(stderr,"%s\n", description);
}


