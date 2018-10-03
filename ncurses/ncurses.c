/* gcc -Wall -o de_logiciel de_logiciel.c -lncurses */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <curses.h>

/* cadre vide */
char cadre[10][19] = {"------------------","|                |",
"|                |","|                |","|                |","|                |",
"|                |","|                |","|                |","------------------"};

void aff_vide() {
	int j;
	/* place les chaînes en position ( 5, j ) */
	for (j=0;j<=9;j++)
		mvprintw(j, 5, cadre[j]);
}

void aff_1() {

	mvprintw(4, 13, "##");
	mvprintw(5, 13, "##");
}

void aff_2() {
	mvprintw(1, 8, "##");
	mvprintw(2, 8, "##");

	mvprintw(7, 18, "##");
	mvprintw(8, 18, "##");
}

void aff_3() {
	mvprintw(1, 8, "##");
	mvprintw(2, 8, "##");

	mvprintw(4, 13, "##");
	mvprintw(5, 13, "##");

	mvprintw(7, 18, "##");
	mvprintw(8, 18, "##");
}

void aff_4() {
	mvprintw(1, 8, "##");
	mvprintw(2, 8, "##");

	mvprintw(1, 18, "##");
	mvprintw(2, 18, "##");

	mvprintw(7, 8, "##");
	mvprintw(8, 8, "##");

	mvprintw(7, 18, "##");
	mvprintw(8, 18, "##");
}

void aff_5() {
	mvprintw(1, 8, "##");
	mvprintw(2, 8, "##");

	mvprintw(1, 18, "##");
	mvprintw(2, 18, "##");

	mvprintw(4, 13, "##");
	mvprintw(5, 13, "##");

	mvprintw(7, 8, "##");
	mvprintw(8, 8, "##");

	mvprintw(7, 18, "##");
	mvprintw(8, 18, "##");
}

void aff_6() {
	mvprintw(1, 8, "##");
	mvprintw(2, 8, "##");

	mvprintw(1, 18, "##");
	mvprintw(2, 18, "##");

	mvprintw(1, 13, "##");
	mvprintw(2, 13, "##");

	mvprintw(7, 8, "##");
	mvprintw(8, 8, "##");

	mvprintw(7, 13, "##");
	mvprintw(8, 13, "##");

	mvprintw(7, 18, "##");
	mvprintw(8, 18, "##");
}

int main(void) {

	/* fenêtre principale */
    WINDOW * mainwin;
	/* initialisation de la fenêtre */
    if ( (mainwin = initscr()) == NULL ) {
		fprintf(stderr, "Erreur d'initialisation.\n");
		exit(EXIT_FAILURE);
    }

	noecho();
	curs_set(0);

	/* tirage du dé, avec ralentissement à la fin */
	int i, k;


	srand(time(NULL)); // initialisation

	for (i=0;i<k;i++)
	{

		/* vide */
		aff_vide();
		/* valeur aléatoire */
		/* c'est ici qu'il faut procéder à l'appel de la fonction */

		mvprintw(12,2,"Tirage %d",k);

		refresh();
		usleep(((k/10)<0?1:k/10)*10000);

	}
	sleep(3);

	/* suppression des éléments créés */
    delwin(mainwin);
    endwin();
    // refresh();

	printf("Vous avez obtenu un %d\n", i+1);

	/* fin du programme sans problème */
    return EXIT_SUCCESS;
}
