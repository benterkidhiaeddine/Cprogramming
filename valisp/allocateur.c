#include "allocateur.h"



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


int bloc_suivant(int indice){
    int suivant;
    bloc bloc_contient_suivant = MEMOIRE_DYNAMIQUE[indice];
   
    suivant = bloc_contient_suivant & ((1 << 15) - 1); 
    return suivant;
}


int bloc_precedant(int indice){

    int precedent;
    bloc bloc_contient_precedent = MEMOIRE_DYNAMIQUE[indice];

    precedent = bloc_contient_precedent >> 16;
    precedent = precedent & ((1 << 15) - 1);
    return precedent;

}


int usage_bloc(int indice){

    int usage;
    bloc bloc_contient_usage = MEMOIRE_DYNAMIQUE[indice];

    usage = bloc_contient_usage >> 15;
    usage = usage & 1;
    return usage;

}

int rm_bloc(int indice){

    int rm;
    bloc bloc_contient_rm = MEMOIRE_DYNAMIQUE[indice];

    rm = bloc_contient_rm >> 31;
    return rm;
}


int taille_bloc(int indice){
    int suivant = bloc_suivant(indice);
    /*
        Cas spécail pour la dernière case de métadonées 
    */
    if (indice == (TAILLE_MEMOIRE_DYNAMIQUE - 1)){
        return 0;
    }
    return suivant - indice - 1;
}