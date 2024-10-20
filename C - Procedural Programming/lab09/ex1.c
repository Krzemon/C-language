#include <stdio.h>
#include <stdlib.h>

// suma elementow tablicy
int suma(int *p, int len);
// elementy w wierszach tak, aby na początku były elementy parzyste, a potem elementy nieparzyste (procedura sortuje każdy wiersz oddzielnie)
void proc_1(int k, int t[][k], int w);
// wiersze rosnąco ze względu na wartość  maksymalną w wierszu należy wykorzystać funkcję max zwracającą indeks elementu maksymalnego w tablicy
void proc_2(int k, int t[][k], int w);
// indeks elementu maksymalnego w tablicy
int max(int *tab, int len);
// wypisuje cala tablice
void print_tab_all(int y, int a[][y], int x);
// komparatory dla qsort
int porownaj_1(const void *a, const void *b);
int porownaj_2(const void *a, const void *b);

int K;

int main() {
    int tab_A[3][6] = {{1, -4, 1, 2, 11, 55}, {12, 2, 32, 2, 0, 0}, {72, 1, -32, 2, 0, 0}};
    int tab_B[4][3] = {{1, -24, 1}, {9, 32, 2}, {5, 64, 1}, {3, 32, 1}};

    printf("tab_A\n");
    print_tab_all(6, tab_A, 3);
    printf("\n");
    printf("tab_A po proc1\n");
    proc_1(6, tab_A, 3);
    print_tab_all(6, tab_A, 3);
    printf("\n");
    printf("tab_A po proc2\n");
    proc_2(6, tab_A, 3);
    print_tab_all(6, tab_A, 3);

    printf("\n\n");

    printf("tab_B\n");
    print_tab_all(3, tab_B, 4);
    printf("\n");
    printf("tab_B po proc1\n");
    proc_1(3, tab_B, 4);
    print_tab_all(3, tab_B, 4);
    printf("\n");
    printf("tab_B po proc2\n");
    proc_2(3, tab_B, 4);
    print_tab_all(3, tab_B, 4);

    return 0;
}

int suma(int *p, int len) {
    int sum = 0;
    for (int i = 0; i < len; i++)
        sum += p[i];
    return sum;
}

int max(int *tab, int len) {
    int ind = 0;
    for (int i = 1; i < len; i++)
        if (tab[ind] < tab[i])
            ind = i;
    return ind;
}

void print_tab_all(int y, int a[][y], int x) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++)
            printf("%3d ", a[i][j]);
        printf("\n");
    }
}

int porownaj_1(const void *a, const void *b) {
    int int_a = *(int *)a;
    int int_b = *(int *)b;

    // Sort by even first, then odd
    if ((int_a % 2 == 0) && (int_b % 2 != 0))
        return -1;
    if ((int_a % 2 != 0) && (int_b % 2 == 0))
        return 1;

    // If both are even or both are odd, sort by value
    return int_a - int_b;
}

void proc_1(int k, int t[][k], int w) {
    for (int i = 0; i < w; ++i)
        qsort(t[i], k, sizeof(int), porownaj_1);
}

int porownaj_2(const void *a, const void *b) {
    int *row_a = (int *)a;
    int *row_b = (int *)b;

    int max_a = row_a[max(row_a, K)];
    int max_b = row_b[max(row_b, K)];

    return max_a - max_b;
}

void proc_2(int k, int t[][k], int w) {
    K = k;
    qsort(t, w, sizeof(t[0]), porownaj_2);
}
