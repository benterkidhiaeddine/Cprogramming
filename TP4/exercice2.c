#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

/*

Partie i : création des types
*/
/*
    Définir la cellule d'une liste chainée
*/
struct cellule
{
    struct cellule *suivant;
    int contenu;
};

/*
    Renommer le pointeur vers une cellule comme liste_chainee

*/
typedef struct cellule *liste_chainee;

/*
    Partie ii : fonctions d’accès au type

*/
liste_chainee nouvelle_lc()
{
    liste_chainee nouvelle_liste_chainee = NULL;
    return nouvelle_liste_chainee;
}

int est_vide(liste_chainee lc)
{
    return (NULL == lc);
}

/*
Appeler cette fonction seulemnt sur des Listes non vides
*/

int head(liste_chainee L)
{
    return L->contenu;
}
/*
    Appeler cette fonction seulemnt sur des Listes non vides
*/

liste_chainee tail(liste_chainee L)
{
    return L->suivant;
}

liste_chainee ajout_lc(int x, liste_chainee L)
{
    liste_chainee nouvau_head = malloc(sizeof(struct cellule));
    nouvau_head->contenu = x;
    nouvau_head->suivant = L;
    return nouvau_head;
}

/*
    J'ai utiliser une solution récursif mais je pense ca va etre probématique pour des grandes
    listes chainées
*/

void liberer_lc(liste_chainee lc)
{
    if (lc == NULL)
    {
        return;
    }
    else
    {
        liberer_lc(lc->suivant);
        free(lc);
    }
}

void test_nouvelle_lc(void)
{

    liste_chainee nlc = nouvelle_lc();
    if (est_vide(nlc))
    {
        printf("Cette liste chainé est vide\n");
    }
    else
    {
        printf("Cette liste chainée n'est pas vide\n");
    }
}

void question1(void)
{
    test_nouvelle_lc();
}
void question2(void)
{

    /*
        Test la création d'une list chainée  12 -> 4 -> NULL
    */

    int i;
    int head_nlc_valeur;
    liste_chainee tail_nlc;
    liste_chainee parcour_nlc;

    liste_chainee nlc = nouvelle_lc();
    nlc = ajout_lc(4, nlc);
    nlc = ajout_lc(12, nlc);
    printf("Test la création d'une liste chainée 12 -> 4 -> NULL \n");
    for (i = 0, parcour_nlc = nlc; parcour_nlc != NULL; parcour_nlc = parcour_nlc->suivant, i++)
    {
        printf("%d. Valeur: %d\n", i, parcour_nlc->contenu);
    }

    printf("Test head\n");
    head_nlc_valeur = head(nlc);
    printf("%d\n", head_nlc_valeur);

    printf("Test tail\n");
    tail_nlc = tail(nlc);
    printf("%d\n", tail_nlc->contenu);

    printf("Test c'est le Tail du Tail est NULL\n");
    if (est_vide(tail(tail_nlc)))
    {
        printf("La liste chainée se termine ici\n");
    }
    else
    {
        printf("Il reste encore une autre cellule\n");
    }

    liberer_lc(nlc);
}

/*
    Partie iii : utilisation de notre type

*/
void affiche_lc(liste_chainee lc)
{
    if (est_vide(lc))
    {
        printf("NULL\n");
    }
    else
    {
        printf("[%d] -> ", lc->contenu);
        affiche_lc(tail(lc));
    }
}

int longeur_lc(liste_chainee lc)
{
    if (est_vide(lc))
    {
        return 0;
    }
    else
    {
        return 1 + longeur_lc(tail(lc));
    }
}

liste_chainee copie_lc(liste_chainee lc)
{
    if (est_vide(lc))
    {
        return nouvelle_lc();
    }
    else
    {
        return ajout_lc(lc->contenu, copie_lc(tail(lc)));
    }
}
/*
    Renvoie une copie de la liste auquel un élément a été ajouté à la fin
*/
liste_chainee ajout_fin_lc(int x, liste_chainee lc)
{
    if (est_vide(lc))
    {
        return ajout_lc(x, nouvelle_lc());
    }
    else
    {
        return ajout_lc(lc->contenu, ajout_fin_lc(x, tail(lc)));
    }
}

int max_lc(liste_chainee lc)
{
    int max_tail;
    if (est_vide(lc))
    {
        return -INT_MAX - 1;
    }
    else
    {
        max_tail = max_lc(tail(lc));
        return (lc->contenu > max_tail ? lc->contenu : max_tail);
    }
}

/*
    Fonction qui prend en argumetn une liste chainée et un pointer vers une fonction int -> int
*/
liste_chainee map_lc(liste_chainee lc, int (*f)(int))
{
    if (est_vide(lc))
    {
        return nouvelle_lc();
    }

    else
    {
        return ajout_lc(f(lc->contenu), map_lc(tail(lc), f));
    }
}

void test_affiche_lc(liste_chainee lc, char *Attendue)
{
    printf("Resultat :\n");
    affiche_lc(lc);
    printf("Attendue :\n%s\n", Attendue);
}

void test_longeur_lc(liste_chainee lc, int Attendue)
{
    printf("Longeur  :");
    affiche_lc(lc);
    printf("%d\n", longeur_lc(lc));
    printf("Attendue :\n%d\n", Attendue);
}

void test_copie_lc(liste_chainee lc)
{
    liste_chainee lc_copie = copie_lc(lc);
    printf("L'adresse de la liste chainée orginal: %p\n", (void *)lc);
    affiche_lc(lc);
    printf("L'adresse de la liste chainée copié: %p\n", (void *)lc_copie);
    affiche_lc(lc_copie);
}
void test_ajout_fin_lc(int x, liste_chainee lc)
{
    liste_chainee lc_copie = ajout_fin_lc(x, lc);
    printf("L'adresse de la liste chainée orginal: %p\n", (void *)lc);
    affiche_lc(lc);

    printf("L'adresse de la liste chainée copié: %p\n", (void *)lc_copie);
    affiche_lc(lc_copie);
}

void test_max_lc(liste_chainee lc, int Attendue)
{
    printf("Maximum  :");
    affiche_lc(lc);
    printf("%d\n", max_lc(lc));
    printf("Attendue :\n%d\n", Attendue);
}

void test_map_lc(liste_chainee lc, int (*f)(int))
{
    liste_chainee lc_resultat = map_lc(lc, f);
    printf("L'adresse de la liste chainée orginal: %p\n", (void *)lc);
    affiche_lc(lc);
    printf("L'adresse de la liste chainée resultat: %p\n", (void *)lc_resultat);
    affiche_lc(lc_resultat);
}

/*
    divers fonctions pour tester map
*/
int add2(int a)
{
    return a + 2;
}
int mult2(int a)
{
    return a * 2;
}
void question3()
{

    liste_chainee nlc = nouvelle_lc();
    liste_chainee nlc_vide = nouvelle_lc();
    liste_chainee nlc_deux_elements = nouvelle_lc();

    nlc_deux_elements = ajout_lc(15, nlc_deux_elements);
    nlc_deux_elements = ajout_lc(30, nlc_deux_elements);

    nlc = ajout_lc(20, nlc);
    nlc = ajout_lc(1, nlc);
    nlc = ajout_lc(17, nlc);

    printf("Tester l'affichage\n");
    test_affiche_lc(nlc, "[17] -> [1] -> [20] -> NULL");
    test_affiche_lc(nlc_deux_elements, "[30] -> [15] -> NULL");
    test_affiche_lc(nlc_vide, "NULL");

    printf("\n");
    printf("Tester la longeur\n");

    test_longeur_lc(nlc, 3);
    test_longeur_lc(nlc_deux_elements, 2);
    test_longeur_lc(nlc_vide, 0);

    printf("\n");
    printf("Tester la copie\n");

    test_copie_lc(nlc);
    test_copie_lc(nlc_deux_elements);
    test_copie_lc(nlc_vide);

    printf("\n");
    printf("Tester l'ajout à la fin\n");

    test_ajout_fin_lc(199, nlc);
    test_ajout_fin_lc(9, nlc_deux_elements);
    test_ajout_fin_lc(0, nlc_vide);

    printf("\n");
    printf("Test le maximum\n");

    test_max_lc(nlc, 20);
    test_max_lc(nlc_deux_elements, 30);
    test_max_lc(nlc_vide, -INT_MAX - 1);

    printf("\n");
    printf("Test le map \n");

    test_map_lc(nlc, add2);
    test_map_lc(nlc, mult2);
    test_map_lc(nlc_vide, add2);
    test_map_lc(nlc_vide, mult2);
}
int main(void)
{
    printf("Partie i:============================================\n");
    question1();
    printf("======================================================\n");

    printf("Partie ii:============================================\n");
    question2();
    printf("======================================================\n");

    printf("Partie iii:============================================\n");
    question3();
    printf("======================================================\n");

    return 0;
}
