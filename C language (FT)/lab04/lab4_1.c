#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double d_rand(double, double);
void wypisz_d (double *, double *);
void wypelnij(double t[][6], int);

int main(){
    srand(time(NULL));
    double A_1[8][6], A_2[10][6];
    wypelnij(A_1, 8);
    wypelnij(A_2, 10);

    wypisz_d(*A_1, *(A_1+8));
    printf("\n\n");
    for(int i = 0; i < 8; ++i)
        wypisz_d(A_1[i], A_1[i+1]);
    printf("\n\n");

    wypisz_d(*A_2, *(A_2+10));
    printf("\n\n");
    for(int i = 0; i < 10; ++i)
        wypisz_d(A_2[i], A_2[i+1]);
    printf("\n\n");
    return 0;
}


double d_rand(double min, double max){
    double r = (double) rand()/RAND_MAX;
    return r*(max-min) + min;
}

void wypisz_d (double *poczatek, double *koniec) {
    while (poczatek < koniec) 
        printf ("%6.2f", *poczatek++); 
    printf ("\n");    
return;}

void wypelnij(double t[][6], int n) {
    double x = d_rand(-10, 10);
    for(int w = 0; w < n; ++w)
        for(int k = 0; k < 6; ++k)
            t[w][k] = (x += 0.4);
}