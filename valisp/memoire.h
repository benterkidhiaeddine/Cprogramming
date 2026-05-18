#ifndef MEMOIRE_H
#define MEMOIRE_H
#include "allocateur.h"

void* valisp_malloc(size_t size);
void ramasse_miette_parcourir_et_marquer(sexpr s);

#endif