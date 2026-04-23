#ifndef ENVIRONEMENT_H
#define ENVIRONEMENT_H

#include "types.h"
#include "allocateur.h"
#include  "lib_memoire.h"


sexpr environnement_global(void);
void initialiser_memoire(void);
int longueur_env(sexpr env);
void valisp_stat_memoire(void);

#endif