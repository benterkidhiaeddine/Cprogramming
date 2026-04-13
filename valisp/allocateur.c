#include <stdio.h>
#include <stdint.h>
#define  TAILLE_MEMOIRE_DYNAMIQUE 32768
typedef uint32_t bloc;


bloc MEMOIRE_DYNAMIQUE[TAILLE_MEMOIRE_DYNAMIQUE];


void initialiser_memoire_dynamique(){
    MEMOIRE_DYNAMIQUE[0] =  (1 << 15) - 1;
    MEMOIRE_DYNAMIQUE[TAILLE_MEMOIRE_DYNAMIQUE -  1] = (1 << 16) - 1; 
}

bloc cons_bloc(int rm, int precedant, int libre, int suivant){
    /*
        Ajouter la marqiue pour le rammasse miete 
    */
    bloc res = rm;
    
    /*
        Ajouter la valeur du précéent 
    */
    res = res << 15;
    res = res | precedant;

 
    /*
        Ajouter la valeur du libre 
    */
    res = res << 1;
    res = res | libre;


 
    /*
        Ajouter la valeur du suivant 
    */
    res = res << 15;
    res = res | suivant;


    return res;


}
