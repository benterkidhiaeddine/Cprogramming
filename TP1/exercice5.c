#include <stdio.h>

void vide_buffer(void){
    char c;
    while ((c =getchar()) != '\n' && c != EOF ){}
}
int lire_entier(void){

    char c;
    int acc;
    /*Accumulateur pour stocker le nombre*/
    acc = 0;
    printf("entier> ");
    while ( (c = getchar()) != '\n' && c != EOF ){
        /*On vérifie si le charactère n'est  pas numeric*/
        if (c >= '0' && c <= '9' ){
            acc = acc * 10 + (c - '0');
        }
        else {
            vide_buffer();
            return (-1);
        }
    }

    return (acc);
}

void espace(int n){
    int i;
    for (i = 1; i <= n; i++){
        printf(" ");
    }
}

void etoile_espace(int n){
    int i;
    for (i = 1; i <= n; i++){
        printf("* ");
    }
}

void pyramide(int n){

    int ligne;
    for (ligne = 1; ligne <= n; ligne++){
        espace(n - ligne);
        etoile_espace(ligne);
        printf("\n");
    } 

}

int main(void){
    int n;
    while ((n = lire_entier()) != -1){
        pyramide(n);
    }

    return (0);

}