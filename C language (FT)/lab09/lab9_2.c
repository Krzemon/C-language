#include <stdio.h>
#include <stdlib.h>

void wypisz_i(int *poczatek, int *koniec);
int porownaj(const void *a , const void *b );
int find (int k, int t[][k], int w, int q);

int main(void) {
    int tab_A[3][6] = {{1,-4,1,2,11},{12,2,32,2},{72,2,-32,2}};
    int tab_B[4][3] = {{1,-24,1},{9,32,2},{5,64,1},{3,32,1}};

    int c;
    if((c = find(6, tab_A, 3, 1)) == -1) {
        printf("Nie znaleziono %d.\n", 1);
    } else {
        printf("Znaleziono %d w %d-tym wierszu:\n", 1, c);
        wypisz_i(tab_A[c], tab_A[c+1]);
    }
    if((c = find(3, tab_B, 4, -24)) == -1) {
        printf("Nie znaleziono %d.\n", -24);
    } else {
        printf("Znaleziono %d w %d-tym wierszu:\n", -24, c);
        wypisz_i(tab_B[c], tab_B[c+1]);
    }
}

void wypisz_i(int *poczatek, int *koniec) { 
  while (poczatek < koniec) 
    printf ("%4d ", *poczatek++);   
  printf ("\n");    
  return;}

int porownaj(const void *a , const void *b ){
    return *(int*)a - *(int*)b;
}

int find(int k, int t[][k], int w, int q){
  for(int i = 0; i < w; ++i)
    qsort(t[i], k, sizeof(int), porownaj);
  for(int i = 0; i < w; ++i)
    if(bsearch(&q, t[i], k, sizeof(int), porownaj) != NULL)
      return i;
  return -1;
}