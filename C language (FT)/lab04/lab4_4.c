#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double d_rand(double, double);
int *flooor(double *, double *);

int main(void){
    srand(time(NULL));
    double a = d_rand(-100, 100), b = d_rand(-100, 100);
    int *p = flooor(&a, &b);
    printf("%g * %g = %d\n", a, b, *p);

    free(p);
    return 0;
}

double d_rand(double min, double max){
    double r = (double) rand()/RAND_MAX;
    return r*(max-min) + min;
}

int *flooor(double *a, double *b) {
    int *r = malloc(sizeof(int));
    *r = floor(*a * *b);
    return r;
}