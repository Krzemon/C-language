#include <stdio.h>

int suma (int *tab, int len);
void swap(void *a, void *b, size_t n_bytes);
void swap_tab(int *A, int *B, int n);
void swap_rows(int n, int (*TAB)[n], int x, int y);
void selection_sort(int n, int (*TAB)[n], int row);
void wypisz_i (int *poczatek, int *koniec);

int main(){
    int tab_A[4][6] = {{1,-4,1,2,11},{12,2,2},{72,2,-32,2}};
    int tab_B[5][3] = {{1,-24,1},{9,32,2},{5,64,1},{3,32,1},{1,-1,2}};
    
    int num_row_A = sizeof(tab_A) / sizeof(*tab_A);
    int num_row_B = sizeof(tab_B) / sizeof(*tab_B);

    int num_col_A = sizeof(*tab_A) / sizeof(**tab_A);
    int num_col_B = sizeof(*tab_B) / sizeof(**tab_B); 

    // przed
    printf("Wypis wierszami tablicy tab_A:\n");
    for(int w = 0; w < num_row_A; ++w){
        wypisz_i(*(tab_A+w),*(tab_A+w) + num_col_A);
    }
    printf("Wypis wierszami tablicy tab_B:\n");
    for(int w = 0; w < num_row_B; ++w){
        wypisz_i(*(tab_B+w),*(tab_B+w) + num_col_B);
    }
    printf("-----------------------------\n");
    // petla iteracyjna przez wiersze
    selection_sort(num_col_A, tab_A, num_row_A);
    selection_sort(num_col_B, tab_B, num_row_B);

    

    // po
    printf("Wypis wierszami tablicy tab_A:\n");
    for(int w = 0; w < num_row_A; ++w){
        wypisz_i(*(tab_A+w),*(tab_A+w) + num_col_A);
    }
    printf("Wypis wierszami tablicy tab_B:\n");
    for(int w = 0; w < num_row_B; ++w){
        wypisz_i(*(tab_B+w),*(tab_B+w) + num_col_B);
    }

    return 0;
}

int suma (int *tab, int len) {
    int ss = 0.0;
    for (int i = 0; i < len; i++)
    ss+= tab[i];
return ss;
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

void selection_sort(int n, int (*TAB)[n], int row){
    int temp;
    int min_sum;
    int min_row;
    for(int w = 0; w < row; ++w){
        min_row = w;
        min_sum = suma(TAB[w], n);
        for (int i = w+1; i < row; ++i){
            temp = suma(TAB[i], n);
            if (temp < min_sum){
                min_row = i;
                min_sum = temp;
            }
            if (w != min_row)
                swap_rows(n, TAB, w, min_row);   
        }   
    }
}


void wypisz_i (int *poczatek, int *koniec) {
    while (poczatek < koniec)
    printf ("%4d ", *poczatek++);
    printf ("\n");
return;
}