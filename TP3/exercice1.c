#include <stdio.h>

void incremente(int *a)
{
    *a = *a + 1;
}

void test_incremente(int *a, int attendue)
{
    printf("La valeur à l\'adresse avant l'incrémentation %p est : %d\n", (void *)a, *a);
    incremente(a);
    printf("La valeur à l\'adresse après l'incrémentation %p est : %d (Attendue) = %d\n", (void *)a, *a, attendue);
}

void question1(void)
{
    int i1 = 12;
    int i2 = 0;
    int i3 = -2;

    test_incremente(&i1, 13);
    test_incremente(&i2, 1);
    test_incremente(&i3, -1);
}

void echange(int *a, int *b)
{
    int tmp = *b;
    *b = *a;
    *a = tmp;
}

void test_echange(int *a, int *b)
{
    printf("la valeurs avant l'échange: de a = %d,  b = %d\n", *a, *b);
    echange(a, b);
    printf("la valeurs après l'échange: de a = %d,  b = %d\n", *a, *b);
}

void question2(void)
{
    int a1 = 10;
    int b1 = 5;

    test_echange(&a1, &b1);
}

/*
    Mets la plus grand des valeurs dans b et la plus petite des valeurs dans a,
    return : int, 0 si il n'y a pas eu d'échange et 1 s'il y a eu d'échange
*/

int trier(int *a, int *b)
{
    if (*b > *a)
    {
        return 0;
    }
    else
    {
        echange(a, b);
        return 1;
    }
}

void test_trier(int *a, int *b, int attendue)
{

    int res = 0;

    printf("la valeurs avant l'échange: de a = %d,  b = %d\n", *a, *b);
    res = trier(a, b);
    printf("la valeurs après l'échange: de a = %d,  b = %d , le résultat de trier est : %d , (Attendue) = %d \n", *a, *b, res, attendue);
}

void question3(void)
{
    int a1 = 3;
    int b1 = 4;

    int a2 = 5;
    int b2 = 5;

    int a3 = 9;
    int b3 = 5;

    test_trier(&a1, &b1, 0);
    test_trier(&a2, &b2, 0);
    test_trier(&a3, &b3, 1);
}

int main(void)
{
    printf("Question1: ==================================\n");
    question1();
    printf("=============================================\n");
    printf("\n");

    printf("Question2: ==================================\n");
    question2();
    printf("=============================================\n");
    printf("\n");

    printf("Question3: ==================================\n");
    question3();
    printf("=============================================\n");
    printf("\n");

    return 0;
}