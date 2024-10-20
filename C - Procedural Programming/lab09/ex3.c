#include <stdio.h>
#include <math.h>

void wypisz_i(int *poczatek, int *koniec);
int porownaj(const void *a , const void *b );
int find (int k, int t[][k], int w, int q);

double def_integral(double (*fun)(double), double x_0, double x_n, int n); 
double fun_1(double x);
double fun_2(double x);

double (*fun_wsk_1)(double) = &fun_1;
double (*fun_wsk_2)(double) = &fun_2;

int main() {

    int n1 = 1000, n2 = 1000;
    
    double a1 = 1, b1 = 12, a2 = -5, b2 = 6;
    double v1 = def_integral(fun_wsk_1, a1, b1, n1);
    double v2 = def_integral(fun_wsk_2, a2, b2, n2);

    printf("Calka z sin(x) w przedziale <%2.lf, %2.lf> dla %d podprzedziałow wynik %2.6lf\n", a1, b1, n1, v1);
    printf("Calka z x²+3*x-14.511 w przedziale <%2.lf, %2.lf> dla %d podprzedziałow wynik %2.6lf\n", a2, b2, n2, v2);

    return 0;
}


// --------------------------
double def_integral(double (*fun)(double), double x_0, double x_n, int n){
    double dx = (x_n - x_0) / n;
    double value = (fun(x_0) + fun(x_n) ) / 2;

    for(int i = 1; i < n-1; ++i)
        value += fun(x_0 + i * dx);

    value *= dx;
    return value;
}

double fun_1(double x){
    return sin(x);
}

double fun_2(double x){
    return x*x + 3*x - 14.511;;
}
