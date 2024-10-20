#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define M 4

// deklaracje funkcji
double rand_d(double a, double b);
double suma (double *tab, int len);
int find_min_ind (double *T_F, double *T_L);
void wypisz_d (double *poczatek, double *koniec);

int main(){
    // srand(time(NULL)); // inicjacja generatora
    double abc[N][M];

    for(int i = 0; i < N; ++i){ 
        for(int j = 0; j < M; ++j){
            abc[i][j] = rand_d(-10.0,10.0); 
        }
    }

    printf("Wypis wierszami:\n");
    for(int w = 0; w < N; ++w){
        wypisz_d(*(abc+w),*(abc+w) + M);
    }

    double suma_all = suma (*abc, M*N);
    double suma_1 = suma (*abc, M*N/2 + 1);
    double suma_2 = suma (*abc + M*N/2+1, M*N/2);

    printf("suma_all = %.4lf\n", suma_all);
    printf("suma elementow od abc[%d][%d] do abc[%d][%d] = %.4lf\n", 0,0, N/2, M*N/2 % N + 1, suma_1);
    printf("suma elementow od abc[%d][%d] do abc[%d][%d] = %.4lf\n", N/2 , M*N/2 % N + 2, N-1, M-1, suma_2);

    int MIN_IND[N];
    for(int i = 0; i < N; ++i){
        MIN_IND[i] = find_min_ind (*(abc + i), *(abc + i) + M -1);
        printf("MIN_IND wiersza %d to %d, wartosc to: %.1lf, adres to: %p\n", i, MIN_IND[i], abc[i][MIN_IND[i]], &abc[i][MIN_IND[i]]);
    }
    printf("\n");

    int min_global_id = *(abc + N - 1) + M -1 - *abc;
    int min_row = min_global_id/N + 1;
    int min_col = min_global_id % M - 1;

    printf("indeks globalny liczac od zerowych: {numer wiersza}*N + numer kolumny: %d\n",min_global_id);
    printf("abc[min_global_id/N + 1][min_global_id \% M - 1] = abc[%d][%d] = %.1lf\n",min_row, min_col, *(*(abc + min_row) + min_col)) ;

    int MIN_IND_ALL = find_min_ind (*abc, *(abc + N - 1) + M - 1);

    printf("\n");

    
return 0;
}

int find_min_ind (double *T_F, double *T_L){ //poczatek i koniec ( T_F - wskaźnik na pierwszy element, T_L wskaznik za ostatni element) obszaru tablicy gdzie szukamy minimum
    double *wsk = T_F;
    double *min = T_F++;

    while (T_F < T_L){
    if(*min > *T_F) min = T_F;
    T_F++;
    }
return (int)(min - wsk);
}

double rand_d(double a, double b){//funkcja losujaca double z przedziału <a, b>
    double r = (double)rand() / RAND_MAX;//liczba z przedziałuu <0.0, 1.0>
return r * (b - a) + a;
}


double suma (double *tab, int len) { 
  double ss = 0.0;
  for (int i = 0; i < len; i++)  
    ss+= tab[i]; 
 return ss;
 }

void wypisz_d (double *poczatek, double *koniec) {
    while (poczatek < koniec)
    printf ("%6.2g ", *poczatek++);
    printf ("\n");
return;
}