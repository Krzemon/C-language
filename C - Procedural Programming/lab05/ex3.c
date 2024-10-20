#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 5 // kolumny
#define N 5 // wiersze

int find_min_ind (int *T_F, int *T_L);
int rand_i(int a, int b);
void wypisz_i (int *poczatek, int *koniec);
int* tab_min(int (*TAB)[M], int row_num);
int* row_number(int (*TAB)[M], int row_num);


int main(){

    int min = -5;
    int max = 5;

    int TAB[N][M];
    printf("wylosowana tablica:\n");
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            TAB[i][j] = rand_i(min, max);
        }
        wypisz_i(TAB[i], TAB[i] + M);
        printf("\n");
    }

    printf("Minimalne indeksy (0 - M-1)\n");
    printf("-----------------------------\n");

    int* MIN_ID = tab_min(TAB, N);
    wypisz_i(MIN_ID, MIN_ID + N);
    printf("-----------------------------\n");

    int global_min = max + 1;
    int row, col;
    for(int i = 0; i < N; ++i){
        if(TAB[i][MIN_ID[i]] < global_min){
            global_min = TAB[i][MIN_ID[i]];
            row = i;
            col = MIN_ID[i];
        }
    }

    printf("minimalna wartosc tablicy to TAB[%d][%d]: %d\n", row, col, global_min);

    printf("-----------------------------\n");

    int* min_row_wsk = row_number(TAB, N);

    printf("elemenry wiersza o indeksie %d w ktorym to znajduje sie minimalny element to:\n", *min_row_wsk);

    wypisz_i(TAB[*min_row_wsk], TAB[*min_row_wsk] + M);

    free(MIN_ID);
    return 0;
}

int find_min_ind (int *T_F, int *T_L){ //poczatek i koniec ( T_F - wskaznik na pierwszy element, T_L wskaznik za ostatni element ) obszaru tablicy gdzie szukamy minimum
    int min = 0;
    for (int i = 1; i < T_L - T_F; i++)
    if(T_F[min] > T_F[i]) min = i;
return min;
}


int* tab_min(int (*TAB)[M], int row_num){

    int* min_id = malloc(row_num * sizeof(int));
    int xd = 0;
    while(xd < row_num){
        min_id[xd] = find_min_ind(TAB[xd], TAB[xd] + M);
        ++xd;
    }

    return min_id;
}

int* row_number(int (*TAB)[M], int row_num){
    row_num = find_min_ind(TAB[0],TAB[0] + row_num*M) / N;
    int* wsk = &row_num;
    return wsk;
}

int rand_i(int a, int b){//funkcja losujaca integery z zakresu <a, b>
return (a + rand()%(b-a+1));}

void wypisz_i (int *poczatek, int *koniec) {
    while (poczatek < koniec)
    printf ("%4d ", *poczatek++);
    printf ("\n");
return;}