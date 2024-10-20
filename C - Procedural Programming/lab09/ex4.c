#include <stdio.h>
#include <stdlib.h>

// Funkcja wypisująca wiersz od wskaźnika początkowego do końcowego
void wypisz_i(int *poczatek, int *koniec) {
    while (poczatek < koniec)
        printf("%4d ", *poczatek++);
    printf("\n");
}

// Funkcja sumująca elementy w wierszu
int suma(int *p, int len) {
    int sum = 0;
    for (int i = 0; i < len; i++)
        sum += p[i];
    return sum;
}

// Funkcja porównawcza dla qsort, sortująca sumy
int compare_sums(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Funkcja porównawcza dla bsearch, porównująca wartość z sumą
int compare_value(const void *a, const void *b) {
    int value = *(int *)a;
    int sum = *(int *)b;
    return value - sum;
}

// Funkcja znajdująca wskaźnik do wiersza o sumie elementów równej value
int* num_find(int k, int t[][k], int w, int value) {
    int sums[w];
    for (int i = 0; i < w; i++) {
        sums[i] = suma(t[i], k);
    }

    // Sortowanie wierszy według sumy ich elementów
    for (int i = 0; i < w - 1; i++) {
        for (int j = i + 1; j < w; j++) {
            if (sums[i] > sums[j]) {
                int temp_sum = sums[i];
                sums[i] = sums[j];
                sums[j] = temp_sum;
                
                int temp_row[k];
                for (int col = 0; col < k; col++) {
                    temp_row[col] = t[i][col];
                    t[i][col] = t[j][col];
                    t[j][col] = temp_row[col];
                }
            }
        }
    }

    // Szukanie wartości w tablicy sum
    int *result = (int *)bsearch(&value, sums, w, sizeof(int), compare_value);

    if (result != NULL) {
        int index = result - sums;
        return t[index];
    } else {
        return NULL;
    }
}

// Funkcja wypisująca całą tablicę
void print_tab_all(int y, int a[][y], int x) {
    int i, j;
    for (i = 0; i < x; i++) {
        for (j = 0; j < y; j++)
            printf("%4d", a[i][j]);
        printf("\n");
    }
}

int main() {
    int value = -22;
    int tab_A[3][6] = {{1, -4, 1, 2, 11, 0}, {12, 2, 3, 2, -2, -5}, {7, 2, -3, 2, 2, -1}};
    int tab_B[4][3] = {{1, -24, 1}, {9, 32, 2}, {5, 64, 1}, {3, 32, 1}};

    int *wsk = num_find(6, tab_A, 3, value);
    printf("W tablicy tab_A:\n");
    print_tab_all(6, tab_A, 3);
    if (wsk != NULL) {
        printf("Zawartosc wiersza tab_A ktorego suma elementow jest rowna %d to:\n", value);
        wypisz_i(wsk, wsk + 6);
    } else {
        printf("Nie znaleziono wiersza o takiej sumie elementow\n");
    }

    wsk = num_find(3, tab_B, 4, value);
    printf("W tablicy tab_B:\n");
    print_tab_all(3, tab_B, 4);
    if (wsk != NULL) {
        printf("Zawartosc wiersza tab_B ktorego suma elementow jest rowna %d to:\n", value);
        wypisz_i(wsk, wsk + 3);
    } else {
        printf("Nie znaleziono wiersza o takiej sumie elementow\n");
    }

    return 0;
}
