#include <stdio.h>

/*
Écrivez la fonction int chercher_caractere(char chaine[], char symbole) : cette fonction renvoie vrai
(sous forme d’entier) si un caractère symbole apparaît dans la chaîne chaine, faux sinon.
*/
int chercher_caractere(char chaine[], char symbole){
    int i;
    for (i = 0; chaine[i] != '\0'; i++){
        if (chaine[i] == symbole){
            return 1;
        }
    }
    return 0;

}

void test_cherher_caractere(char chaine[], char symbole, char expected[]){
    char*  reponse;
    if (chercher_caractere(chaine, symbole)){
        reponse = "Oui";
    }
    else{
        reponse = "Non";
    }
    printf("La chaine \"%s\" continet le charactère \'%c\' :(Retour: %s)  == (Attendue:%s)\n", chaine, symbole, reponse, expected );

}

void question1(void){
    char * str1 = "hello";
    char * str2 = "aaaaaaaaaaaaaaaaaaaaaaa;";
    char * str3 = "bba;";
    char * str4 = "";
    char c1 = 'l';
    char  c2 = ';';
    char  c3 = 'c';
    char  c4 = 'z';
    test_cherher_caractere(str1, c1 , "Oui");
    test_cherher_caractere(str2, c2 , "Oui");
    test_cherher_caractere(str3, c3 , "Non");
    test_cherher_caractere(str4, c4 , "Non");
}

/*
2. Écrivez la fonction int egale(char chaine1[], char chaine2[]) testant l’égalité de deux chaînes de caractères.
*/
int egale(char chaine1[], char chaine2[]){

    int i = 0;
    while (chaine1[i] != '\0' && chaine2[i] != '0'){
        if (chaine1[i] != chaine2[i]){
            return 0;
        } 
        i++;
    }


    return (chaine1[i] == chaine2[i]);


}


void tester_egale(char chaine1[] , char chaine2[], char expected[]){

    char*  reponse;
    if (egale(chaine1, chaine2)){
        reponse = "Oui";
    }
    else{
        reponse = "Non";
    }
    printf("La chaine \"%s\" est égale à la chaine \'%s\' :(Retour: %s)  == (Attendue:%s)\n", chaine1, chaine2, reponse, expected );

}


void question2(void){
    char* str1 = "hello";
    char* str2 = "hellos";


    char* str3 = "abca";
    char* str4 = "";

    tester_egale(str1 , str2 ,"Non");
    tester_egale(str3 , str3 ,"Oui");
    tester_egale(str3 , str4 ,"Non");

}

/*
3. Écrivez la fonction void miroir(char chaine []) qui modifie la chaine en argument pour la remplacer par
son miroir.

*/

int length(char chaine[]){
    int i = 0;
    while(chaine[i] != '\0'){
        i++;
    }
    return i ;
}

void miroir(char chaine []){

    int start = 0;
    int end  = length(chaine) - 1;
    while (start < end){
        char tmp = chaine[end];
        chaine[end] = chaine[start];
        chaine[start] = tmp;
        start++;
        end--;
    }

}
/*
4. Écrivez la fonction int inclue(char chaine[], char sous_chaine[]) qui teste si le second paramètre de
la fonction est une sous-chaîne du premier.
*/

int inclue(char chaine[], char sous_chaine[]){
    int i = 0;
    int j = 0;
    while (chaine[i] != '\0' && sous_chaine[j] != '\0'){
        if (chaine[i] == sous_chaine[j]){
            i++;
            j++;
        }
        else {
            i++;
            j = 0;
        }
    }
        
    return sous_chaine[j] == '\0';
} 




void test_inclue(char chaine[], char sous_chaine[], char expected[] ){

    char*  reponse;
    if (inclue(chaine, sous_chaine)){
        reponse = "Oui";
    }
    else{
        reponse = "Non";
    }
    printf("La chaine \"%s\" inclue  la chaine \'%s\' :(Retour: %s)  == (Attendue:%s)\n", chaine, sous_chaine, reponse, expected );

}

void question4(){

    char * str1 = "hello";
    char * str2 = "ll";

    test_inclue(str1 , str2, "Oui");
}




void test_miroir(char chaine [],char initial[], char expected[]){

    miroir(chaine);
    printf("Le miroir de la chaine \"%s\" est :(Retour: %s)  == (Attendue:%s)\n", initial, chaine, expected );


}


void question3(){
    char  str1[4] = "bba";
    char  expected1[4] = "abb";
    test_miroir(str1, "bba", expected1);

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


    printf("Question3: ==================================\n");
    question4();
    printf("==================================\n");
    printf("\n");


    return 0;
}