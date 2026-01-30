#include <stdio.h>


struct horaire_struct {
    short h;
    short m;
    short s;
};

typedef struct horaire_struct horaire;


horaire nouvel_horaire(short h, short m ,short s){
    horaire n_horaire;
    n_horaire.h = h;
    n_horaire.m = m;
    n_horaire.s = s;
    return n_horaire;
}

/*Cette fonction affiche l'horraire sans la nouvelle ligne*/
void _afficher_horraire(horaire h){
    printf("%02dh %02dm %02ds", h.h, h.m, h.s);

}

void afficher_horaire(horaire h){
    _afficher_horraire(h);
    printf("\n");
}


horaire ajout(horaire h1, horaire h2){
    horaire n_horaire;
    short somme_secondes = h1.s + h2.s;
    short somme_minutes = h1.m + h2.m;
    short somme_heures = h1.h + h2.h; 

    short s =  somme_secondes % 60;
    short m = (somme_minutes + (somme_secondes / 60)) % 60; 
    short h = ( somme_heures + somme_minutes / 60) % 24;

    n_horaire.s = s;
    n_horaire.m = m;
    n_horaire.h = h;

    return n_horaire;

}


horaire secondes_vers_horaire(int s) {
    horaire n_horaire;

    short new_s = s % 60; 
    short m = s / 60; 
    short h = m / 60;
    m = m % 60;
    h = h % 24;

    n_horaire.s = new_s;
    n_horaire.m = m;
    n_horaire.h = h;
    return n_horaire;
}

int horaire_vers_secondes(horaire h){
    int res = (h.h * 60 * 60 + h.m *60 + h.s);
    return res;
}


void question1(void){
    short h = 12;
    short m = 30;
    short s = 22;

    horaire horaire_1 =  nouvel_horaire(h, m , s);
    afficher_horaire(horaire_1);


}


void question2(void){

    short h = 5;
    short m = 3;
    short s = 2;

    horaire horaire_2 =  nouvel_horaire(h, m , s);
    afficher_horaire(horaire_2);



}


void test_ajout_horraire(horaire h1 , horaire h2){

    printf("La somme de l'horraire ");
    _afficher_horraire(h1);
    printf(" et l'horraire ");
    _afficher_horraire(h2);
    printf(" est : ");
    afficher_horaire(ajout(h1 ,h2));

}
void question3(void){

    horaire h1 = {1 , 20 , 35};
    horaire h2 = {22 , 40 , 0 };

    test_ajout_horraire(h1,h2);
}

void test_secondes_vers_horraires(horaire h , int s){

    printf("l'horraire pour  %dsecondes est ", s);
    afficher_horaire(h);

}
void question4(void){


    int s1 = 62;
    int s2 = 120;
    int s3 = 0;
    int s4 = 86400;
    horaire h1 = secondes_vers_horaire(s1);
    horaire h2 = secondes_vers_horaire(s2);
    horaire h3 = secondes_vers_horaire(s3);
    horaire h4 = secondes_vers_horaire(s4);

    test_secondes_vers_horraires(h1, s1);

    test_secondes_vers_horraires(h2, s2);

    test_secondes_vers_horraires(h3, s3);

    test_secondes_vers_horraires(h4, s4);
}


void test_horaires_vers_secondes(horaire h, int s){

    printf("Le nombre de secondes  est: %d secondes ",s);
    printf("pour l'horraire: ");
    afficher_horaire(h);

}

void question5(void){

    horaire h1 = {1 , 20 , 35};
    horaire h2 = {0 , 2 , 0 };
    horaire h3 = {22 , 30 , 0 };
    horaire h4 = {23 , 59 , 59 };



    int s1 = horaire_vers_secondes(h1);
    int s2 = horaire_vers_secondes(h2);
    int s3 = horaire_vers_secondes(h3);
    int s4 = horaire_vers_secondes(h4);

    test_horaires_vers_secondes(h1, s1 );
    test_horaires_vers_secondes(h2, s2 );
    test_horaires_vers_secondes(h3, s3 );
    test_horaires_vers_secondes(h4, s4 );

}


int main(void){

    printf("Question1 :===================================\n");
    question1();

    printf("==========================\n");
    printf("\n");
 
    printf("Question2 :===================================\n");
    question2();

    printf("==========================\n");
    printf("\n");
 
    printf("Question3 :===================================\n");
    question3();
 
    printf("==========================\n");
    printf("\n");
 

    printf("Question4 :===================================\n");
    question4();

    printf("==========================\n");
    printf("\n");
 

    printf("Question5 :===================================\n");
    question5();


    printf("==========================\n");
    printf("\n");
 
    
 
   return 0;
}