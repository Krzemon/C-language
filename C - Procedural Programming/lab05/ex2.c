#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int rand_i(int a, int b);
void wypisz_i (int *poczatek, int *koniec);


int main(){

    int* table = malloc(N*sizeof(int));
    if(!table){printf("Brak pamieci!;\n"); return -1;}
    for(int i = 0; i < N; ++i){
        table[i] = rand_i(-5, 5);
    }
    printf("wylosowana tablica:\n");
    wypisz_i(table, table + N);

    int* arg_p = NULL;
    int* arg_n = NULL;

    int num_p = 0;
    int num_n = 0;

    for(int i = 0; i < N; ++i){
        if(table[i] % 2 == 0){
            ++num_p;
            arg_p = realloc(arg_p, num_p*sizeof(int));
            arg_p[num_p-1] = table[i];
        }
        else{
            ++num_n;
            arg_n = realloc(arg_n, num_n*sizeof(int));
            arg_n[num_n-1] = table[i];
        }
    }

    printf("tablica arg_p:\n");
    wypisz_i(arg_p, arg_p + num_p);

    printf("tablica arg_n:\n");
    wypisz_i(arg_n, arg_n + num_n);

    free(table);
    free(arg_p);
    free(arg_n);
    return 0;
}


int rand_i(int a, int b){//funkcja losujaca integery z zakresu <a, b>
return (a + rand()%(b-a+1));}

void wypisz_i (int *poczatek, int *koniec) {
    while (poczatek < koniec)
    printf ("%4d ", *poczatek++);
    printf ("\n");
return;}