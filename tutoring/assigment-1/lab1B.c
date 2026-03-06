#include <stdio.h>


int isDigit(char c);
int isLower(char c);
char toUpper(char c);

int main(){

    int c;
    int outC;

    c = getchar();

    //&& c != '\n'
    while (c != EOF){
        if (isLower(c) == 1){
            outC = toUpper(c);
        }
        else if (isDigit(c) == 1){
            if (c  >= '0' && c < '5') {
                outC = '-';
            }
            else if (c == '5'){
                outC = '5';
            }
            else if (c > '5' && c <= '9'){
                outC = '+';
            }
        }
        else{
            outC = c;
        }

        putchar(outC);
        c = getchar();
    }

}
    

int isDigit(char c){
    if (c >= '0' && c <= '9'){
        return 1;
    } else{
        return 0;
    }
}


char toUpper(char c){
    return c - ('a' - 'A');
}
int isLower(char c){
    if (c >= 'a' && c <= 'z') {
        return 1;
    } else{
        return 0;
    }
}


