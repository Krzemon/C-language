#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define M 4

// deklaracje funkcji
int rand_i(int a, int b);
void wypisz_i (int *poczatek, int *koniec);

int main(){

    int TAB[N][M];
    int (*wsk)[M];
    wsk = TAB + 3;
    
    for(int i = 0; i < N; ++i){ 
        for(int j = 0; j < M; ++j){
            TAB[i][j] = rand_i(-5,5); 
        }
    }

    printf("Wypis wierszami przed wyzerowaniem:\n");
    for(int w = 0; w < N; ++w){
        wypisz_i(*(TAB+w),*(TAB+w) + M);
    }
// ----------------------- wskazniki ---------------------------
    
    // int row_to_clear[N/2];
    // int row_step = 0, idx = 0;
    // do{
    //     row_to_clear[idx++] = row_step;
    //     row_step += 2;
    // }while(row_step < N);

    for(int row = 0; row < N; row += 2){
        for(int col = 0; col < M; ++col){
            *(*(wsk - 3 + row) + col) = 0;
        }
    }

    printf("Wypis wierszami po wyzerowaniu parzystych wierszy wskaznikiem wsk:\n");
    for(int w = 0; w < N; ++w){
        wypisz_i(*(TAB+w),*(TAB+w) + M);
    }

// ------------------------ tablice  --------------------------

    for(int row = 1; row < N; row += 2){
        for(int col = 0; col < M; ++col){
            TAB[row][col] = 0;
        }
    }

    printf("Wypis wierszami po wyzerowaniu nieparzystych wierszy tablica TAB:\n");
    for(int w = 0; w < N; ++w){
        wypisz_i(*(TAB+w),*(TAB+w) + M);
    }


return 0;
}


int rand_i(int a, int b){//funkcja losujaca integery z zakresu <a, b>
return (a + rand()%(b-a+1));
}

void wypisz_i (int *poczatek, int *koniec) {
    while (poczatek < koniec)
    printf ("%2d, ", *poczatek++);
    printf ("\n");
return;
}