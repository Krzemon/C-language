#include <stdio.h>
#include <math.h>

int zero(double (*f)(double), double l, double r, double* x, double eps) {
    if(f(l) * f(r) > 0) return 0;
    while(fabs(r-l) >= 2*eps) {
        *x = (l+r)/2;
        if(f(l) * f(*x) > 0) l = *x;
        else r = *x;
    }
    return 1;
}

double wielomian(double x) {
    return -x*x+3*x+11;
}

int main() {
    double r;
    int w;
    double eps = 1e-4;
    printf("1) ");
    w = zero(sin, -1, 1, &r, eps);
    if(w) printf("Miejsce zerowe w %.2f.\n", r);
    else printf("Nie znaleziono miejsca zerowego.\n");
    printf("\n2) ");
    w = zero(wielomian, 0, 8, &r, eps);
    if(w) printf("Miejsce zerowe w %.2f.\n", r);
    else printf("Nie znaleziono miejsca zerowego.\n");
    printf("\n3) ");
    w = zero(wielomian, -1, 1, &r, eps);
    if(w) printf("Miejsce zerowe w %.2f.\n", r);
    else printf("Nie znaleziono miejsca zerowego.\n");
}
