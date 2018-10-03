#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* gcc -o stack_overflow stack_overflow.c */

/* sous Linux */
/* ulimit -a : taille de la pile
   ulimit -s 32768 : fixe la taille de la pile,
   plus d'appels récursifs qu'avec la valeur par défaut
   ulimit -Ha affiche les tailles maximales des paramètres du système.

Il est possible de modifier ces valeurs en fonction des utilisateurs.
*	-	stack	65536
dans /etc/security/limits.conf
modifiera la taille de la pile pour tous les utilisateurs, sauf pour root,
qui peut fixer n'importe quelle taille.

*/

/* la fonction rec se rappelle elle-même jusqu'au débordement
 * de la pile */
int rec(int rappel) {
	/* tableau inutile */
	int tab[10];

	/* adresse du tableau */
	//printf("%p\r", tab);

	/* temps de lire les informations */
	// sleep(1);

	/* rappel récursif */
	printf("%d\r\n", rappel);
	rec(rappel+1);

	return 0;
}

int main(void)
{
	rec(1);
    return 0;
}
