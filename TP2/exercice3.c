#include <stdio.h>

typedef enum { entier ,decimal} typage;

typedef union {
    int ent;
    float dec;
} valeur;


typedef struct {
    typage type;
    valeur value;
} nombre;

/*
— nombre nombre_entier(int i)
— nombre nombre_decimal(float f)
— int est_entier(nombre n) 
— int est_decimal(nombre n)  Renvoie un booléen 
— void afficher_nombre(nombre n)  2 chiffres après la virgule si décimal 
*/

nombre nombre_entier(int i){
    nombre num;
    num.type = entier;
    num.value.ent = i;
    return num;
}


nombre nombre_decimal(float f){
    nombre num;
    num.type = decimal;
    num.value.dec = f;
    return num;
}


int est_entier(nombre n) {
    switch(n.type){
        case decimal:
            return 0;
        case entier:
            return 1; 

        default:
            return 0;
    }
}


int est_decimal(nombre n) {
    switch(n.type){
        case decimal:
            return 1;
        case entier:
            return 0; 
        default:
            return 0;
    }
}


void _afficher_nombre(nombre n){
    if (est_decimal(n)){
        printf("[type : deicmal , valeur : %.2f]", n.value.dec);
    }
    else {
        printf("[type: entier , valeur : %d]", n.value.ent);
    }

}
void afficher_nombre(nombre n){
    _afficher_nombre(n);
    printf("\n");
} 


/*
    Écrire une fonction nombre somme(nombre a, nombre b) calculant la somme de deux nombres. On part du
    principe que la somme de deux entiers est un entier, la somme de deux décimaux est un décimal et que la somme
    d’un entier avec un décimal est un décimal.
*/

nombre somme(nombre a, nombre b){
    nombre res;
    
    if (a.type == entier && b.type == entier ){
        res.type = entier;
        res.value.ent = a.value.ent + b.value.ent;
    }
    else {
        res.type = decimal;
        if (a.type == decimal && b.type == entier){
            res.value.dec = a.value.dec + b.value.ent;
        }
        else if (a.type == entier && b.type == decimal){
            res.value.dec = a.value.ent + b.value.dec;
        }
        else {
            res.value.dec = a.value.dec + b.value.dec;
        }
    }

    return res;
}

/*

    Écrire une fonction nombre division(nombre a, nombre b) calculant le quotient de deux nombres. Si les
    deux nombres sont de typage entier et que a est un multiple de b, alors le résultat sera de typage entier ; dans tous
    les autres cas, le résultat sera décimal.

*/

nombre division(nombre a, nombre b){
    nombre res;
    
    if (a.type == entier && b.type == entier ){
        if (a.value.ent % b.value.ent == 0){
            res.type = entier;
            res.value.ent = a.value.ent / b.value.ent;
        }
        else {
            res.type = decimal;
            res.value.dec = (float) a.value.ent / b.value.ent;
        }
    }
    else {
        res.type = decimal;
        if (a.type == decimal && b.type == entier){
            res.value.dec = a.value.dec / b.value.ent;
        }
        else if (a.type == entier && b.type == decimal){
            res.value.dec = a.value.ent / b.value.dec;
        }
        else {
            res.value.dec = a.value.dec / b.value.dec;
        }
    }

    return res;
}

/*
    Écrire une fonction nombre moyenne(nombre notes[], int taille) calculant la moyenne du tableau. On
    s’assurera que les trois notes « 10, 5 et 15 » renvoie bien une moyenne de typage entier et que les cinq notes « 10,
    5, 15, 12, 9 » renvoie un moyenne décimale.
*/

nombre moyenne(nombre notes[], int taille){

    nombre total;
    nombre res;
    nombre compte_de_notes;

    int i;

    compte_de_notes.type = entier;
    compte_de_notes.value.ent = taille;

    total.type = entier;
    total.value.ent = 0;
    

    for (i = 0; i < taille ; i++){
        total = somme(notes[i], total);
    }


    res = division(total, compte_de_notes);
    return res;
}




void test_typage_enum(typage t){
    switch(t){
        case entier:
            printf("Ce type est un entier\n");
            break;
        case decimal:
            printf("Ce type est un decimal\n");
            break;
    }

}
void question1(){

    typage t1 = entier;
    typage t2 = decimal;

    test_typage_enum(t1);
    test_typage_enum(t2);

}

void test_valeur_union(valeur v){
    int a = 10;
    float b = 5.2;
    v.ent = 22;
    printf("Tester l'addition entre entiers: %d + %d = %d\n",a, v.ent, a + v.ent );


    printf("Changer la valeur en decimal\n");
    v.dec = 4.5;
    printf("Tester l'addition entre flottants %.2f + %.2f = %.2f\n",b, v.dec, b + v.dec );

}


void question2(){

    valeur v;
    test_valeur_union(v);
}


void test_nombre_struct(nombre num){

    int integ_num = 10;
    float float_num = 5.5;

    switch(num.type){
        case entier:
            printf("Tester l'addition entre entiers: %d + %d = %d\n",integ_num, num.value.ent, integ_num + num.value.ent );

            break;
        case decimal:
            printf("Tester l'addition entre flottants: %.2f + %.2f = %.2f\n",float_num, num.value.dec, float_num + num.value.dec );
            break;


    }

}

void question3(){
    
    nombre dec_num;
    nombre integ_num;
    dec_num.type = decimal;
    dec_num.value.dec = 10.5;
    integ_num.type = entier;
    integ_num.value.ent = 5;

    test_nombre_struct(dec_num);
    test_nombre_struct(integ_num);
}

nombre test_creation_nombre_entier(int i){
    nombre n1_entier = nombre_entier(i);
    printf("nombre avec type entier et valeur : %d a été crée\n",n1_entier.value.ent);
    return n1_entier;
}


nombre test_creation_nombre_floattant(int f){
    nombre n1_decimal = nombre_decimal(f);
    printf("nombre avec type decimal et valeur : %.2f a été crée\n",n1_decimal.value.dec);
    return n1_decimal;
}

void test_type_est_entier(nombre n){
    if (est_entier(n)){
        printf("Le nombre est de type entier \n");
    }
    else {

        printf("Le nombre n'est pas de type entier \n");
    }

}

void test_type_est_decimal(nombre n){
    if (est_decimal(n)){
        printf("Le nombre est de type decimal \n");
    }
    else {
        printf("Le nombre n'est pas de type decimal \n");
    }

}


void question4(){

    nombre n1;
    nombre n2;
    
    nombre n3;
    nombre n4;

    int i1 = 45;
    int i2 = 50;

    float f1 = 5.5;
    float f2 = 0;


    n1 = test_creation_nombre_entier(i1);
    printf("\n");
    n2 = test_creation_nombre_entier(i2);
    printf("\n");
    n3 = test_creation_nombre_floattant(f1);
    printf("\n");
    n4 = test_creation_nombre_floattant(f2);
    printf("\n");

    printf("Tester qu'un nombre entier n'est pas de type decimal\n");
    afficher_nombre(n1);
    test_type_est_decimal(n1);
    printf("\n");

    printf("Tester qu'un nombre entier est de type correcte\n");
    afficher_nombre(n2);
    test_type_est_entier(n2);
    printf("\n");

    printf("Tester qu'un nombre decimal n'est pas de type entier\n");
    afficher_nombre(n3);
    test_type_est_decimal(n3);
    printf("\n");

    printf("Tester qu'un nombre decimal est de type correcte\n");
    afficher_nombre(n4);
    test_type_est_entier(n4);
    printf("\n");


}


void test_addition_nombres(nombre n1, nombre n2){
    printf("L'addition de : ");
    _afficher_nombre(n1);
    printf(" et ");
    _afficher_nombre(n2);
    printf(" = ");
    _afficher_nombre(somme(n1,n2));
    printf("\n");

}


void test_division_nombres(nombre n1, nombre n2){
    printf("La devision de : ");
    _afficher_nombre(n1);
    printf(" par ");
    _afficher_nombre(n2);
    printf(" = ");
    _afficher_nombre(division(n1,n2));
    printf("\n");

}


void affiche_tableau_nombres(nombre nombres[], int taille){
    int i;
    printf("[");
    for (i = 0; i < taille; i++ ){
        if (i == 0){
            if (est_decimal(nombres[i])) { 
                printf(" %.2f ", nombres[i].value.dec);
            }
            else {
                printf(" %d ", nombres[i].value.ent);
            }
        }

        else {
            if(est_decimal(nombres[i])){ 
                printf(", %.2f ", nombres[i].value.dec);
            }
            else {
                printf(", %d ", nombres[i].value.ent);
            }
        }
    }
    printf("]\n est ");

}
    
void test_moyenne_nombre(nombre notes[], int taille){
    printf("La moyenne pour les notes:");
    affiche_tableau_nombres(notes, taille);
    afficher_nombre(moyenne(notes, taille));

}




void question5(){

    /* Nombres pour tester addition et division */
    nombre n1;
    nombre n2;
    
    nombre n3;
    nombre n4;
    nombre n5;


    int i1 = 45;
    int i2 = 100;
    int i3 = 5;

    float f1 = 5.5;
    float f2 = 2;

    /* Nombres pour test le calcul de la moyenne*/
    nombre n6 ;
    nombre n7 ;
    nombre n8 ;
    nombre n9;
    nombre n10 ;


    nombre notes1[3] ;
    nombre notes2[5] ;
    
    
    n6 = nombre_entier(10);
    n7 = nombre_entier(5);
    n8 = nombre_entier(15);
    n9 = nombre_entier(12);
    n10 = nombre_entier(9);
    
    notes1[0] = n6;
    notes1[1] = n7,
    notes1[2] = n8;
    
    notes2[0] = n6;
    notes2[1] = n7;
    notes2[2] = n8;
    notes2[3] = n9;
    notes2[4] = n10;

    n1 = test_creation_nombre_entier(i1);
    printf("\n");
    n2 = test_creation_nombre_entier(i2);
    printf("\n");
    n3 = test_creation_nombre_floattant(f1);
    printf("\n");
    n4 = test_creation_nombre_floattant(f2);
    printf("\n");
    n5 = test_creation_nombre_entier(i3);
    printf("\n");

    printf("Tests : Partie 1 : Addition: ====== \n");
    printf("Tester l'addition d'un entier avec un entier\n");
    test_addition_nombres(n1, n2);

    printf("============\n");

    printf("Tester l'addition d'un entier avec un decimal\n");
    test_addition_nombres(n1, n3);


    printf("Tester l'addition d'un decimal avec un entier\n");
    test_addition_nombres(n4, n2);


    printf("Tester l'addition d'un decimal avec un decimal\n");
    test_addition_nombres(n3, n4);

    printf("Tests : Partie 2 : Division: ====== \n");
    printf("Tester la divison d'un entier par un autre entier qui est son diviseur \n");
    test_division_nombres(n1, n5);

    printf("============\n");
    
    printf("Tester la divison d'un entier par un autre entier qui n'est pas son diviseur \n");
    test_division_nombres(n2, n1);

    printf("Tester la divison d'un entier par un autre flottant\n");
    test_division_nombres(n1, n4);

    printf("Tester la divison d'un flottant par un autre entier\n");
    test_division_nombres(n3, n1);

    printf("Tester la divison d'un flottant par un autre flottant\n");
    test_division_nombres(n3, n4);


    printf("Tests: Partie 3 Moyenne : ====== \n");
    printf("Tester la moyenne lorsque elle est entière\n");
    test_moyenne_nombre(notes1, 3);
    
    
    printf("Tester la moyenne lorsque elle est décimal\n");
    test_moyenne_nombre(notes2, 5);
    printf("============\n");


}


int main(void){

    printf("Question1: ==================================\n");
    question1();
    printf("==================================\n");
    printf("\n");


    printf("Question2: ==================================\n");
    question2();
    printf("==================================\n");
    printf("\n");


    printf("Question3: ==================================\n");
    question3();
    printf("==================================\n");
    printf("\n");


    printf("Question4: ==================================\n");
    question4();
    printf("==================================\n");
    printf("\n");


    printf("Question4: ==================================\n");
    question5();
    printf("==================================\n");
    printf("\n");





    return 0;
}
