#include "primitives.h"
#include <stdio.h>
#include "erreurs.h"



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


sexpr car_valisp(sexpr liste, sexpr env){

    sexpr a;
    a = car(liste);
    if (a == NULL){
        return NULL;
    }
    return car(a);

}




sexpr cdr_valisp(sexpr liste, sexpr env){

    sexpr a;
    a = car(liste);
    if (a == NULL){
        return NULL;
    }
    return cdr(a);

}


sexpr cons_valisp(sexpr liste, sexpr env){
    sexpr a;
    sexpr b;
    test_nb_parametres(liste, "cons", 2);


    a = car(liste);
    b = car(cdr(liste));
    return cons(a, b);


}


sexpr equal_valisp(sexpr liste, sexpr env){

    sexpr a;
    sexpr b;


    test_nb_parametres(liste, "=", 2);

    a = car(liste);
    b = car(cdr(liste));

    if (sexpr_equal(a ,b)){
        return new_symbol("t");
    }
    else {
        return new_symbol("nil");
    }

}


sexpr print_valisp(sexpr liste, sexpr env){

    sexpr tmp;
    sexpr last;
    if (liste == NULL){
        return new_string("");
    }
    for (tmp = liste; tmp != NULL; tmp =cdr(tmp)){
        afficher(car(tmp));
        last = car(tmp);
    }

    return last;


}

sexpr type_of_valisp(sexpr liste, sexpr env) {
    sexpr a;
    test_nb_parametres(liste, "typeof", 1);

    a = car(liste);

    if (a == NULL) {
        return new_symbol("nil"); 
    }

    switch (a->type) {
        case entier:
            return new_symbol("int");

        case couple:
            return new_symbol("cons");

        case symbole:
            return new_symbol("symbol");

        case chaine:
            return new_symbol("string");

        case prim:
            return new_symbol("primitive");

        case spec:
            return new_symbol("special");
        default:
            return new_symbol("uknown");

    }
}