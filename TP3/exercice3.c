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

/*

7. Écrivez une fonction ajout qui ajoute une nouvelle note au bulletin. Cependant, si le tableau est plein, on remplace
la plus mauvaise note du tableau par celle donnée en paramètre (si cette dernière est meilleure, évidement). On
utilisera la fonction ajout_simple et on renverra 0 si l’ajout s’est fait sans problème, 1 si le tableau étant plein,
la pire note a été remplacée, 2 si le tableau étant plein, la nouvelle note a été ignorée car trop mauvaise et -1 en
cas de note non valide. Remarque : vous avez le droit de créer des fonctions auxiliaires pour simplifier votre code.

*/

int min_idx_tab_notes(int tab[], int taille)
{
    int i;
    int min_idx = 0;

    /*
        retourner -1 si le tableau est vide, les notes sont tous positifs
    */
    if (taille == 0)
    {
        return -1;
    }

    for (i = 1; i < taille; i++)
    {
        if (tab[i] < tab[min_idx])
        {
            min_idx = i;
        }
    }

    return min_idx;
}

int ajout(bulletin *b, int note)
{

    int min_idx = 0;
    if (note < 0 || note > 20)
    {
        return -1;
    }

    /*
        cas ou le bulletin à un tableau de notes avec une taille égale = 0, cad il est toujours plein

    */
    if (b->taille == 0)
    {
        return 2;
    }

    /*
        tableau plein
    */
    if (b->n == b->taille)
    {
        /*
            pas besoin de vérifier s'il y a une erreur , on sait d'emblé que le talbeau a au moins un élément
        */
        min_idx = min_idx_tab_notes(b->notes, b->taille);
        if (note < b->notes[min_idx])
        {
            return 2;
        }
        else
        {
            b->notes[min_idx] = note;
            return 1;
        }
    }

    b->notes[b->n] = note;
    b->n = (b->n) + 1;

    return 0;
}

void test_ajout(bulletin *b, int note, int attendue)
{
    int code;
    printf("Avant ajout de la note %d \n", note);
    afficher_bulletin(*b);
    code = ajout(b, note);
    printf("Après ajout de la note %d, code de retour %d , Attendue = %d\n", note, code, attendue);
    afficher_bulletin(*b);
}

void question7(void)
{

    bulletin bulletin1 = nouveau(3);
    test_ajout(&bulletin1, 5, 0);
    test_ajout(&bulletin1, 9, 0);
    test_ajout(&bulletin1, 10, 0);
    test_ajout(&bulletin1, 22, -1);
    test_ajout(&bulletin1, -1, -1);
    test_ajout(&bulletin1, 4, 2);
    test_ajout(&bulletin1, 6, 1);
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
    printf("Question7: ==================================\n");
    question7();
    printf("=============================================\n");
    printf("\n");

    return 0;
}