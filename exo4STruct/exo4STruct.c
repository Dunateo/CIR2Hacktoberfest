#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "exo4STruct.h"

int main() {
  s valeurs;
  u un;
  valeurs.c = 3;
  valeurs.s = 356;
  valeurs.i = 3563256;
  un.c = 3;
  un.s = 356;
  un.i = 3563256;
  printf("%c\n", valeurs.c);
  printf("%d\n",valeurs.i );
  printf("%hd\n", valeurs.s);
  return 0;
}
