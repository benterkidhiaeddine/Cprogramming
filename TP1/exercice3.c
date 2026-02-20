#include <stdio.h>

void vide_buffer(void)
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}
int lire_entier(void)
{

    char c;
    int acc;
    /*Accumulateur pour stocker le nombre*/
    acc = 0;
    printf("entier> ");
    while ((c = getchar()) != '\n' && c != EOF)
    {
        /*On vérifie si le charactère n'est  pas numeric*/
        if (c < '0' || c > '9')
        {
            vide_buffer();
            return (-1);
        }
        acc = acc * 10 + (c - '0');
    }

    return (acc);
}

float moyenne_stdin()
{
    int somme_notes, nombres_de_notes, note;

    somme_notes = 0;
    nombres_de_notes = 0;

    while ((note = lire_entier()) != -1)
    {
        if (note <= 20)
        {
            somme_notes += note;
            nombres_de_notes++;
        }
    }

    /*Gérer le cas ou le nombre de notes entrés valides est 0*/
    if (nombres_de_notes == 0)
    {
        return 0;
    }

    return (somme_notes / (nombres_de_notes / 1.));
}

void question3()
{

    int i;
    for (;;)
    {
        i = lire_entier();
        if (i == -1)
        {
            printf("Ce n'est pas un entier\n");
        }
        else if (i % 2 == 0)
        {
            printf("L'entier %d est pair\n", i);
        }
        else
        {

            printf("L'entier %d est impair\n", i);
        }
    }
}

void question4()
{
    float moyenne;
    moyenne = moyenne_stdin();
    printf("La moyenne est %.2f \n", moyenne);
}

void division_euclidienne(int a, int b)
{
    int reste, quotient;
    if (b == 0)
    {
        printf("On peut pas déviser par zéro\n");
        return;
    }
    else
    {
        reste = a % b;
        quotient = a / b;
        printf("%d = %d * %d + %d\n", a, quotient, b, reste);
    }
    return;
}

void division_decimal(int a, int b)
{
    float res;
    if (b == 0)
    {
        printf("On peut pas déviser par zéro\n");
        return;
    }

    res = a / (b / 1.);
    printf("%d = %.2f * %d\n", a, res, b);

    return;
}

void question5()
{
    division_euclidienne(25, 10);
    division_euclidienne(25, 0);
    division_euclidienne(10, 25);
}

void question6()
{
    division_decimal(25, 10);
    division_decimal(25, 0);
}

void division(int a, int b)
{
    int reste;
    if (b == 0)
    {
        printf("On peut pas déviser par zéro\n");
        return;
    }
    reste = a % b;
    if (reste == 0)
    {
        printf("%d/%d = %d\n", a, b, a / b);
    }
    else
    {
        printf("%d/%d = %.2f\n", a, b, a / (b / 1.));
    }
    return;
}
void question7(void)
{
    division(25, 10);
    division(30, 10);
    division(30, 0);
    division(0, 0);
    division(0, 10);
}

int main(void)
{
    /*question3();*/
    /*question4();*/
    /*question5();*/
    /*question6();*/
    question7();

    return 0;
}

/*
    Boucles infinies
*/
for (;;)
{
}

while (1)
{
}