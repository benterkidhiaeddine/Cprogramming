#include "memoire.h"

void* valisp_malloc(size_t size){
    void * ptr_res;
    ptr_res = allocateur_malloc(size);
    if (ptr_res == NULL ){
        ERREUR_FATALAE("Allocation impossible");
        exit(1);
    }

    return ptr_res;
    
}