#include <stdio.h>



/*
    1. Écrivez une fonction unsigned int lire_binaire(char chaine[]) qui transforme une chaîne représentant
    un nombre en binaire en entier. On autorisera les espaces ("1111 1111" correspond à 255). On renverra -1 en
    cas d’erreur.
*/
unsigned int lire_binaire(char chaine[]){
    unsigned int acc = 0;
    int i;
    for (i = 0 ; chaine[i] != '\0'; i++){
        char c = chaine[i];
        if (c == ' '){
            continue;
        }
        if (c > '9' ||  c < '0'){
            return -1;
        }
        acc = acc * 2 + (c - '0');
    }
    return acc;
}

void test_lire_binaire(char chaine[] , unsigned int expected) {

    unsigned int res = lire_binaire(chaine);
    if (res == -1){
        printf("L'entrée  \'%s\' n'est pas un nombre binaire valide\n", chaine);
        return;
    }
    printf("La chaine de charactère \'%s\' corrspond au nombre: %u Attendue = %u\n",chaine,  res, expected);
} 


void question1(){
    unsigned int max_unsigend_int = 4294967295;
    test_lire_binaire("1111 1111" , 255);
    test_lire_binaire("1" , 1);
    test_lire_binaire("0" , 0);
    test_lire_binaire("011" , 3);
    test_lire_binaire("011" , 3);
    test_lire_binaire("                101" , 5);
    test_lire_binaire("  1011   " , 11);
    test_lire_binaire("111" , 7);
    test_lire_binaire("1111 1111 1111 1111" , (1 << 16) - 1);
    test_lire_binaire("1111 1111 1111 1111 1111 1111 1111 1111" ,  max_unsigend_int);
    test_lire_binaire("11111 1111 1111 1111 1111 1111 1111 1111" ,  max_unsigend_int);
    test_lire_binaire("acb111" ,  -1);
    test_lire_binaire("111bfcd" ,  -1);
    test_lire_binaire("-25" ,  -1);

}

/*
    2. Écrivez une fonction void afficher_binaire(unsigned int n) qui affiche un entier en binaire. On pourra
    utiliser un tableau de taille suffisante pour contenir tous les bits d’un entier de type int (astuce : sizeof(int)
    donne le nombre d’octet utilisé par le type int). Par soucis de lisibilité, on affichera les bits par groupe de 4 et on
l   n’affichera pas les zéros inutiles à la gauche du nombre. Exemple : 10 0010 1101.
*/
void afficher_binaire(unsigned int n){
    char res[sizeof(n) * 8];
    int i = 0; 
    if (n == 0){
        printf("0");
        return;
    }
    while (n > 0){
        int r = n % 2;
        n = (n - r) / 2;
        res[i] = r + '0';
        i++;
    }

    /*Fait en sorte que le pointeur revient au premier chiffre du nombre binaire */
    i -= 1;
    while (i >= 0){
        printf("%c", res[i]);
        if (i  % 4 == 0 && i != 0){
            printf(" ");
        }
        i--;
    }
    
}

void test_afficher_binaire(unsigned int n, char expected[]){
    printf("Le nombre decimal : %u en binaire est, (", n);
    afficher_binaire(n);
    printf(") , Attendue : (%s)",expected);
    printf("\n");
}

void question2(void){
    unsigned int max_unsigend_int = 4294967295;

    test_afficher_binaire(22 , "1 0110");
    test_afficher_binaire(202 ,"1100 1010");
    test_afficher_binaire(252, "1111 1100");
    test_afficher_binaire(12, "1100");
    test_afficher_binaire(7, "111");
    test_afficher_binaire(9, "1001");

    test_afficher_binaire(0 ,"0");

    test_afficher_binaire(max_unsigend_int, "1111 1111 1111 1111 1111 1111 1111 1111");

}



/*
    Checks if a string is a numeric string or not
*/
int is_numeric(char str[]){
    int i;
    for (i  = 0; str[i]!= '\0'; i++){
        if (str[i] < '0' || str[i] > '9' ){
            return 0;
        }
    }
    if (i != 0){
        return 1;
    } 
    return 0;
}

int str_to_int(char str[]){
    int i = 0;
    int acc = 0;

    for (; str[i] != '\0'; i++){
        acc = (acc * 10) + (str[i] - '0');
    }
    return acc;
}

int main(int argc, char *argv[]){
    int question_number = 0;
    if (argc != 2 || !is_numeric(argv[1]) ){
        printf("Usage : %s [question_number 1 - 2]\n", argv[0]);
        return (-1);
    }
    printf("This works \n");
    question_number =  str_to_int(argv[1]);
    if (question_number < 1 || question_number > 2){
        printf("Usage : %s [question_number 1 - 2]\n", argv[0]);
        return (-1);

    }


    switch(question_number){
        case 1:
            printf("Question1: ==================================\n");
            question1();
            printf("==================================\n");
            printf("\n");

        break;  
  
        case 2:
            printf("Question2: ==================================\n");
            question2();
            printf("==================================\n");
            printf("\n");
        break;
    }
    return 0;
}