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
int longeur_liste(sexpr liste);
bool sexpr_equal(sexpr e1 , sexpr e2);


/*

    Dans cet exercice, il n’y aura aucune différence entre primitive et forme spéciale, si ce n’est évidement le type. La
différence se verra lorsque l’on écrira l’interpréteur (TP 4).
1. sexpr new_primitive(char *nom, primitive p) et sexpr new_speciale(char *nom, primitive p)
2. bool prim_p(sexpr val) et bool spec_p(sexpr val)
3. char* get_name(sexpr p) et primitive get_prim(sexpr p)
4. sexpr run_prim(sexpr p, sexpr liste, sexpr env) qui exécute la primitive p avec comme paramètres
liste et env.
5. void afficher(sexpr V). On affichera une primitive sous la forme #p<nom> où nom est le nom de la primitive
en question. Pour une forme spéciale, on remplacera le p par un s ce qui donnera #s<nom>.

*/

sexpr new_primitive(char *nom, primitive p);
sexpr new_speciale(char *nom, primitive p);

bool prim_p(sexpr val);
bool spec_p(sexpr val);

char* get_name(sexpr p);
primitive get_prim(sexpr p);

sexpr run_prim(sexpr p, sexpr liste, sexpr env);

#endif