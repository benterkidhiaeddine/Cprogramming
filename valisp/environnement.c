#include "environnement.h" 
#include <stdio.h>


sexpr ENV = NULL;



sexpr environnement_global(void){
    return ENV;
}


void initialiser_memoire(void){
    sexpr variable_t;
    initialiser_memoire_dynamique();


    /*
        Créer un nouveu t : t 
    */

    sexpr t = new_symbol("t");
    variable_t = cons(t , t);

    ENV = environnement_global();
    ENV =  cons(variable_t , NULL);
}
