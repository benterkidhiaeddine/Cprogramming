#include "primitives.h"
#include <stdio.h>
#include "erreurs.h"

int longeur_liste(sexpr liste){
    if (liste == NULL){
        return 0;
    }
    return (1+ longeur_liste(cdr(liste)));
}


void test_nb_parametres(sexpr liste, char* fonction, int taille) {

    if (longeur_liste(liste) != taille){
        erreur(ARITE, fonction, "nombre de paramètres", liste);
    }
}

sexpr add_valisp(sexpr liste, sexpr env){
    sexpr a;
    sexpr b;
    test_nb_parametres(liste, "+" ,2);
    
    a = car(liste);
    b = car(cdr(liste));

    if (!integer_p(a)) erreur(TYPAGE, "+" ,"nécessite un entier", a);
    if (!integer_p(b)) erreur(TYPAGE, "+" ,"nécessite un entier", b);

    return new_integer(get_integer(a) + get_integer(b));

}


sexpr mul_valisp(sexpr liste, sexpr env){
    sexpr a;
    sexpr b;
    test_nb_parametres(liste, "*" ,2);
    
    a = car(liste);
    b = car(cdr(liste));

    if (!integer_p(a)) erreur(TYPAGE, "*" ,"nécessite un entier", a);
    if (!integer_p(b)) erreur(TYPAGE, "*" ,"nécessite un entier", b);

    return new_integer(get_integer(a) * get_integer(b));


}


sexpr sub_valisp(sexpr liste, sexpr env){
    sexpr a;
    sexpr b;
    

    /*
        Cas pas de paramètres 
    */

    if (liste == NULL){
        erreur(ARITE, "-", "nombre de paramètres 1 ou 2", liste);
    }
    /*
        Cas un seul paramètre : c'est la négation
    */
    if (longeur_liste(liste) == 1){
        a = car(liste);
        if (!integer_p(a)) erreur(TYPAGE, "-" ,"nécessite un entier", a);
        return new_integer(- get_integer(a));
    }
    /*
        Cas deux parmètres c'est la soustraction 
    */ 
    test_nb_parametres(liste, "-" ,2);
    
    a = car(liste);
    b = car(cdr(liste));

    if (!integer_p(a)) erreur(TYPAGE, "-" ,"nécessite un entier", a);
    if (!integer_p(b)) erreur(TYPAGE, "-" ,"nécessite un entier", b);

    return new_integer(get_integer(a) - get_integer(b));


}


sexpr div_valisp(sexpr liste, sexpr env){
    sexpr a;
    sexpr b;
    test_nb_parametres(liste, "/" ,2);
    
    a = car(liste);
    b = car(cdr(liste));

    if (!integer_p(a)) erreur(TYPAGE, "/" ,"nécessite un entier", a);
    if (!integer_p(b)) erreur(TYPAGE, "/" ,"nécessite un entier", b);


    if (get_integer(b) == 0){
        erreur(DIVISION_PAR_ZERO, "/", "ca fait l'infini !!!", liste);
    }

    return new_integer(get_integer(a) / get_integer(b));


}


sexpr mod_valisp(sexpr liste, sexpr env){
    sexpr a;
    sexpr b;
    test_nb_parametres(liste, "%" ,2);
    
    a = car(liste);
    b = car(cdr(liste));

    if (!integer_p(a)) erreur(TYPAGE, "%" ,"nécessite un entier", a);
    if (!integer_p(b)) erreur(TYPAGE, "%" ,"nécessite un entier", b);


    if (get_integer(b) == 0){
        erreur(DIVISION_PAR_ZERO, "%", "ca fait l'infini !!!", liste);
    }

    return new_integer(get_integer(a) % get_integer(b));


}


sexpr less_valisp(sexpr liste, sexpr env){


    sexpr a;
    sexpr b;
    test_nb_parametres(liste, "<" ,2);
    
    a = car(liste);
    b = car(cdr(liste));

    if (!integer_p(a)) erreur(TYPAGE, "<" ,"nécessite un entier", a);
    
    
    if (!integer_p(b)) erreur(TYPAGE, "<" ,"nécessite un entier", b);

    if (get_integer(a) < get_integer(b)){
        return new_symbol("t");
    }
    else {
        return new_symbol("nil");
    }

}
