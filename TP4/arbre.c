#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
struct arbre_struct
{
    struct arbre_struct *gauche;
    struct arbre_struct *droite;
    int racine;
};
typedef struct arbre_struct *arbre;
int est_entier(arbre a)
{
    return (a->gauche == NULL && a->droite == NULL);
}
arbre entier(int i)
{
    arbre a = malloc(sizeof(struct arbre_struct));
    a->gauche = NULL;
    a->droite = NULL;
    a->racine = i;
    return a;
}
arbre expression(int i, arbre exp1, arbre exp2)
{
    arbre a = malloc(sizeof(struct arbre_struct));
    a->gauche = exp1;
    a->droite = exp2;
    a->racine = i;
    return a;
}
int calcul(int operation, int x, int y)
{
    switch (operation)
    {
    case '+':
        return x + y;
    case '-':
        return x - y;
    case '*':
        return x * y;
    case '/':
        return x / y;
    default:
        fprintf(stderr, "Calcul non autorisé\n");
        exit(1);
    }
}
int valeur(arbre expr)
{
    int gauche;
    int droite;
    if (est_entier(expr))
    {
        return expr->racine;
    }
    else
    {
        gauche = valeur(expr->gauche);
        droite = valeur(expr->droite);
        return calcul(expr->racine, gauche, droite);
    }
}

void bucheron(arbre expr)
{
    if (est_entier(expr))
    {
        free(expr);
    }
    else
    {
        bucheron(expr->gauche);
        bucheron(expr->droite);
        free(expr);
    }
}

int main(void)
{
    arbre e1 = entier(3);
    arbre e2 = entier(5);
    arbre a1 = expression('+', e1, e2);
    arbre a2 = expression('*', a1, entier(10));
    printf("e1=%d\n", valeur(e1)); /* affiche 3 */
    printf("e2=%d\n", valeur(e2)); /* affiche 5 */
    printf("a1=%d\n", valeur(a1)); /* affiche 8 */
    /* bucheron(a1); cause une erreur ligne suivante*/
    printf("a2=%d\n", valeur(a2)); /* affiche 80 */
    bucheron(a2);
    return 0;
}
