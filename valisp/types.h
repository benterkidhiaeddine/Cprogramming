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


/*
    Fonctions des symboles
*/

sexpr new_symbol(char *c);
bool symbol_p(sexpr val);
char *get_symbol(sexpr val);
void afficher(sexpr val);
bool symbol_match_p(sexpr val, const char *chaine);


/*
    Fonctions des Listes

*/
sexpr cons(sexpr e1, sexpr e2);
bool cons_p (sexpr e);
sexpr car(sexpr e);
sexpr cdr(sexpr e);
void set_car(sexpr e, sexpr nouvelle);
void set_cdr(sexpr e, sexpr nouvelle);
void afficher_liste(sexpr e);


#endif