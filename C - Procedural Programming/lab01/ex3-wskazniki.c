// wersja wskaznikowa
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// deklaracje uzywanych funkcji
double rand_d(double a, double b);
double suma (double *t, int n);
double min (double *t, int n);
double max (double *t, int n);
double mean (double *t, int n);
double max_dev (double *t, int n);
double min_dev (double *t, int n);

const int n = 10;

int main(){

    double t[10];
    double* p = NULL;

    printf("wylosowana tablica %d liczb:\n", n);
    for(p = t; p < t + n ; p++){
        *p = rand_d(7.,35.);
        printf("p[%d] = %.2lf, ", p - t, *p);
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

double suma (double *t, int n){
    double* temp = t;
    double SUM = 0.0;
    while (temp < t + n)
        SUM += *temp++;
return SUM;
}

double min (double *t, int n){
    double* temp = t;
    double MIN = *t;
    while (temp < t + n)
        if (*temp < MIN)
            MIN = *temp;
        else
            ++temp;
return MIN; 
}

double max (double *t, int n){
    double* temp = t;
    double MAX = *t;
    while (temp < t + n)
        if (*temp > MAX)
            MAX = *temp++;
        else 
            ++temp;
return MAX; 
}

double mean (double *t, int n){
    double MEAN = suma(t, n) / n;
return MEAN; 
}

double max_dev (double *t, int n){
    double* temp = t;
    double MEAN = mean(t, n);
    double MAX_DEV = *temp++ - MEAN;

    while (temp < t + n)
        if (*temp - MEAN > MAX_DEV)
            MAX_DEV = *temp++ - MEAN;
        else
            ++temp;
return fabs(MAX_DEV); 
}

double min_dev (double *t, int n){
    double* temp = t;
    double MEAN = mean(t, n);
    double MIN_DEV = *temp++ - MEAN;

    while (temp < t + n)
        if (*temp - MEAN < MIN_DEV)
            MIN_DEV = *temp++ - MEAN;
        else
            ++temp;
return fabs(MIN_DEV); 
}