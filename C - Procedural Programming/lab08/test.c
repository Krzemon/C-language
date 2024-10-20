#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double *get_vector(size_t n);
double *realloc_vector(double *vec, size_t n);
double d_rand(double min, double max);
void fill_random(double *first, double *last, double min, double max);
double dot_product(const double *vec1, const double *vec2, size_t n);
double *sum(const double *vec1, const double *vec2, size_t n);
void print_vector(const double *vec, size_t n, const char *header);

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    if (argc < 2)
    {
        fprintf(stderr, "Brak parametrow: podaj rozmiar wektora.\n");
        return -1;
    }

    if (atoi(argv[1]) < 1)
    {
        fprintf(stderr, "Za maly rozmiar\n");
        return -1;
    }
    size_t n = atoi(argv[1]); 
    size_t m = n;

    double *x = get_vector(n);
    double *y = get_vector(n);
    double *z = get_vector(n);
    double *p[] = {x, y, z, sum(x, y, n), sum(y, z, n)};
    const char *headers[] = {
        "Wektor x",
        "Wektor y",
        "Wektor z",
        "Wektor x + y",
        "Wektor y + z"};
    m = sizeof p / sizeof(*p);
    if (n > 3)
    {
        for (size_t i = 0; i < m; ++i)
            p[i] = realloc_vector(p[i], 3);
        n = 3;
    }
    for (size_t i = 0; i < m; ++i)
        print_vector(*(p + i), n, *(headers + i));

    printf("Iloczyn skalarny <x|y> = %g, <y|z> = %g, <x|z> = %g\n", dot_product(*p, *(p + 1), n), dot_product(*(p + 1), *(p + 2), n), dot_product(*p, *(p + 2), n));

    for (size_t i = 0; i < m; ++i)
        free(*(p + i));
    free(x);
    free(y);
    free(z);
    return 0;
}

double *get_vector(size_t n)
{
    double *vec = malloc(n * sizeof(double));
    fill_random(vec, vec + n, -1.0, 1.0);
    return vec;
}

double *realloc_vector(double *vec, size_t n)
{
    double * p = realloc(vec, n * sizeof(double));
    if (!vec)
    {
        fprintf(stderr, "Blad alokacji w funkcji %s\n", __func__);
        exit(-2);
    }
    return p;
}

double d_rand(double min, double max)
{
    return ((double)rand() / RAND_MAX) * (max - min) + min;
}

void fill_random(double *first, double *last, double min, double max)
{
    while (first < last)
        *first++ = d_rand(min, max);
}

double dot_product(const double *vec1, const double *vec2, size_t n)
{
    double sum = 0.0;
    for (size_t i = 0; i < n; ++i)
        sum += *(vec1 + i) * *(vec2 + i);
    return sum;
}

double *sum(const double *vec1, const double *vec2, size_t n)
{
    double *sum = get_vector(n);
    for (size_t i = 0; i < n; ++i)
        *(sum + i) = *(vec1 + i) + *(vec2 + i);
    return sum;
}

void print_vector(const double *vec, size_t n, const char *header)
{
    printf("%15s: ", header);
    for (size_t i = 0; i < n; ++i)
        printf("%10g ", *(vec + i));
    printf("\n");
}

