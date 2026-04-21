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
        printf("nil");
    }
    else{
        switch (s_expression->type){
            case entier:
                printf("%d", s_expression->data.i);
                break;
            case chaine:
                printf("%s", s_expression->data.c);    
            case symbole:
                printf("%s", s_expression->data.c);    
            case couple:
                printf("(");
                afficher_liste(s_expression);
                printf(")");
        }

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

    if (my_strcmp(c, "nil")){
        return NULL;
    }else{
        sexpr res = valisp_malloc(sizeof(struct valisp_object));
        res->type = symbole;
        res->data.c = chaine_vers_memoire(c);
        return res;
    }

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
    if (val == NULL ){
        return (my_strcmp(chaine, "nil"));
    }
    return my_strcmp(val->data.c , chaine);
    
}


/*
    Fonctions des Listes

*/

sexpr cons(sexpr e1, sexpr e2){
    sexpr res;
    struct cons new_cons;
    

    res = valisp_malloc(sizeof(struct valisp_object));
    res->type = couple;

    new_cons.car = e1;
    new_cons.cdr = e2;

    res->data.con = new_cons;

    return res;

}


bool cons_p (sexpr e){
    if (e == NULL){
        return 0;
    }
    return (e->type == couple);
}


sexpr car(sexpr e){
    if (e == NULL) {
        ERREUR_FATALE("L'expression = NULL");
    }
    return e->data.con.car;
}


sexpr cdr(sexpr e){
    if (e == NULL) {
        ERREUR_FATALE("l'expression = NULL");
    }
    return e->data.con.cdr;
}


void set_car(sexpr e, sexpr nouvelle){
    if( e == NULL){
        ERREUR_FATALE("l'expression = NULL");
    }
    e->data.con.car = nouvelle;

}
void set_cdr(sexpr e, sexpr nouvelle){
    if (e == NULL){
        ERREUR_FATALE("l'expression = NULL");
    }
    e->data.con.cdr = nouvelle;
}

void afficher_liste(sexpr e){
    sexpr x;
    sexpr y;
    if  (e == NULL){
        return;
    }
    x = e->data.con.car;
    y = e->data.con.cdr;

    /*
        on affiche x
        • puis on regarde y
         si y est NULL : on quitte la fonction
         si y est un cons : on affiche " " et on appelle affiche_liste(y)
         sinon on affiche " . " puis y.
     */

    afficher(x);
    if (y == NULL){
        return;
    }
    else if (y->type == couple){
        printf(" ");
        afficher_liste(y);
    }
    else {
        printf(" . ");
        afficher(y);
    }

}
