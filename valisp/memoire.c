#include "memoire.h"
#include <stdlib.h>
#include "erreurs.h"

void* valisp_malloc(size_t size){
    void * ptr_res;
    ptr_res = allocateur_malloc(size);
    if (ptr_res == NULL ){
        erreur(MEMOIRE, "valisp_malloc", "Pas assez de mémoire", NULL);
    }

    return ptr_res;
    
}