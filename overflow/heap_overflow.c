#include <stdio.h>
#include <string.h>
#include <malloc.h>

/* gcc -o heap_overflow heap_overflow.c */
/* espace occupé :
 * 
 *  watch -n 1 pmap -x `ps -ef | grep [.]/heap | awk '{print $2}'`
 *  traduction en français:
 * regarde toutes les secondes la carte mémoire du processus
 * dont le nom commence par le mot "heap"
 * 
 * */

/* fonction main */
int main(void)
{
	/* pointeur vers la première case d'un tableau
	 * de caractères */
	char *c;
	
	/* boucle qui remplit le tas, en allouant
	 * des blocs à chaque tour de boucle */
	getchar();
	// getchar() attend une saisie clavier, l'appel
	// est là uniquement pour suspendre l'exécution du
	// programme
	
	int i;
	for (i=0;i<=100; i++)
	{
		// bloc de 10 Mo
		c = malloc(10485760*sizeof(char));
		// affichage de l'adresse du premier octet
		printf("%p\n",c);
		int j;
		for (j=0; j<10485760; j++)
			*(c+j) = 'A';
		
		// libération de la mémoire allouée
		// free(c);
		// attente d'une saisie clavier avant de poursuivre
		// l'exécution
		getchar();
	}
	sleep(60);

    return 0;
}
