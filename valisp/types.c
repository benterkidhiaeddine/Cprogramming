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
        case chaine:
            printf("%s", s_expression->data.c);    
        case symbole:
            printf("%s", s_expression->data.c);    

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


/*
    Fonctions des chaines de charactères
*/

int longeur_chaine(const char* c){
    int i = 0;
    while(c[i] != 0){
        i++;
    }
    return i;
}


char *chaine_vers_memoire(const char *c){
    int l;
    char *res;
    int i;
    char *tmp;

    /*
        Calculer la longeur de la chaine pour conntaintre le nombre d'octets nécessaire 
    */
    l = longeur_chaine(c);
    res = valisp_malloc(sizeof(char) * l + 1 );


    /*
        Copier la chaine de la mémoire statique à notre mémoire dynamique 
        en utilisant l'arithmétique des pointeurs
    */
    i = 0;
    tmp = res;
    while (c[i] != 0){
        *(tmp + i) = c[i];
        i++;
    }
    *(tmp + i) = '\0';
    return res;

}


sexpr new_string(char *c){

    sexpr res = valisp_malloc(sizeof(struct valisp_object));
    char* new_c = chaine_vers_memoire(c); 
    res->type = chaine;
    res->data.c = new_c;
    return res;
}


bool string_p(sexpr val){
    if (val == NULL){
        return 0;
    }
    return (val->type == chaine);

}


char *get_string(sexpr val){
    return val->data.c;

}


/*
    Fonctions pour les symboles
*/

bool my_strcmp(char* a, char* b) {
    int i;
    int l1 = longeur_chaine(a);
    int l2 = longeur_chaine(b);

    if (l1 != l2){
        return 0;
    }
    for (i = 0; i <l1 ; i++){
        if (a[i] != b[i]){
            return 0;
        }

    }
    return 1;
    
}


sexpr new_symbol(char *c){

    sexpr res = valisp_malloc(sizeof(struct valisp_object));

    res->type = symbole;

    if (c == NULL){
        res->data.c = chaine_vers_memoire("nil");  ;
    }else{
        res->data.c = chaine_vers_memoire(c);
    }

    return res;
}



bool symbol_p(sexpr val){
    if (val == NULL){
        return 1;
    }

    return (val->type == symbole);

}


char *get_symbol(sexpr val){
    if (val == NULL){
        return "nil";
    }
    return val->data.c;
}


bool symbol_match_p(sexpr val, const char *chaine){
    return my_strcmp(val->data.c , chaine);
    
}