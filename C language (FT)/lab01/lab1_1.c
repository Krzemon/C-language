#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

int suma(const int*,const int*);

int main(void){
  int tab[N];
  int* p=NULL;
  for(p=tab; p <tab + N ; p++){
    *p=rand()%(35-7+1)+7; //range: [7;35]
    printf("p[%d] = %d\n", (int)(p-tab), *p);
  }
  printf("\n");
  int su = suma(p, tab);
  printf("su=%d\n",su);
  return 0;
}

//Recursive function counting the sum of the array elements 
int suma (const int* A, const int* B){
    if (A--!=B)
      return *A + suma(A,B);
    else
      return 0;
}
