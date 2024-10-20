#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int rand_i(int a, int b);
void wypisz_i (int *poczatek, int *koniec);
int** create_table(int rows_num, int** TAB);


int main(){

    int rows_num = rand_i(3, 7);
    int** tab_wsk = NULL;
    tab_wsk = create_table(rows_num, tab_wsk);

    printf ("\n---------------przy pomocy procedury---------------\n");
    for(int i = 0; i < rows_num; ++i){
        wypisz_i(*(tab_wsk+i), *(tab_wsk+i)+i+1);
    }

    printf ("\n---------------przy pomocy tablicy---------------\n");
    for(int i = 0; i < rows_num; ++i){
        for(int j = 0; j < i+1; ++j){
            printf ("%4d ", tab_wsk[i][j]);
        }
        printf ("\n");
    }

    printf ("\n-----------------------------\n");

    for(int i = 0; i < rows_num; ++i){
        free(tab_wsk[i]);
    }

    int rows_num_new = rand_i(2, 8);
    tab_wsk = create_table(rows_num_new, tab_wsk);

    printf ("\n---------------przy pomocy procedury---------------\n");
    for(int i = 0; i < rows_num; ++i){
        wypisz_i(*(tab_wsk+i), *(tab_wsk+i)+i+1);
    }

    printf ("\n---------------przy pomocy tablicy---------------\n");
    for(int i = 0; i < rows_num; ++i){
        for(int j = 0; j < i+1; ++j){
            printf ("%4d ", tab_wsk[i][j]);
        }
        printf ("\n");
    }

    for(int i = 0; i < rows_num_new; ++i){
        free(tab_wsk[i]);
    }

    return 0;
}

void wypisz_i (int *poczatek, int *koniec) {
    while (poczatek < koniec)
    printf ("%4d ", *poczatek++);
    printf ("\n");
return;}

int rand_i(int a, int b){//funkcja losujaca integery z zakresu <a, b>
return (a + rand()%(b-a+1));}

// int** create_table(int rows_num){
//     int** TAB = malloc(rows_num * sizeof(int*));
//     for(int i = 0; i < rows_num; ++i){
//         TAB[i] = malloc(i+1 * sizeof(int));
//         for(int j = 0; j < i+1; ++j){
//             TAB[i][j] = i+1;
//         }
//     }
//     return TAB;
// }

int** create_table(int rows_num, int** TAB){
    TAB = realloc(TAB, rows_num * sizeof(int*));
    
    for(int i = 0; i < rows_num; ++i){
        TAB[i] = calloc(i+1, (i+1)* sizeof(int));
        for(int j = 0; j < i+1; ++j){
            TAB[i][j] = i+1;
        }
    }
    return TAB;
}