#ifndef ENVIRONEMENT_H
#define ENVIRONEMENT_H

#include "types.h"
#include "allocateur.h"
#include  "lib_memoire.h"
#include "couleurs.h"
#include "primitives.h"
#define CHARGER_UNE_PRIMITIVE(NOM,FONCTION) charger_une_primitive(NOM, #FONCTION, FONCTION );

sexpr environnement_global(void);
void initialiser_memoire(void);
int longueur_env(sexpr env);
void valisp_stat_memoire(void);
void afficher_env(sexpr env);
int trouver_variable(sexpr env, sexpr variable, sexpr *resultat);
int modifier_variable(sexpr env, sexpr variable, sexpr valeur);
void definir_variable_globale(sexpr variable, sexpr valeur);
void charger_une_primitive(char *nom_valisp, char *nom_c, primitive p);
void charger_une_speciale(char *nom_valisp, char *nom_c, primitive p);
void charger_primitives();

#endif