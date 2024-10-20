#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int i_rand(int,int);
void wypisz_i(int *, int *);
void null(int *, int *);

int main(){
    srand(time(NULL));
    size_t n;
    printf("Podaj rozmiar tablicy: "); 
    scanf("%lu", &n);
    int *table = malloc(n * sizeof(int));
    for(int i = 0; i < n; ++i)
        table[i] = i_rand(-5, 5);
    printf("table -> "); 
    null(table, table+n);
    int *table_p = NULL, *table_n = NULL;
    size_t n_p = 0, n_n = 0;
    while(n) {
        if(table[n-1] % 2 == 0) {
            table_p = realloc(table_p, (++n_p)*sizeof(int));
            table_p[n_p-1] = table[n-1];
            table = realloc(table, (--n)*sizeof(int));
        } 
        else {
            table_n = realloc(table_n, (++n_n)*sizeof(int));
            table_n[n_n-1] = table[n-1];
            table = realloc(table, (--n)*sizeof(int));
        }
    }
    printf("arg_p -> "); 
    null(table_p, table_p+n_p);
    printf("arg_n -> "); 
    null(table_n, table_n+n_n);
    printf("t -> "); 
    null(table, table+n);

    free(table);
    free(table_p);
    free(table_n);
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

void null(int *begin, int *end) {
    if(begin == end) {
        printf("NULL\n");
    } 
    else {
        wypisz_i(begin, end);
    }
}