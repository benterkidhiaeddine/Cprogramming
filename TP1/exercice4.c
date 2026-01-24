#include <stdio.h>


int main(void){
    int ligne, colonne;

    for (ligne = 0; ligne <=9; ligne++){
        for (colonne = 1; colonne <= 10; colonne++){
            printf("% 4d", colonne + (ligne * 10));
        }
        printf("\n");
    }


    return (0);

}