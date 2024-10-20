// wersja indeksowa
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// deklaracje uzywanych funkcji
double rand_d(double a, double b);
double suma (double t[], int n);
double min (double t[], int n);
double max (double t[], int n);
double mean (double t[], int n);
double max_dev (double t[], int n);
double min_dev (double t[], int n);

const int n = 10;

int main(){

    double t[10];

    printf("wylosowana tablica %d liczb:\n", n);
    for(int i = 0; i < n; ++i){
        t[i] = rand_d(7.,35.);
        printf("p[%d] = %.2lf, ", i, t[i]);
    }
    printf("\b\b"); // nie dziala nie wiem czemu
    printf("\n\n");

    printf("suma elementow tablicy: %.2lf\n", suma(t, n));
    printf("wartosc minimalna tablicy: %.2lf\n", min(t, n));
    printf("wartosc maksymalna tablicy: %.2lf\n", max(t, n));
    printf("wartosc srednia tablicy: %.2lf\n", mean(t, n));
    printf("maksymalne odchylenie od sredniej: %.2lf\n", max_dev(t, n));
    printf("minimalne odchylenie od sredniej: %.2lf\n", min_dev(t, n));


return 0;
}

double rand_d(double a, double b){//funkcja losujaca double z przedziału <a, b>
    double r = (double)rand() / RAND_MAX;//liczba z przedziałuu <0.0, 1.0>
return r * (b - a) + a;
}

double suma (double t[], int n){
    double SUM = 0.0;
    int i = 0;
    while (i++ <  n)
        SUM += t[i];
return SUM;
}

double min (double t[], int n){
    int i = 0;
    double MIN = t[0];
    while (i < n)
        if (t[i] < MIN)
            MIN = t[i++];
        else
            ++i;
return MIN; 
}

double max (double t[], int n){
    int i = 0;
    double MAX = t[0];
    while (i < n)
        if (t[i] > MAX)
            MAX = t[i++];
        else 
            ++i;
return MAX; 
}

double mean (double t[], int n){
    double MEAN = suma(t, n) / n;
return MEAN; 
}

double max_dev (double t[], int n){
    int i = 0;
    double MEAN = mean(t, n);
    double MAX_DEV = t[i++]- MEAN;

    while (i < n)
        if (t[i] - MEAN > MAX_DEV)
            MAX_DEV = t[i++] - MEAN;
        else
            ++i;
return fabs(MAX_DEV); 
}

double min_dev (double t[], int n){
    int i = 0;
    double MEAN = mean(t, n);
    double MIN_DEV = t[i++]- MEAN;

    while (i < n)
        if (t[i] - MEAN  < MIN_DEV)
            MIN_DEV = t[i++] - MEAN;
        else
            ++i;
return fabs(MIN_DEV); 
}