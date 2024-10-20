#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double fun0(double x) { return log(x); }
double fun1(double x) { return x*x;    }
double fun2(double x) { return sin(x); }
double fun3(double x) { return cos(x); }
char* nazwy[]={"log", "pow","sin","cos"};
double data[8] = { 3.5, 1.0, 2.5, 2.0, 1.5, 3.0, 0.5, 4.0 }; 
double (*FUN_CMP)(double);

void print_fun(double (*f)(double), char *n, double *t, int l);
double (**find_max(double (**t)(double), double x))(double);
int cmp (const void *a , const void *b );
void sort_arg(double (*f)(double), double *t, int l);
void wypisz_f (double *poczatek, double *koniec);


int main(void) {
    double (*TAB_FUN[5])(double);
    TAB_FUN[0] = fun0; 
    TAB_FUN[1] = fun1;
    TAB_FUN[2] = fun2;
    TAB_FUN[3] = fun3;
    TAB_FUN[4] = NULL;
    
    print_fun(fun0,"log",data,8);
    printf("\n");

    double (**wsk_fun)(double);
    char **str;
    wsk_fun = TAB_FUN;
    str = nazwy;
    for(;*wsk_fun;++str,++wsk_fun)
        print_fun(*wsk_fun, *str, data, 8);

    double (**wsk_max)(double) = find_max(TAB_FUN, 0.05);
    printf ("dla x= %.3f najwieksza wartosc wynosi %.5f dla funkcji %s\n", 0.05, (*wsk_max)(0.05), nazwy[wsk_max - TAB_FUN]);
    sort_arg (TAB_FUN[1], data, 8);
    wypisz_f(data, data+8);
    
}

void print_fun(double (*f)(double), char *n, double *t, int l) {
    for(int i = 0; i < l; ++i)
        printf("%s(%3f)=%6f  ", n, t[i], f(t[i]));
    printf("\n");   
}

double(**find_max(double (**t)(double), double x))(double) {
    double mv = (*t)(x);
    double (**mp)(double) = t;
    while(*++t) {
        double v = (*t)(x);
        if(v > mv)
            mv = v, mp = t;
    }
    return mp;
}

int cmp (const void *a , const void *b ){
    double A = *(double*)a, B = *(double*)b;
    double C = FUN_CMP(A) - FUN_CMP(B);
    if(C < 0) return -1;
    if(C > 0) return 1;
    return 0;
}

void sort_arg(double (*f)(double), double *t, int l) {
    FUN_CMP = f;
    qsort(t, l, sizeof(double), cmp);
}

void wypisz_f (double *poczatek, double *koniec) { 
  while (poczatek < koniec) 
    printf ("%6.2f", *poczatek++); 
  printf ("\n");    
}
