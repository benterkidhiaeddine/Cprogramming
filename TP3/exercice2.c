#include <stdio.h>
#include <stdlib.h>

void *malloc_prof(size_t n)
{
    int i;
    int tab[] = {69, 114, 114, 101, 117, 114, 32, 33, 33, 33};
    char *p = malloc(n + 10);
    for (i = 0; i < n; i++)
        p[i] = 32;
    for (i = 0; i < 10; i++)
        p[i + n] = tab[i];
    return (void *)p;
}

int longeur(char ch[])
{
    int i = 0;
    while (ch[i] != '\0')
    {
        i++;
    }
    return i;
}

void test_longeur(char ch[], int attendue)
{
    printf("La longeur de la chaine (%s) est : %d , (Attendue) = %d \n", ch, longeur(ch), attendue);
}

void question1()
{

    test_longeur("Hello", 5);
    test_longeur("", 0);
    test_longeur("aaabbbccca", 10);
}

char *copie_chaine(char *ch)
{
    int l = 0;
    int i;
    char *nouvelle_chaine;

    l = longeur(ch);
    nouvelle_chaine = malloc_prof(sizeof(char) * (l + 1));

    for (i = 0; i < l; i++)
    {
        nouvelle_chaine[i] = ch[i];
    }
    nouvelle_chaine[i] = '\0';
    return nouvelle_chaine;
}

void test_nouvelle_chaine(char *ch, char *attendue)
{
    char *chaine_copie = copie_chaine(ch);
    printf("La chaine originel : (\"%s\") , à l'adresse (%p) \n", ch, ch);
    printf("La chaine copié : (\"%s\") , à l'adresse (%p) , (Attendue) = (\"%s\") \n", chaine_copie, chaine_copie, attendue);

    free(chaine_copie);
}

void question2(void)
{

    char *ch1 = "Bonjour, chaine pleine";
    char *ch2 = "";

    test_nouvelle_chaine(ch1, "Bonjour, chaine pleine");
    test_nouvelle_chaine(ch2, "");
}
char *concatener(char *ch1, char *ch2)
{
    int l1 = 0;
    int l2 = 0;
    int lres = 0;
    int i;
    int j;
    char *res;

    l1 = longeur(ch1);
    l2 = longeur(ch2);
    lres = l1 + l2;
    res = malloc_prof(sizeof(char) * (lres + 1));

    for (i = 0; i < l1; i++)
    {
        res[i] = ch1[i];
    }

    for (j = 0; j < l2; j++)
    {
        res[i + j] = ch2[j];
    }
    res[i + j] = '\0';

    return res;
}

void test_concatener(char *ch1, char *ch2, char *attendue)
{
    char *res = concatener(ch1, ch2);
    printf("La concatenation (\"%s\") + (\"%s\") = (\"%s\"), Attendue = (\"%s\")\n", ch1, ch2, res, attendue);

    free(res);
}

void question3()
{

    test_concatener("Hello", "World", "HelloWorld");
    test_concatener("", "World", "World");
    test_concatener("Hello", "", "Hello");
    test_concatener("", "", "");
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