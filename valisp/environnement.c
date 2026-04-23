#include "environnement.h" 
#include <stdio.h>
#include "debug.h"


sexpr ENV = NULL;



sexpr environnement_global(void){
    return ENV;
}


void initialiser_memoire(void){
    sexpr variable_t;
    sexpr t;
    initialiser_memoire_dynamique();


    /*
        Créer un nouveu t : t 
    */

    t = new_symbol("t");
    variable_t = cons(t , t);

    ENV = environnement_global();
    ENV =  cons(variable_t , NULL);
}


int longueur_env(sexpr env){
    int res = 0; 
    sexpr tmp;
    for (tmp = env; tmp != NULL; tmp = cdr(tmp)){

        res += 1;
    } 
    return res;
}


void valisp_stat_memoire(void){
    afficher_stat_memoire();
}


void afficher_env(sexpr env){

    sexpr ENV;
    sexpr tmp;
    sexpr curr;
    sexpr variable;
    sexpr valeur;

    ENV = environnement_global();


    for (tmp = ENV; tmp != NULL; tmp = cdr(tmp)){
        curr = car(tmp);
        variable = car(curr);
        valeur = cdr(curr);

       printf("%s", couleur_bleu); 
       afficher(variable);
       printf(" ");
       printf("%s", couleur_defaut); 
       afficher(valeur);
       printf("\n");
    }

}



int trouver_variable(sexpr env, sexpr variable, sexpr *resultat){

    sexpr tmp;
    sexpr curr;
    sexpr variable_c;
    sexpr valeur_c;
    for (tmp = env; tmp != NULL; tmp = cdr(tmp)){
        curr = car(tmp);
        variable_c = car(curr);
        valeur_c = cdr(curr);

        

        if (sexpr_equal(variable, variable_c)){
            *resultat = valeur_c;
            return 0;
        }
    }
    return -1;

}


int modifier_variable(sexpr env, sexpr variable, sexpr valeur){

    sexpr tmp;
    sexpr curr;
    sexpr variable_c;

    for (tmp = env; tmp != NULL; tmp = cdr(tmp)){
        curr = car(tmp);
        variable_c = car(curr);

        if (sexpr_equal(variable, variable_c)){
            set_cdr(curr , valeur);
            return 0;
        }
    }
    return -1;

}


void definir_variable_globale(sexpr variable, sexpr valeur){
    sexpr ENV;
    sexpr tmp;


    ENV = environnement_global();
    if (modifier_variable(ENV, variable , valeur) != 0){

        for (tmp = ENV;  tmp != NULL && cdr(tmp) != NULL; tmp = cdr(tmp)){
            /*On parcours l'environnement jusqu'à la fin*/
        }

        set_cdr(tmp, 
            cons(
                cons(variable, valeur)
                ,NULL)
            );

    }

}

/*

    Logique pour charger les primitives

*/

void charger_une_primitive(char *nom_valisp, char *nom_c, primitive p){
    definir_variable_globale( new_symbol(nom_valisp), new_primitive(nom_c, p));
}

void charger_une_speciale(char *nom_valisp, char *nom_c, primitive p){
    definir_variable_globale( new_symbol(nom_valisp), new_speciale(nom_c, p));
}

void charger_primitives(){
    CHARGER_UNE_PRIMITIVE("+",add_valisp);
}