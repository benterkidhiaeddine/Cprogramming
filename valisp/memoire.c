#include "memoire.h"
#include <stdlib.h>
#include "erreurs.h"
#include "environnement.h"

void* valisp_malloc(size_t size){
    void * ptr_res;
    ptr_res = allocateur_malloc(size);
    if (ptr_res == NULL ){
        erreur(MEMOIRE, "valisp_malloc", "Pas assez de mémoire", NULL);
    }

    return ptr_res;
    
}



void ramasse_miette_parcourir_et_marquer(sexpr s){
    sexpr curr;
    int indice;

   if (s == NULL || rm_bloc(pointeur_vers_indice(s))){
    return;
   }

   curr = car(s);
   switch (curr->type)
   {
   case chaine:
   case symbole:
    indice = pointeur_vers_indice(curr->data.c);
    
    
    
    /* code */
    break;
   
   default:
    break;
   }
}
