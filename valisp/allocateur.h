#ifndef ALLOCATEUR_H
#define ALLOCATEUR_H
#include <stdint.h>

#define TAILLE_MEMOIRE_DYNAMIQUE 32768
/*
    Maitre les headers des types ici

*/
typedef uint32_t bloc;

/*
    Maitre les headers des fonctions ici
*/

void initialiser_memoire_dynamique();
bloc cons_bloc(int rm, int precedant, int libre, int suivant);
int bloc_suivant(int indice);
int bloc_precedant(int indice);
int usage_bloc(int indice);
int rm_bloc(int indice);

int rechercher_bloc_libre(int nombre_blocs);
int allocateur_balloc(int nombre_blocs);

#endif