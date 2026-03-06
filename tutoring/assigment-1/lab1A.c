#include <stdio.h>
#include "myheader.h"


int main(){


    while (1){
        int integer = 0;
        char character = '0';
        int digitValue = 0;

        printf("Enter an integer and a character separated by blank:");
        scanf("%d %c",&integer , &character);

        if (integer == -10000){
            break;
        }

        if (isLetter(character) == 1){
            printf("Character \'%c\' represents a letter\n", character);
            
        }
        else if (isOperator(character) == 1){
            printf("Character \'%c\' represents an operator\n", character);
        }

        else if (isDigit(character) == 1){
            digitValue = character - '0';
            int result  = digitValue + integer;
            printf("Character \'%c\' represents a digit.Sum of %d and %d is %d\n",character, integer, digitValue, result);
        }

        else{

            printf("Character \'%c\' represents others\n", character);
        }

    }

}
    

int isDigit(char c){
    if (c >= '0' && c <= '9'){
        return 1;
    } else{
        return 0;
    }
}


int isLetter(char c){
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
        return 1;
    } else{
        return 0;
    }
}


int isOperator(char c){
    if (c == '+' || c == '-' || c == '/' || c == '*' || c == '%' ){
        return 1;
    }else {
        return 0;
    }
}