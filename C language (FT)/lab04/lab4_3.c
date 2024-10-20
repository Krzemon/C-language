#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 10
#define N 10

int i_rand(int, int);
void wypisz_i (int *, int *);
int find_min_ind (int *, int *);
int* tab_min(int t[][M], int);
int row_number(int t[][M], int);


int main(void){
    srand(time(NULL));
    int TAB[N][M];
    for(int i = 0, *p = *TAB; i < N*M; ++i, ++p)
        *p = i_rand(-5, 5);
    for(int i = 0; i < N; ++i)
        wypisz_i(TAB[i], TAB[i+1]);
    int *ind_min = tab_min(TAB, N);

    printf("ind_min -> "); wypisz_i(ind_min, ind_min+N);
    
    int mv = TAB[0][ind_min[0]];
    for(int i = 1; i < N; ++i)
        if(mv > TAB[i][ind_min[i]])
            mv = TAB[i][ind_min[i]];
    printf("minimum w całej: %d\n", mv);
    free(ind_min);
    
    int min_w = row_number(TAB, N);
    printf("element minimalny w wierszu o indeksie: %d\n", min_w);
    wypisz_i(TAB[min_w], TAB[min_w+1]);
    
    return 0;
}


int i_rand(int min, int max){
    return rand() % (max-min+1) + min;
}
void wypisz_i (int *poczatek, int *koniec) { 
    while (poczatek < koniec) 
    printf ("%4d ", *poczatek++);   
    printf ("\n");    
return;}

int find_min_ind (int *T_F, int *T_L){  // begin end
    int min = 0;
    for (int i = 1; i < T_L - T_F; i++)
        if(T_F[min] > T_F[i]) min = i;
return min;}

int* tab_min(int t[][M], int n) {
    // tablica przechowująca indeksy wartości minimalnych w poszczególnych wierszach tablicy,
    int *r = malloc(n * sizeof(int));
    for(int i=0; i < n; ++i)
        r[i] = find_min_ind(t[i], t[i+1]);
    return r;
}
int row_number(int t[][M], int n) {
    // numer wiersza, w którym znajduje się minimalny  element w przekazanej do funkcji tablicy dwuwymiarowej o wierszach  długości  N,
    int *ind_min = tab_min(t, N);
    int mv = t[0][ind_min[0]], mi = 0;
    for(int i = 1; i < n; ++i)
        if(mv > t[i][ind_min[i]])
            mv = t[i][ind_min[i]], mi = i;
    free(ind_min);
    return mi;
}
