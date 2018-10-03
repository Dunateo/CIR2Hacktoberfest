#include <stdio.h>
#include <math.h>
#include <string.h>

double mypow(double x){
  double y = 0;
  scanf("%lf",&y );
  return pow(x,y);

}
struct {
  char *nom;
  double (*fon)(double);
} table[] = {{"sin", sin}, {"cos", cos}, {"exp", exp}, {"log", log}, {"tan",tan},{"pow",mypow}};

#define NBF (sizeof table / sizeof table[0])

int main() {
  char nom[80];
  double x;
  unsigned int i;
  for (;;) {
    scanf("%s", nom);//fonction choisie
    if (strcmp(nom, "fin")==0) break;
    scanf("%lf", &x);
    //parcours du tableau de pointeurs de fonctions depart de la case À on avance tant que i ne deborde pas du tableau et que le afonction demandée ("nom") n'est pas éga au nom de la focntion dans table[i].nom.
    for (i=0; i<NBF && strcmp(table[i].nom, nom) != 0; i++) ;
    if (i < NBF)
      printf("%lf\n", (*table[i].fon)(x));
    else printf("%s ???\n", nom);
  }
  return 0;
}
