#include "allocateur.h"
#include <stdio.h>



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
    int bloc_contient_suivant = MEMOIRE_DYNAMIQUE[indice];
   
    suivant = bloc_contient_suivant & ((1 << 15) - 1); 
    return suivant;
}


int bloc_precedant(int indice){

    int precedent;
    int bloc_contient_precedent = MEMOIRE_DYNAMIQUE[indice];

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

int rechercher_bloc_libre(int nombre_blocs){
    int i ;
    for(i = 0 ; i < TAILLE_MEMOIRE_DYNAMIQUE - 1  ; i = bloc_suivant(i)){
        if (nombre_blocs <= taille_bloc(i) && (usage_bloc(i) == 0)) {
            return i;
        }
    }

    return -1;
}

int allocateur_balloc(int nombre_blocs){
    bloc nouvea_b;
    bloc nouveau_suivant;
    int indice_suivant_b;
    int indice_nouveau_bloc;

    int indice_b = rechercher_bloc_libre(nombre_blocs);

    if (indice_b == - 1){
        return -1;
    }

    /*
        Si la taille est exacte pour le bloc trouvé on le marque seulement comme occupé et retourne l'indice  du premier bloc 
    
    */
    if (taille_bloc(indice_b) == nombre_blocs){
        MEMOIRE_DYNAMIQUE[indice_b] = cons_bloc(rm_bloc(indice_b), bloc_precedant(indice_b), 1, bloc_suivant(indice_b));
    }

    else {
        indice_suivant_b = bloc_suivant(indice_b);

        /*
            Créer le nouveau bloc libre suivant 
        */

        nouvea_b = cons_bloc(0, indice_b , 0, indice_suivant_b);
        indice_nouveau_bloc = indice_b + nombre_blocs + 1;
        MEMOIRE_DYNAMIQUE[indice_nouveau_bloc] = nouvea_b;

        /*
           maitre le nouveau bloc crée comme prédecent de suivant de notre block alloué 
        */
        nouveau_suivant = cons_bloc(rm_bloc(indice_suivant_b) , indice_nouveau_bloc, usage_bloc(indice_suivant_b), bloc_suivant(indice_suivant_b) );
        MEMOIRE_DYNAMIQUE[indice_suivant_b] = nouveau_suivant; 
        
        
        MEMOIRE_DYNAMIQUE[indice_b] = cons_bloc(rm_bloc(indice_b), bloc_precedant(indice_b), 1, indice_nouveau_bloc);

    }

    return indice_b;
}



int octets_vers_blocs(size_t size){
    int remainder = 0;
    remainder = size % sizeof(bloc);

    if (remainder == 0){
        return size / sizeof(bloc); 
    }

    else {
        return (size / sizeof(bloc)) + 1;
    
    }
}



void *allocateur_malloc(size_t size){
    int indice_b = 0 ;
    int bloc_number = octets_vers_blocs(size);

    indice_b = allocateur_balloc(bloc_number); 

    if (indice_b == -1){
        return NULL;
    }

    else {
        return MEMOIRE_DYNAMIQUE + indice_b + 1;
    }
}



void allocateur_bree(int i){

    int prev_i = bloc_precedant(i);
    int suivant_i = bloc_suivant(i);
    int suivant_suivant_i = bloc_suivant(suivant_i);
        
    if (i == (TAILLE_MEMOIRE_DYNAMIQUE - 1)) {
        return;
    }
    /*
        Bloc adjancents sont pas libres 
    */
    if (usage_bloc(prev_i) && usage_bloc(suivant_i)){
        /*  On change seuelemnt le bit d'usage */
        MEMOIRE_DYNAMIQUE[i] = cons_bloc(rm_bloc(i),bloc_precedant(i), 0 , bloc_suivant(i));
        return;
    }

    /*
        Bloc précédent libre, bloc suivant ouccupé 
    */

    else if (!usage_bloc(prev_i) && usage_bloc(suivant_i)){

        MEMOIRE_DYNAMIQUE[prev_i] = cons_bloc(rm_bloc(prev_i), bloc_precedant(prev_i), 0, suivant_i);
        MEMOIRE_DYNAMIQUE[suivant_i] = cons_bloc(rm_bloc(suivant_i), prev_i, usage_bloc(suivant_i), suivant_suivant_i);
        return;
    }


    /*
        Bloc précedent  occupé, bloc suivant libre  
    */
    else if (usage_bloc(prev_i) && !usage_bloc(suivant_i)){
        MEMOIRE_DYNAMIQUE[i] = cons_bloc(rm_bloc(i),bloc_precedant(i), 0 , bloc_suivant(suivant_i));
        MEMOIRE_DYNAMIQUE[suivant_suivant_i] = cons_bloc(rm_bloc(suivant_suivant_i), i, usage_bloc(suivant_suivant_i), bloc_suivant(suivant_suivant_i));
        return;
    }    
    /*
        Bloc adjacents sont libres 
    */
   else{ 
       MEMOIRE_DYNAMIQUE[prev_i] = cons_bloc(rm_bloc(prev_i), bloc_precedant(prev_i), 0 , suivant_suivant_i);
       MEMOIRE_DYNAMIQUE[suivant_suivant_i] = cons_bloc(rm_bloc(suivant_suivant_i), prev_i, usage_bloc(suivant_suivant_i) , bloc_suivant(suivant_suivant_i));
       return;
   }

}


void allocateur_free (void *ptr){
    int pointer_i = (bloc*) ptr - MEMOIRE_DYNAMIQUE -1; 
    allocateur_bree(pointer_i);
}

int pointeur_vers_indice(void *ptr){

    if (ptr < MEMOIRE_DYNAMIQUE || ptr >= (MEMOIRE_DYNAMIQUE + TAILLE_MEMOIRE_DYNAMIQUE )){
        ERREUR_FATALE("Acces au dela du memoir dynamique");

    }

    return ((bloc*) ptr - MEMOIRE_DYNAMIQUE - 1);
}


int ramasse_miettes_lire_marque(void *ptr){
    int indice = pointeur_vers_indice(ptr);
    return  rm_bloc(indice) ;
}

int ramasse_miettes_poser_marque(void *ptr){
    int indice = pointeur_vers_indice(ptr);
    if( rm_bloc(indice)){
        ERREUR_FATALE("deja marqué");
    }

    MEMOIRE_DYNAMIQUE[indice] = cons_bloc(1 , bloc_precedant(indice), usage_bloc, bloc_suivant(indice));
    return 1;

} 


int bloc_libre(int i){
    if (i == TAILLE_MEMOIRE_DYNAMIQUE - 1){
        return 0;
    }

    return !rm_bloc(i);
}

void ramasse_miettes_liberer(void){ 

    int i;

    for(i = 0; i != TAILLE_MEMOIRE_DYNAMIQUE - 1 ; i = bloc_suivant(i)){

        if  (bloc_libre(i)){
            allocateur_bree(i);
        }
        MEMOIRE_DYNAMIQUE[i] = cons_bloc(0, bloc_precedant(i), usage_bloc(i), bloc_suivant(i));

    }
}