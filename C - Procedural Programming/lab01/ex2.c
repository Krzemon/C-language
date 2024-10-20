#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

// deklaracje uzywanych funkcji
double rand_d(double a, double b);
void zamiana(double* a, double* b);
void odwroc(double* tab, size_t size);

int main(){

double tab[10];
double* p = NULL;

printf("Przed odwroceniem:\n");
for(p = tab; p < tab + N ; p++){
    *p = rand_d(7,35);
    printf("p[%d] = %.2lf\n", p - tab, *p);
}

odwroc(tab, N);

// if (N % 2 == 0)
//     odwroc(tab, N/2);
// else
//     odwroc(tab, (N-1)/2);

printf("Po odwroceniu:\n");
for(p = tab; p < tab + N ; p++){
    printf("p[%d] = %.2lf\n", p - tab, *p);
}

return 0;
}

double rand_d(double a, double b){//funkcja losujaca double z przedziału <a, b>
double r = (double)rand() / RAND_MAX;//liczba z przedziałuu <0.0, 1.0>
return r * (b - a) + a;}

void zamiana(double* a, double* b){
    double temp = *a;
    *a = *b;
    *b = temp;
}

void odwroc(double* tab, size_t size){
    double* temp = tab + size - 1;
    for(double* p = tab; p < tab + size/2; ++p, --temp){
        zamiana(p,temp);
    }
}
