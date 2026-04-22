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
