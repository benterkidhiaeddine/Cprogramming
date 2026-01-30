#include <stdio.h>



void vide_buffer(void){
    char c;
    while ((c =getchar()) != '\n' && c != EOF ){}
}
int lire_entier(void){

    char c;
    int acc = 0;
    /*Ce flag pour éviter le cas ou on spamme des espaces et entre pas dans la boucle , dans ce cas on attend que 
    ca donne -1 mais ca donne 0 selon notre accumulateur , donc on s'assure qu'on entre au moins dans la boucle sinon on retourne
    - 1*/
    short flag = 0;

    /*Accumulateur pour stocker le nombre*/
    acc = 0;
    printf("entier> ");
    while ( (c = getchar()) != '\n' && c != EOF  ){
        flag = 1;
        /*On vérifie si le charactère n'est  pas numeric*/
        if (c >= '0' && c <= '9' ){
            acc = acc * 10 + (c - '0');
        }
        else {
            vide_buffer();
            return (-1);
        }
    }
    if (flag == 0){
        return -1;
    }
    return (acc);
}




void affiche_tableau(int tab[], int n){
    int i;
    printf("Le tableau lu est : [");
    for (i = 0; i < n; i++ ){
        if (i == 0){
            printf(" %d ", tab[i]);
        }
        else {
            printf(", %d ", tab[i]);
        }
        
    }
    printf("]\n");
    

}

int saisie_tab(int tableau[]){
    int num = 0;
    int compte = 0;
    
    while ((num = lire_entier()) != -1){
        tableau[compte] = num;
        compte++;

    }

    affiche_tableau(tableau, compte);
    return compte;

}


void question1(void){
    /*0 - 9*/
    int tab2[] = {1, 1 ,3, 5 ,8 ,13};
    int tab1[10];
    int i;
    for (i = 0; i < 10; i++){
        tab1[i] = i;
    }
    printf("Afficher tab1 5 premiers éléments\n");
    affiche_tableau(tab1, 5);

    printf("Afficher tab1 10 premiers éléments\n");
    affiche_tableau(tab1, 10);

    
    printf("Afficher tab1 0 premiers éléments\n");
    affiche_tableau(tab1, 0);
    
    printf("Afficher les 5 premiers de tab2\n");
    affiche_tableau(tab2 , 5);
    
    printf("Exemple bugé , accès à une valeur en dehors du tableau\n");
    printf("Afficher tab1 11 premiers éléments\n");
    affiche_tableau(tab1, 11);

}


void question3(void){
    int tab1[10];
    saisie_tab(tab1);

}

int main (void){
    printf("Question1 :===============================\n");
    question1();

    printf("===============================\n");
    printf("\n");
    
    
    printf("Question3 :===============================\n");
    question3();
 
    printf("===============================\n");
    printf("\n");
 
    return (0);
}