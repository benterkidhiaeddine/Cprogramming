#include "types.h"
#include <stdio.h>

enum valisp_type {
    entier,
    chaine,
    symbole,
    couple,
    prim,
    spec
};


struct cons {
    sexpr car;
    sexpr cdr;
};


struct prim {
    char* nom;
    primitive f;

};


union valisp_data {
   int32_t i; 
   char* c;
   struct cons con; 
   struct prim pri;
};


struct valisp_object {
    enum valisp_type type;
    union valisp_data data;
};


void afficher(sexpr s_expression){
    if (s_expression == NULL){
        printf("nil\n");
    }
    else{
        printf("<???>");
    }
}


