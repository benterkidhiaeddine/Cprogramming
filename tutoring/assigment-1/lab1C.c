#include <stdio.h>

#define N 10

int isDigit(char c);

int main(){

    int otherCount = 0;
    int countArray[10];
    int c;
    
    c = getchar();
    while (c != EOF){

        if (isDigit(c) == 1){
            countArray[c - '0'] += 1;
        }
        else{
            otherCount += 1;
        }

        c = getchar();

    }

    for (int i = 0; i < N; i++){
        printf("%d: %d\n", i, countArray[i]);
    }
    printf("X: %d\n", otherCount);

}
    

int isDigit(char c){
    if (c >= '0' && c <= '9'){
        return 1;
    } else{
        return 0;
    }
}
