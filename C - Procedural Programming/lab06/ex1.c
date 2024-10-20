#include <stdio.h>

/*
Zamienia wartosci zajmujace n_bytes bajtow pamieci, ktorych adresy przechowuja parametry a i b.
a wskaznik do poczatku pierwszego bloku pamieci.
b wskaznik do poczatku drugiego bloku pamieci.
n_bytes liczba bajtow pamieci do zamiany.
*/

void swap(void *a, void *b, size_t n_bytes);
// swap_tab zgodną z prototypem wymieniającą zawartość tablic A oraz B (o tym samym rozmiarze n)
void swap_tab(int *A, int *B, int n);
// swap_rows zgodną z prototypem wymieniającą wiersz x z wierszem y w tablicy dwuwymiarowej TAB przy  użyciu procedury swap_tab
void swap_rows(int n, int (*TAB)[n], int x, int y);
void wypisz_i (int *poczatek, int *koniec);

int main(){
    int tab_1[4][5] = {{1,1,1,1,1},{2,2,2,2,2},{3,3,3,3,3},{4,4,4,4,4}};
    int tab_22 [5][2] = {{1,1},{2,2},{3,3},{4,4},{5,5}};
    
    int num_row_1 = sizeof(tab_1) / sizeof(*tab_1);
    int num_row_22 = sizeof(tab_22) / sizeof(*tab_22);

    int num_col_1 = sizeof(*tab_1) / sizeof(**tab_1);
    int num_col_22 = sizeof(*tab_22) / sizeof(**tab_22); 

    // przed
    printf("Wypis wierszami tablicy tab_1:\n");
    for(int w = 0; w < num_row_1; ++w){
        wypisz_i(*(tab_1+w),*(tab_1+w) + num_col_1);
    }
    printf("Wypis wierszami tablicy tab_22:\n");
    for(int w = 0; w < num_row_22; ++w){
        wypisz_i(*(tab_22+w),*(tab_22+w) + num_col_22);
    }
    printf("-----------------------------\n");
    swap_rows(num_col_1, tab_1, 0, 2);
    swap_rows(num_col_1, tab_1, 1, 3);
    swap_tab(*tab_22, *(tab_22+1), num_col_22);


    // po
    printf("Wypis wierszami tablicy tab_1:\n");
    for(int w = 0; w < num_row_1; ++w){
        wypisz_i(*(tab_1+w),*(tab_1+w) + num_col_1);
    }
    printf("Wypis wierszami tablicy tab_22:\n");
    for(int w = 0; w < num_row_22; ++w){
        wypisz_i(*(tab_22+w),*(tab_22+w) + num_col_22);
    }
    
    return 0;
}

void wypisz_i (int *poczatek, int *koniec) {
    while (poczatek < koniec)
    printf ("%4d ", *poczatek++);
    printf ("\n");
return;
}

void swap(void *a, void *b, size_t n_bytes){
    char *p_a = a;
    char *p_b = b;
    for (size_t i = 0; i < n_bytes; i++)
    {
        char temp = *p_a;
        *p_a = *p_b;
        *p_b = temp;
        p_a++;
        p_b++;
    }
}

void swap_tab(int *A, int *B, int n){
    int temp;
    for(int i = 0; i < n; ++i){
        temp = A[i];
        A[i] = B[i];
        B[i] = temp;   
    }
}

void swap_rows(int n, int (*TAB)[n], int x, int y){
    swap_tab(TAB[x], TAB[y], n);
}