#include <stdio.h>
void question1(){
    printf("Hello World\n");
}


void question2(){
    int i;

    i = 65;
    while (i <= 90) {
        printf("%d ", i);
        i++;
    }
    printf("\n");
}

void question3(){
    int i;

    i = 65;
    while (i <= 90) {
        printf("%c ", i);
        i++;
    }
    printf("\n");
}


void question4(){
    char *s;
    double x;


    s = "Pi vaut";
    x = 3.1415926;

    printf("%s %.7f\n", s, x);


}

void question5(void) {
    char c;
    int i;
    c = 'a';
    i = c + 1;
    printf("Valeur de c en caractère est '%c' et son équivalent décimal vaut %d\n",c,c);
    printf("Valeur de i en caractère est '%c' et son équivalent décimal vaut %d\n",i,i);
}


void question6(){
    int a, z;
    a = 97;
    z = a + 25;


    while (a <= z){
        printf("%c ",a);
        a++;
    }
    printf("\n");

}




int main(void){

    question1();
    question2();
    question3();
    question4();
    question5();
    question6();
    return 0;

}