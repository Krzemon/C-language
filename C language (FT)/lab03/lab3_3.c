#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define M 4

int i_rand(int , int );
void wypisz_i(int *, int *);


int main() {
  srand(time(NULL));
  int tab[N][M];

  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < M; ++j)
      tab[i][j] = i_rand(-10, 10);
  }
    
  int (*wsk)[M] = tab+2; // wskaznik na tablice o M kolumnach
  wsk -= 2; // cofnięcie na początek tablicy, żeby wyzerować całą kolumnę
  //wersja tablicowa
  for(; wsk < tab+N; ++wsk) {
    for(int i = 0; i < M; i += 2) {
      (*wsk)[i] = 0;
    }
    wypisz_i(*wsk, *(wsk+1)); 
  }
    
  printf("\n");
  wsk = tab;
  //wersja wskaznikowa
  for(; wsk < tab+N; ++wsk) {
    for(int i = 0; i < M; i += 2) {
      *(*wsk + i) = 0;
    }
    wypisz_i(*wsk, *(wsk+1)); 
  }
  return 0;
}


int i_rand(int min, int max){
    return rand() % (max-min+1) + min;
}
void wypisz_i (int *poczatek, int *koniec) { 
  while (poczatek < koniec) 
    printf ("%4d ", *poczatek++);   
  printf ("\n");    
}