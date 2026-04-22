#ifndef PRIMITIVES_H
#define PRIMITIVES_H
#include "types.h"
    

void test_nb_parametres(sexpr liste, char* fonction, int taille);
sexpr add_valisp(sexpr liste, sexpr env);
sexpr mul_valisp(sexpr liste, sexpr env);
sexpr sub_valisp(sexpr liste, sexpr env);
sexpr div_valisp(sexpr liste, sexpr env);
sexpr mod_valisp(sexpr liste, sexpr env);
sexpr less_than_valisp(sexpr liste, sexpr env);
sexpr car_valisp(sexpr liste, sexpr env);
sexpr cdr_valisp(sexpr liste, sexpr env);
sexpr cons_valisp(sexpr liste, sexpr env);
sexpr equal_valisp(sexpr liste, sexpr env);

#endif