#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5
#define M 4

int i_rand(int,int);
double d_rand(double,double);
void wypisz_d(double *, double *);
void wypisz_i(int *, int *);
int suma(int *, int);
int find_min_ind(int *, int *);

int main(){
  srand(time(NULL));
  int abc[N][M];
  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < M; ++j)
        abc[i][j] = i_rand(-10, 10);
      wypisz_i(abc[i], abc[i+1]);
  }
  int suma_all = suma(*abc, N*M);
  int *abc2 = *abc + N*M/2;
  int suma_1 = suma (*abc, N*M/2);
  int suma_2 = suma (abc2, N*M/2);
  printf("Suma elementow calej tablicy: %d\n",suma_all);
  printf("Suma elementow pierwszej polowy tablicy: %d\n",suma_1);
  printf("Suma elementow drugiej polowy tablicy: %d\n",suma_2);
    
  int MIN_IND_1 = find_min_ind(*abc, abc2);
  int MIN_IND_2 = find_min_ind(abc2, *(abc + N));
  int *min_1 = *abc + MIN_IND_1;
  int *min_2 = abc2 + MIN_IND_2;
  printf("min1: wartosc = %d adres = %p\n", *min_1, min_1);
  printf("min2: wartosc = %d adres = %p\n", *min_2, min_2);
  int ming1 = min_1 - *abc;
  int ming2 = min_2 - *abc;
    
  printf("min1: wiersz = %d kolumna = %d \n", ming1/M, ming1%M);
  printf("min2: wiersz = %d kolumna = %d \n", ming2/M, ming2%M);
    
return 0;
}

int i_rand(int min, int max){
  return rand() % (max-min+1) + min;
}

double d_rand(double min, double max){
  double r = (double) rand()/RAND_MAX;
  return r*(max-min) + min;
}

void wypisz_d (double *poczatek, double *koniec) { 
  while (poczatek < koniec) 
    printf ("%6.2f", *poczatek++); 
  printf ("\n");    
}

void wypisz_i (int *poczatek, int *koniec) { 
  while (poczatek < koniec) 
    printf ("%4d ", *poczatek++);   
  printf ("\n");    
}

int suma (int *tab, int len) { 
  int ss = 0;
  for (int i = 0; i < len; i++)  
    ss+= tab[i]; 
  return ss;
}

int find_min_ind (int *T_F, int *T_L){
  int min = 0;
  for (int i = 1; i < T_L - T_F; i++)
    if(T_F[min] > T_F[i]) min = i;
  return min;
}
