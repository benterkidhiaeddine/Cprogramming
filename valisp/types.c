#include "types.h"
#include  "memoire.h"
#include <stdio.h>
#include "debug.h"

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
    switch (s_expression->type){
        case entier:
            printf("%d", s_expression->data.i);
            break;
            
    }
}



/*
    Fonctions des entiers

*/

sexpr new_integer(int32_t i){
    sexpr res =  (sexpr) valisp_malloc(sizeof(struct valisp_object)); 
    
    res->type = entier; 
    res->data.i = i;
     
    return res;
}



bool integer_p(sexpr val){
    if (val == NULL){
        return 0;
    }
    return (val->type == entier);
}


int32_t get_integer(sexpr val){
    return val->data.i;
}
