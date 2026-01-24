#include <stdio.h>
int lire_valeur(void) {
int taille = 0;
char c;
printf("longueur> ");
while ( (c=getchar()) != '\n' && c!= EOF ) { /* L1 */
printf("%c : %d\n", c, taille);
taille ++;
}
printf("Vous avez entré %d caractères\n", taille);
return 0;
}
int main(void) {
for (;;) lire_valeur(); /* L2 */
return 0;
}
