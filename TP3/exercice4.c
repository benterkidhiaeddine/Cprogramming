#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *memoire;
    int taille;
    int n;
} tableau;

tableau *nouveau_tableau(int taille)
{
    tableau *nouveau = malloc(sizeof(tableau));
    int *memoire = malloc(taille * sizeof(int));
    nouveau->memoire = memoire;
    nouveau->taille = taille;
    nouveau->n = 0;
    return nouveau;
}

void liberer_tableau(tableau *t)
{
    free(t->memoire);
    free(t);
}

void afficher_tableau(tableau *t)
{
    int i;
    printf("%d/%d ", t->n, t->taille);
    printf("[");
    for (i = 0; i < t->n; i++)
    {
        if (i == 0)
        {
            printf("%d", t->memoire[i]);
        }
        else
        {
            printf(", %d", t->memoire[i]);
        }
    }
    printf("]\n");
}

void test_afficher_tableau(tableau *t, char *attendue)
{
    afficher_tableau(t);
    printf("Résultat attendue : %s\n", attendue);
}

void question4(void)
{
    tableau *tableau1 = nouveau_tableau(3);
    test_afficher_tableau(tableau1, "0/3 []");

    liberer_tableau(tableau1);
}

int ajout_simple(tableau *t, int valeur)
{

    if (t->n == t->taille)
    {
        return -1;
    }

    t->memoire[t->n] = valeur;
    t->n += 1;
    return 0;
}

void question5(void)
{
    tableau *tableau1 = nouveau_tableau(3);
    test_afficher_tableau(tableau1, "0/3 []");

    ajout_simple(tableau1, 5);
    test_afficher_tableau(tableau1, "1/3 [5]");

    ajout_simple(tableau1, 9);
    test_afficher_tableau(tableau1, "2/3 [5, 9]");

    ajout_simple(tableau1, 1);
    test_afficher_tableau(tableau1, "3/3 [5, 9, 1]");

    ajout_simple(tableau1, 5);
    test_afficher_tableau(tableau1, "3/3 [5, 9, 1]");

    liberer_tableau(tableau1);
}

void agrandir_v1(tableau *t)
{
    int i;
    int nouvelle_taille = t->taille * 2;
    int *nouvel_memoire = malloc(nouvelle_taille * sizeof(int));

    for (i = 0; i < t->n; i++)
    {
        nouvel_memoire[i] = t->memoire[i];
    }
    free(t->memoire);
    t->memoire = nouvel_memoire;
    t->taille = nouvelle_taille;
}

void agrandir(tableau *t)
{
    int nouvelle_taille = t->taille * 2;
    int *nouvel_memoire = realloc(t->memoire, (nouvelle_taille) * sizeof(int));

    t->memoire = nouvel_memoire;
    t->taille = nouvelle_taille;
}

void question6(void)
{

    tableau *tableau1 = nouveau_tableau(3);
    test_afficher_tableau(tableau1, "0/3 []");

    agrandir(tableau1);
    test_afficher_tableau(tableau1, "0/6 []");

    ajout_simple(tableau1, 5);
    test_afficher_tableau(tableau1, "1/6 [5]");

    agrandir(tableau1);
    test_afficher_tableau(tableau1, "1/12 [5]");

    liberer_tableau(tableau1);
}

void ajout(tableau *t, int valeur)
{

    if (t->n == t->taille)
    {
        agrandir(t);
    }

    t->memoire[t->n] = valeur;
    t->n += 1;
}

void question7()
{

    tableau *tableau1 = nouveau_tableau(3);
    test_afficher_tableau(tableau1, "0/3 []");

    ajout(tableau1, 2);
    test_afficher_tableau(tableau1, "1/3 [2]");

    ajout(tableau1, 3);
    test_afficher_tableau(tableau1, "2/3 [2, 3]");

    ajout(tableau1, 4);
    test_afficher_tableau(tableau1, "3/3 [2, 3, 4]");

    ajout(tableau1, 12);
    test_afficher_tableau(tableau1, "4/6 [2, 3, 4, 12]");

    liberer_tableau(tableau1);
}

/*
    Decale tous les elements dans un tableau vers la droite à partir de l'indice i
*/
void decale_droit(tableau *t, int i)
{
    int n = (t->n) - 1;
    for (; n >= i; n--)
    {
        t->memoire[n + 1] = t->memoire[n];
    }
}
int inserer(tableau *t, int i, int valeur)
{
    /*
        Indice depasse le tableau
        Pour interdire les insertions avec des trous
    */
    if (i > t->n)
    {
        return -1;
    }

    if (t->n == t->taille)
    {
        agrandir(t);
    }
    /* Si l'index d'insertion est avant le dernier élément présent dans le tableau on décale */
    if (i < t->n)
    {
        decale_droit(t, i);
    }
    t->memoire[i] = valeur;
    t->n += 1;

    return 0;
}

void question8(void)
{

    tableau *tableau1 = nouveau_tableau(3);
    test_afficher_tableau(tableau1, "0/3 []");

    ajout(tableau1, 2);
    test_afficher_tableau(tableau1, "1/3 [2]");

    ajout(tableau1, 3);
    test_afficher_tableau(tableau1, "2/3 [2, 3]");

    ajout(tableau1, 4);
    test_afficher_tableau(tableau1, "3/3 [2, 3, 4]");

    inserer(tableau1, 1, 12);
    test_afficher_tableau(tableau1, "4/6 [2, 12, 3, 4]");

    inserer(tableau1, 99, 12);
    test_afficher_tableau(tableau1, "4/6 [2, 12, 3, 4]");

    inserer(tableau1, 3, 22);
    test_afficher_tableau(tableau1, "5/6 [2, 12, 3, 22, 4]");

    inserer(tableau1, 5, 10);
    test_afficher_tableau(tableau1, "6/6 [2, 12, 3, 22, 4, 10]");
    liberer_tableau(tableau1);
}

void decale_gauche(tableau *t, int i)
{
    int n = t->n;
    for (; i < n - 1; i++)
    {
        t->memoire[i] = t->memoire[i + 1];
    }
}

int supprimer(tableau *t, int indice, int *valeur)

{
    /*
        Pour interdire la supression des elements qui sont pas vraiment inséres dans le tableau
    */
    if (indice >= t->n)
    {
        return -1;
    }

    *valeur = t->memoire[indice];
    decale_gauche(t, indice);
    t->n -= 1;
    return 0;
}

void question9(void)
{
    int valeur1 = 0;

    tableau *tableau1 = nouveau_tableau(3);
    test_afficher_tableau(tableau1, "0/3 []");

    ajout(tableau1, 2);
    test_afficher_tableau(tableau1, "1/3 [2]");

    ajout(tableau1, 3);
    test_afficher_tableau(tableau1, "2/3 [2, 3]");

    ajout(tableau1, 4);
    test_afficher_tableau(tableau1, "3/3 [2, 3, 4]");

    supprimer(tableau1, 1, &valeur1);
    test_afficher_tableau(tableau1, "2/3 [2, 4]");

    printf("La valeur supprimé %d, La valeur attendue %d\n", valeur1, 3);

    if (supprimer(tableau1, 5, &valeur1) == 0)
    {
        test_afficher_tableau(tableau1, "2/3 [2, 4]");
    }
    else
    {
        printf("Erreur Index en dehors du tableau\n");
    }

    liberer_tableau(tableau1);
}

void supprimer_doublon(tableau *t)
{
    int curr;
    int i, j;
    int garbage;

    for (i = 0; i < (t->n) - 1; i++)
    {
        curr = t->memoire[i];
        for (j = i + 1; j <= (t->n) - 1; j++)
        {
            if (t->memoire[j] == curr)
            {
                supprimer(t, j, &garbage);
                /*
                    Décrementer j en cas du spression pour ne pas rater un doublon consécutif
                    parcque la fonction supprimer décale le tableau vers la gauche
                */
                j--;
            }
        }
    }
}

void question10(void)
{
    int garbage;
    tableau *tableau1 = nouveau_tableau(6);
    test_afficher_tableau(tableau1, "0/6 []");

    ajout(tableau1, 11);
    ajout(tableau1, 31);
    ajout(tableau1, 11);
    ajout(tableau1, 12);
    ajout(tableau1, 11);
    ajout(tableau1, 31);

    test_afficher_tableau(tableau1, "6/6 [11, 31, 11, 12, 11, 31]");

    supprimer_doublon(tableau1);
    test_afficher_tableau(tableau1, "3/6 [11, 31, 12]");

    /*
        Vider le tableau
    */
    supprimer(tableau1, 0, &garbage);
    supprimer(tableau1, 0, &garbage);
    supprimer(tableau1, 0, &garbage);

    test_afficher_tableau(tableau1, "0/6 []");

    /*
        Ajouter des valeurs consécutifs
    */
    ajout(tableau1, 11);
    ajout(tableau1, 11);
    ajout(tableau1, 11);

    test_afficher_tableau(tableau1, "3/6 [11, 11, 11]");

    supprimer_doublon(tableau1);
    test_afficher_tableau(tableau1, "1/6 [11]");

    liberer_tableau(tableau1);
}
int main(void)
{
    printf("Question4: ==================================\n");
    question4();
    printf("=============================================\n");

    printf("Question5: ==================================\n");
    question5();
    printf("=============================================\n");

    printf("question6: ==================================\n");
    question6();
    printf("=============================================\n");

    printf("question7: ==================================\n");
    question7();
    printf("=============================================\n");

    printf("question8: ==================================\n");
    question8();
    printf("=============================================\n");

    printf("question9: ==================================\n");
    question9();
    printf("=============================================\n");

    printf("question10: ==================================\n");
    question10();
    printf("=============================================\n");

    return 0;
}