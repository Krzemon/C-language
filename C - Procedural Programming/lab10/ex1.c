#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

// Definicje funkcji
double fun0(double x) { return log(x); }
double fun1(double x) { return x * x; }
double fun2(double x) { return sin(x); }
double fun3(double x) { return cos(x); }

// Typ wskaźnika do funkcji
typedef double (*TAB_FUN)(double);

// Tablica wskaźników do funkcji
TAB_FUN TAB_FUN_ARRAY[] = {fun0, fun1, fun2, fun3, NULL};

// Tablica nazw funkcji
char *nazwy[] = {"log", "pow", "sin", "cos"};

// Procedura print_fun
void print_fun(double (*fun_ptr)(double), char *fun_name, double *data, int size) {
    printf("%s(", fun_name);
    for (int i = 0; i < size; i++) {
        printf("%.1f=%.4f ", data[i], fun_ptr(data[i]));
    }
    printf(")\n");
}

// Procedura sortująca tablicę argumentów dla funkcji
int compare(const void *a, const void *b) {
    double arg1 = *(const double *)a;
    double arg2 = *(const double *)b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

void sort_arg(TAB_FUN fun, double *data, int size) {
    // Obliczanie wartości funkcji dla danych argumentów
    double values[size];
    for (int i = 0; i < size; i++) {
        values[i] = fun(data[i]);
    }
    // Sortowanie danych
    qsort(data, size, sizeof(double), compare);
    // Wypisanie posortowanych danych i odpowiadających wartości funkcji
    printf("funkcja --> %s  tablica data : ", nazwy[1]); // Uwaga: zmiana indeksu na 1
    for (int i = 0; i < size; i++) {
        printf("%.1f, ", data[i]);
    }
    printf("\n");
    printf("                              wartosci : ");
    for (int i = 0; i < size; i++) {
        printf("%.1f, ", values[i]);
    }
    printf("\n");
}

// Funkcja znajdująca maksymalną wartość funkcji dla danego argumentu
TAB_FUN find_max(TAB_FUN *fun_array, double x) {
    double max_val = (*fun_array[0])(x);
    TAB_FUN max_fun = fun_array[0];
    for (int i = 1; fun_array[i] != NULL; i++) {
        double val = (*fun_array[i])(x);
        if (val > max_val) {
            max_val = val;
            max_fun = fun_array[i];
        }
    }
    return max_fun;
}

int main() {
    double data[] = {3.5, 1.0, 2.5, 2.0, 1.5, 3.0, 0.5, 4.0};

    // Utworzenie wskaźników wsk_fun, oraz str
    TAB_FUN *wsk_fun = TAB_FUN_ARRAY;
    char **str = nazwy;

    // Wywołanie procedury print_fun dla wszystkich funkcji
    for (int i = 0; wsk_fun[i] != NULL; i++) {
        print_fun(wsk_fun[i], str[i], data, 8);
    }

    // Znalezienie funkcji z największą wartością dla danego argumentu
    double x = 0.05;
    TAB_FUN wsk_max = find_max(TAB_FUN_ARRAY, x);
    int index = 0;
    while (TAB_FUN_ARRAY[index] != wsk_max) {
        index++;
    }
    printf("dla x=%.3f najwieksza wartosc wynosi %.5f dla funkcji %s\n", x, wsk_max(x), nazwy[index]);

    // Sortowanie tablicy danych dla jednej z funkcji
    sort_arg(TAB_FUN_ARRAY[1], data, 8);

    return 0;
}