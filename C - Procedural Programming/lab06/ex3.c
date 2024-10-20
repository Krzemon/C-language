#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 7

void wypisz_d (double *poczatek, double *koniec);
double rand_d(double a, double b);
double *find_min_wsk (double *T_F, double *T_L);
double **find_min_wsk_wsk (double **TAB, int n);
void move(double** WSK);


int main(){
    double TAB_2[N];
    double* TAB_1[N];
    double** WSK, **WSK_1;

    for (int i = 0; i<N; ++i){
        TAB_2[i] = rand_d(-5.0, 5.0);
        TAB_1[i] = &TAB_2[i];
    }

    WSK = TAB_1;
    WSK_1 = TAB_1;

    printf("Wynik\n");
    printf("TAB_2 -->");
    wypisz_d(*WSK,*WSK + N);
    printf("\n");
    for(int i = 0; i < N; ++i){
        printf("TAB_1[%d] = %p\n", i, *WSK+i);
    }
    printf("---------------------\n");

    double** indx = find_min_wsk_wsk (TAB_1, N);
    printf("minimum =  %6.2lf indeks = %d adres = %p\n", **indx, *indx - *WSK, **indx);
    printf("---------------------\n");

    move(WSK);

    printf("Wynik\n");
    printf("TAB_2 -->");
    wypisz_d(*WSK,*WSK + N);
    printf("\n");
    for(int i = 0; i < N; ++i){
        printf("TAB_1[%d] = %p\n", i, *WSK+i);
    }
    printf("---------------------\n");

    return 0;
}

void wypisz_d (double *poczatek, double *koniec) {
    while (poczatek < koniec)
    printf ("%6.2lf ", *poczatek++);
    printf ("\n");
return;
}

double rand_d(double a, double b){//funkcja losujaca double z przedziału <a, b>
    double r = (double)rand() / RAND_MAX;//liczba z przedziałuu <0.0, 1.0>
    return r * (b - a) + a;
}

double *find_min_wsk (double *T_F, double *T_L){ //poczatek i koniec ( T_F - wskaźnik na pierwszy element, T_L wskaznik za ostatni element) obszaru tablicy gdzie szukamy minimum
    double *min = T_F++;
    while (T_F < T_L){
        if(*min > *T_F) min = T_F;
        T_F++;
    }
return min;
}

double **find_min_wsk_wsk (double **TAB, int n){ 
    int x = find_min_wsk (*TAB, *TAB + n) - *TAB;
    return TAB + x;
}


void move(double** WSK){
    double* temp = WSK[0];
    for(int i = 0; i < N-1; ++i){
        WSK[i] = WSK[i+1];
    }
    WSK[N-1] = temp;
}


