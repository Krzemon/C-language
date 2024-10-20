#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

const int n = 10;

// deklaracje uzywanych funkcji
void swap(int*a, int*b);
int* find_min_wsk (int * begin, int* end);
void print_ten(int tab[], int * wsk);
void sort (int *tab, int x);
void wypisz_i (int *poczatek, int *koniec);

int main(){

    int tab_A[] = {5,33,1,7,9,55,1,11,22,12,6,8,4,44,6,42,2,8,26,64,80,22,12,6,8,4,44,6,42,2,16,5,33,1,7,9,55,1,11,22,34,78,11,21,9,12,5,3,9};
    int size_tab_A = sizeof(tab_A) / sizeof(tab_A[0]);
    int num_tens = size_tab_A / n + 1; // liczba zakresow 
    int * p[num_tens];
    int i = 0;

    int poczatek = 0;
    int koniec = size_tab_A;

    // zadanie 1
    int* min = find_min_wsk(&tab_A[poczatek], &tab_A[koniec]);

    printf("min dla zakresu: tab_A[%d] - tab_A[%d] to %d\n\n", poczatek, koniec, *min);

    // zadanie 2
    int k = 4; // element tablicy od ktorego iterujemy
    int* wsk = tab_A + k;
    print_ten(tab_A, wsk);
    printf("\n");

    // zadanie 3
    for(int i = 0; i < num_tens; ++i){

        poczatek = i*n;
        koniec = i*n + 9;
        if (koniec > size_tab_A)
            koniec = size_tab_A;
            
        if(poczatek < size_tab_A){
            min = find_min_wsk(&tab_A[poczatek], &tab_A[koniec]);

            print_ten(tab_A, tab_A + poczatek);
            printf("element minimalny ma wartosc = %d, ",*min);
            printf("adres = %p, indeks = %d\n", min, min - tab_A);        
        }

    }
    printf("\n");
    
    // zadanie 4,5
    sort(tab_A, 10);

    wypisz_i (tab_A, &tab_A[size_tab_A-1]);

return 0;
}

void swap(int*a, int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
return;}


int* find_min_wsk (int * begin, int* end){
    int* temp = begin;
    int* MIN = begin;
    while (++temp < end){
        if (*temp < *MIN)
            MIN = temp;
    }
return MIN; 
}

void print_ten(int tab[], int* wsk){
    int temp = wsk - tab;
    printf("zakres %d - %d -->\n", temp, temp + n - 1);
    for(int j = 0; j < n; ++j){
        printf(" tab[%d] = %d,", temp + j, tab[temp + j]);
    }
    printf("\n");
}

void sort (int *tab, int x){
    for(int i = 0; i < x; ++i){
        for(int j = 0; j < x; ++j){
            if(tab[j] > tab[j+1])
                swap(&tab[j], &tab[j+1]);
        }
    }

}

void wypisz_i (int *poczatek, int *koniec) { 
    while (poczatek < koniec) 
    printf ("%4d ", *poczatek++);   
printf ("\n");    
return;}