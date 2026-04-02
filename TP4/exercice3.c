#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

/*
    Partie i :  création des types
*/
struct cellule
{
    struct cellule *suivant;
    int contenu;
};

typedef struct liste
{
    struct cellule *premier;
} liste;

int main(void)
{
    return 0;
}
