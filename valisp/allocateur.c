#include <stdio.h>
#include <stdint.h>
#define  TAILLE_MEMOIRE_DYNAMIQUE 32768
typedef uint32_t block;


block MEMOIRE_DYNAMIQUE[TAILLE_MEMOIRE_DYNAMIQUE];


void initialiser_memoire_dynamique(){
    MEMOIRE_DYNAMIQUE[0] =  (1 << 15) - 1;
    MEMOIRE_DYNAMIQUE[TAILLE_MEMOIRE_DYNAMIQUE -  1] = (1 << 16) - 1; 
}