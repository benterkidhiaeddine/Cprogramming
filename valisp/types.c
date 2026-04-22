#include "types.h"
#include  "memoire.h"
#include <stdio.h>
#include "debug.h"
#include <string.h>



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
                break;
            case symbole:
                printf("%s", s_expression->data.c);    
                break;
            case couple:
                printf("(");
                afficher_liste(s_expression);
                printf(")");
                break;
            case prim:
                printf("#p<%s>", s_expression->data.pri.nom);
                break;
            case spec:
                printf("#s<%s>", s_expression->data.pri.nom);
                break;
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



sexpr new_symbol(char *c){

    if (strcmp(c, "nil") == 0){
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
        return (strcmp(chaine, "nil") == 0);
    }
    return (strcmp(val->data.c , chaine) == 0);
    
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


int longeur_liste(sexpr liste){
    if (liste == NULL){
        return 0;
    }
    return (1+ longeur_liste(cdr(liste)));
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


/*
    Primitives et formes spéciales
*/


sexpr new_primitive(char *nom, primitive p){
   sexpr res = valisp_malloc(sizeof(struct valisp_object));     
   char* s_nom = chaine_vers_memoire(nom);

   res->type = prim;
   res->data.pri.f = p; 
   res->data.pri.nom = s_nom; 

   return res;
}



sexpr new_speciale(char *nom, primitive p){
   sexpr res = valisp_malloc(sizeof(struct valisp_object));     
   char* p_nom = chaine_vers_memoire(nom);

   res->type = spec;
   res->data.pri.f = p; 
   res->data.pri.nom = p_nom; 

   return res;

}


bool prim_p(sexpr val){
    if (val == NULL){
        return 0;
    }

    return (val->type == prim);
}

bool spec_p(sexpr val){
    if (val == NULL){
        return 0;
    }

    return (val->type == spec);
}


char* get_name(sexpr p){
    if (p == NULL){
        ERREUR_FATALE("Essayer d'accéder une primitive NULL");
    }
    return p->data.pri.nom;
}

primitive get_prim(sexpr p){
    if (p == NULL){
        ERREUR_FATALE("Essayer d'accéder une primitive NULL");
    }
    return p->data.pri.f;
}


sexpr run_prim(sexpr p, sexpr liste, sexpr env){
    if (p == NULL){
        ERREUR_FATALE("Essayer de executer NULL comme primitive");
    }
    return p->data.pri.f(liste, env);

}

bool sexpr_equal(sexpr e1, sexpr e2){

    if (e1 == NULL && e2 == NULL) return 1;

    if (e1 == NULL || e2 == NULL) return 0;
    

    if (e1->type != e2->type) return 0;

    switch (e1->type){
        case entier:
            return e1->data.i == e2->data.i;

        case chaine:
        case symbole:
            return strcmp(e1->data.c, e2->data.c) == 0;


        case prim:
        case spec:
            return (strcmp(e1->data.pri.nom,e2->data.pri.nom) == 0 && e1->data.pri.f == e2->data.pri.f);

        case couple:
            return (sexpr_equal(car(e1), car(e2)) && sexpr_equal(cdr(e1), cdr(e2)));

    }


    return 0;
}


