#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

// deklaracje uzywanych funkcji
int suma (const int* begin, const int* end);
int rand_i(int a, int b);


int main(void){
    
//deklaracja tablicy 10 liczb całkowitych, użyj N
//deklaracja wskaźnika p do liczby całkowitej, użyj NULL
//nie używaj zmiennej int  do indeksowania tablicy
//przypisz kolejnym elementom tablicy liczby pseudolosowe z przedziału od 7 do 35 i wypisz je na ekran 
//skorzystaj z funkcji rand_i

int tab[N];
int* p = NULL;


for(p = tab; p < tab + N ; p++){
    *p = rand_i(7,35);  // nie korzystaj z tab 
    
//oblicz wartość indeksu kolejnych elementów tablicy, wypisz wartości kolejnych elementów używając p


    printf("p[%d] = %d\n", p - tab, *p);
}

printf("\n");
// printf("%d", (int)(p-tab));

//oblicz rekurencyjnie sumę elementów tablicy.

int su = suma(tab, p);   //nie używaj N

printf("su=%d\n",su);
return 0;
}

//funkcja rekurencyjna liczaca sume elementów tablicy  
// begin, end - odpowiednio wskaznik na poczatek i koniec tablicy
int suma (const int* begin, const int* end){   //nie używaj N 
int* temp = (int*)begin;
    if (temp < end)
return *temp + suma(temp + 1, end);
    else
return *temp;
}


int rand_i(int a, int b){//funkcja losujaca integery z zakresu <a, b>
return (a + rand()%(b-a+1));}