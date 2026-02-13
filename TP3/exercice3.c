#include <stdio.h>
#include <stdlib.h>

void affiche_tableau(int tab[], int n)
{
    int i;
    printf("[");
    for (i = 0; i < n; i++)
    {
        if (i == 0)
        {
            printf("%d", tab[i]);
        }
        else
        {
            printf(", %d", tab[i]);
        }
    }
    printf("]\n");
}
/*
    notes int* : tableau de notes
    taile int : taille du tableau
    n int : nombre de notes entrées dans le tableau

*/

typedef struct
{
    int *notes;
    int taille;
    int n;
} bulletin;

bulletin nouveau(int taille)
{
    bulletin nouveau_bulletin;
    int *tab;

    tab = calloc(taille, sizeof(int) * taille);
    nouveau_bulletin.notes = tab;
    nouveau_bulletin.taille = taille;
    nouveau_bulletin.n = 0;

    return nouveau_bulletin;
}

void test_nouveau(int taille)
{
    bulletin nouveau_bulletin = nouveau(taille);

    printf("Nouveau Bulletin:\n");
    printf("Tableau notes:");
    affiche_tableau(nouveau_bulletin.notes, taille);
    printf("Le taille de tableau est : %d\n", nouveau_bulletin.taille);
    printf("Le nombre de notes est : %d\n", nouveau_bulletin.n);

    free(nouveau_bulletin.notes);
}

void question1()
{

    test_nouveau(5);
    test_nouveau(0);
}

void liberer_memoire(bulletin b)
{
    free(b.notes);
}

/*
    Écrivez une fonction int ajout_simple(bulletin *b, int note) ajoutant une nouvelle note audit bulletin.
    Cette fonction renverra 0 si tout s’est bien passé, -1 si la note n’est pas comprise entre 0 et 20 et -2 si le tableau
    de notes est déjà plein. Dans ces deux derniers cas, le bulletin ne sera pas modifié.
*/

int ajout_simple(bulletin *b, int note)
{
    if (note > 20 || note < 0)
    {
        return -1;
    }

    if (b->n == b->taille)
    {
        return -2;
    }

    b->notes[b->n] = note;
    b->n += 1;
    return 0;
}

void test_ajout_simple(bulletin *b, int note, int *tab_attendue, int taille_attendue, int n_attendue)
{
    int res = 0;

    printf("tableau de notes avant l'ajout");
    affiche_tableau(b->notes, b->taille);
    printf("le nombre de notes avant l'ajout: %d\n", b->n);
    res = ajout_simple(b, note);
    if (res == -1)
    {
        printf("Note pas compris entre 0 et 20\n");
        return;
    }

    if (res == -2)
    {
        printf("Il y a pas assez de place pour la nouvelle note\n");
        return;
    }
    else
    {
        printf("tableau de note après l'ajout:");
        affiche_tableau(b->notes, b->taille);
        printf("Le tableau attendue:");
        affiche_tableau(tab_attendue, taille_attendue);
        printf("Le nombre de notes après l'ajout %d (Attendue) = %d\n", b->n, n_attendue);
    }
}

void question2()
{

    bulletin bulletin1 = nouveau(5);

    int premier_ajout[] = {1, 0, 0, 0, 0};
    int deuxieme_ajout[] = {1, 15, 0, 0, 0};
    int troisieme_ajout[] = {1, 15, 20, 0, 0};
    int quatrieme_ajout[] = {1, 15, 20, 19, 0};
    int cinquieme_ajout[] = {1, 15, 20, 19, 16};

    test_ajout_simple(&bulletin1, 1, premier_ajout, 5, 1);
    printf("**********************************\n");
    test_ajout_simple(&bulletin1, 15, deuxieme_ajout, 5, 2);

    printf("**********************************\n");
    test_ajout_simple(&bulletin1, 22, deuxieme_ajout, 5, 2);

    printf("**********************************\n");
    test_ajout_simple(&bulletin1, -2, deuxieme_ajout, 5, 2);

    printf("**********************************\n");
    test_ajout_simple(&bulletin1, 20, troisieme_ajout, 5, 3);

    printf("**********************************\n");
    test_ajout_simple(&bulletin1, 19, quatrieme_ajout, 5, 4);

    printf("**********************************\n");
    test_ajout_simple(&bulletin1, 16, cinquieme_ajout, 5, 5);

    printf("**********************************\n");
    test_ajout_simple(&bulletin1, 16, cinquieme_ajout, 5, 5);

    liberer_memoire(bulletin1);
}

void afficher_bulletin(bulletin b)
{
    printf("%d/%d ", b.n, b.taille);
    affiche_tableau(b.notes, b.n);
}

void question6()
{

    bulletin bulletin1 = nouveau(3);

    afficher_bulletin(bulletin1);
    ajout_simple(&bulletin1, 5);
    afficher_bulletin(bulletin1);
    ajout_simple(&bulletin1, 9);
    afficher_bulletin(bulletin1);
    ajout_simple(&bulletin1, 10);
    afficher_bulletin(bulletin1);
    ajout_simple(&bulletin1, 22);
    afficher_bulletin(bulletin1);
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
    printf("Question6: ==================================\n");
    question6();
    printf("=============================================\n");
    printf("\n");

    return 0;
}