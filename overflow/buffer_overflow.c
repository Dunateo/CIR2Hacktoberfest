#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* gcc -o buffer_overflow buffer_overflow.c */

/* Pour les couleurs du bash: https://wiki.archlinux.org/index.php/Color_Bash_Prompt */

/* Plus compliqué:
 * exploration du format objet ELF: sudo apt-get install elfutils
 * readelf, objdump peuvent être utilisés également 
 * */

/* variables dans la zone statique */
/* tampon mémoire de 5 cases de 1 octet chacune indexées de 0 à 4*/
/* booléen qui indique que l'identification a échoué */
/* pour être sûr qu'ils soient côté à côté, on les encapsule dans une structure */

struct {
	char buff[5];
	bool pass;
} securite;
 
int main(void)
{    
	/* le mot de passe est faux par défaut */
	securite.pass = false;
	
    printf("Adresses des cases du tableau et de la variable pass:\n");
    int i;
    for (i=0;i<5;i++)
		/* affichage de l'indice et de l'adresse de la case du tableau */
		printf("buff[%d] : %p\n",i, &(securite.buff[i]));
		/* ce code repousse les vampires */
		
	/* affichage de l'adresse de la variable pass */
	printf("Adresse de pass : %p\n",&(securite.pass));
	
	/*	  
	buff[0] : 0x7fff4d358010
	buff[1] : 0x7fff4d358011
	buff[2] : 0x7fff4d358012
	buff[3] : 0x7fff4d358013
	buff[4] : 0x7fff4d358014
	pass    : 0x7fff4d35801c

	pass - buff[4] = 8 octets, donc en écrasant les 8 valeurs qui suivent,
	pass voit sa valeur changée
	*/

	/* le mot de passe vaut false, car l'utilisateur n'est pas encore
	 * identifié */
	printf("Valeur de pass avant saisie: %d\n",securite.pass);
    printf("Veuillez saisir le mot de passe (5 lettres maximum):\n");
    
    /* GCC indique "warning: the gets function is dangerous and
     * should not be used", car gets
     * copie des données sans se préoccuper de leur taille. */
    gets(securite.buff);

	/* normalement, le mot de passe n'ayant pas encore été testé,
	 * l'identification n'est pas effective, donc pas vaut toujours false */
	printf("Valeur de pass après saisie: %d\n",securite.pass);

	/* STRingCoMPare va comparer le contenu de buff au mot de passe
	 * attendu, qui est cir2, si elle renvoie zéro, les deux chaînes
	 * sont identiques, donc le test échoue, et on affiche
	 * le message contenu dans le else */
    if(strcmp(securite.buff, "cir2"))
    {
		/* si la comparaison échoue */
        printf("Mot de passe KO!\n");
    }
    else
    {
		/* sinon l'utilisateur est correctement authentifié */
        printf ("Mot de passe OK!\n");
        securite.pass = true;
    }

	/* si le mot de passe a été validé, pass vaut true */
    if(securite.pass)
    {
       /* utilisateur authentifié */
        printf ("\e[1;32mAccès autorisé.\e[0m\n");
    }
    else
    {
       /* utilisateur non authentifié */
        printf ("\e[1;31mAccès interdit.\e[0m\n");
    }

    return 0;
}

/*
Exemple d'exécutions normales:
Adresses des cases du tableau et de la variable pass:
buff[0] : 0x601040
buff[1] : 0x601041
buff[2] : 0x601042
buff[3] : 0x601043
buff[4] : 0x601044
Adresse de pass : 0x601045
Valeur de pass avant saisie: 0
Veuillez saisir le mot de passe (5 lettres maximum):
12345
Valeur de pass après saisie: 0
Mot de passe KO!

Adresses des cases du tableau et de la variable pass:
buff[0] : 0x601040
buff[1] : 0x601041
buff[2] : 0x601042
buff[3] : 0x601043
buff[4] : 0x601044
Adresse de pass : 0x601045
Valeur de pass avant saisie: 0
Veuillez saisir le mot de passe (5 lettres maximum):
cir2
Valeur de pass après saisie: 0
Mot de passe OK!
Accès autorisé.

-------------------------------------------------------

Exemple d'exécution avec exploitation du débordement:
Adresses des cases du tableau et de la variable pass:
buff[0] : 0x601040
buff[1] : 0x601041
buff[2] : 0x601042
buff[3] : 0x601043
buff[4] : 0x601044
Adresse de pass : 0x601045
Valeur de pass avant saisie: 0
Veuillez saisir le mot de passe (5 lettres maximum):
123456789
Valeur de pass après saisie: 54
Mot de passe KO!
Accès autorisé.


*/





/* Notez que si vous tentez un débordement dans la pile, comme
 * le placement des variables (hors utilisation de struct) dans la pile n'est pas imposé,
 * rien ne garantit que le débordement attendu se produira. */
