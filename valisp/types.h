#ifndef TYPES_H
#define TYPES_H
#include <stdint.h>
typedef int bool;
struct valisp_object;

typedef struct valisp_object* sexpr;

typedef sexpr (*primitive) (sexpr , sexpr );


void afficher(sexpr s_expression);


#endif