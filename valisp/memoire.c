#include "memoire.h"
#include <stdlib.h>

void* valisp_malloc(size_t size){
    void * ptr_res;
    ptr_res = allocateur_malloc(size);
    if (ptr_res == NULL ){
        ERREUR_FATALE("Allocation impossible");
        exit(1);
    }

    return ptr_res;
    
}