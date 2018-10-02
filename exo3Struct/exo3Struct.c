#include <stdio.h>
#include <stdlib.h>
#include "exo3Struct.h"

int main() {

  S s1,s2;
  S *ptrs1, *ptrs2;
  s2.e = 3;
  s2.f = 4.0;
  ptrs1 = &s1;
  ptrs2 = &s2;
  printf("%d\n",s2.e );
  printf("%f\n",s2.f);
  printf("%p\n",ptrs1 );
  printf("%p\n",ptrs2 );
  echangeValeursStructs(&s1, &s2);
  echangeValeursPtrStructs(&ptrs1, &ptrs2);
  printf("%p\n",ptrs1 );
  printf("%p\n",ptrs2 );
  printf("%d\n",s2.e );
  printf("%f\n",s2.f);
  return 0;
}

void echangeValeursPtrStructs(S **ptrs1, S **ptrs2){

  S *ptrr;
  ptrr = *ptrs1;
  (*ptrs1) = (*ptrs2);
  (*ptrs2) = ptrr;



}
void echangeValeursStructs(S *s1, S *s2){
  int inter;
  float interr;
  inter = s2->e ;
  interr =  s2->f;
  s2->e = s1->e;
  s2->f = s1->f;
  s1->e =inter;
  s1->f = interr;

}
