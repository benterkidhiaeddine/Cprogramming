#ifndef TYPES_H
#define TYPES_H
#include <stdint.h>
typedef int bool;
struct valisp_object;

typedef struct valisp_object* sexpr;

typedef sexpr (*primitive) (sexpr , sexpr );


void afficher(sexpr s_expression);


/*
    Fonctions des entiers
*/

sexpr new_integer(int32_t i);
bool integer_p(sexpr val);
int32_t get_integer(sexpr val);


/*
    Fonctions des chaines
*/

char *chaine_vers_memoire(const char *c);
sexpr new_string(char *c);
bool string_p(sexpr val);
char *get_string(sexpr val);



#endif