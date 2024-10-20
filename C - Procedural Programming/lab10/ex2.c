#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Funkcja obliczająca sumę elementów w wierszu
int suma(int *row, int cols) {
    int sum = 0;
    for (int i = 0; i < cols; i++) {
        sum += row[i];
    }
    return sum;
}

// Funkcja porównująca dla qsort do sortowania wierszy ze względu na średnią
int compare_avg(const void *a, const void *b) {
    const int *row_a = *(const int **)a;
    const int *row_b = *(const int **)b;
    int cols = 10; // Ilość kolumn
    int suma_a = suma((int *)row_a, cols);
    int suma_b = suma((int *)row_b, cols);
    double avg_a = (double)suma_a / cols;
    double avg_b = (double)suma_b / cols;
    return (avg_a > avg_b) - (avg_a < avg_b);
}

// Procedura wypisująca zawartość tablicy
void wypisz_i(int **tab, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    
    int cols = 10; // Ilość kolumn
    int rows = 15; // Ilość wierszy
    int i, j;

    // Tablica tab_3
    int **tab_3 = malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        tab_3[i] = malloc(cols * sizeof(int));
    }
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            tab_3[i][j] = rand() % 21;
        }
    }

    // Tablica tab_33
    int **tab_33 = malloc(rows * sizeof(int *));
    tab_33[0] = malloc(rows * cols * sizeof(int));
    for (i = 1; i < rows; i++) {
        tab_33[i] = tab_33[i - 1] + cols;
    }
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            tab_33[i][j] = rand() % 21;
        }
    }

    // Wypisanie tablicy tab_3 przed sortowaniem
    printf("Tablica tab_3 przed sortowaniem:\n");
    wypisz_i(tab_3, rows, cols);

    // Sortowanie wierszy tab_3 ze względu na średnią
    qsort(tab_3, rows, sizeof(int *), compare_avg);

    // Wypisanie tablicy tab_3 po sortowaniu wierszy ze względu na średnią
    printf("\nTablica tab_3 po sortowaniu wierszy ze względu na średnią:\n");
    wypisz_i(tab_3, rows, cols);

    // Wczytanie wartości rzeczywistej
    double var;
    printf("\nPodaj wartosc rzeczywista: ");
    scanf("%lf", &var);

    // Szukanie wiersza z wartością średnią równą var
    int *found = NULL;
    for (i = 0; i < rows; i++) {
        double avg = (double)suma(tab_3[i], cols) / cols;
        if (avg == var) {
            found = tab_3[i];
            break;
        }
    }

    if (found) {
        // Wypisanie numeru wiersza
        int row_num = found - tab_3[0];
        printf("\nWiersz z wartoscia srednia %.5lf znajduje sie pod numerem %d.\n", var, row_num / cols + 1);
        // Wypisanie zawartości wiersza
        printf("Zawartosc wiersza:\n");
        for (i = 0; i < cols; i++) {
            printf("%d ", found[i]);
        }
        printf("\n");
    } else {
        printf("\nWiersz z wartoscia srednia %.5lf nie istnieje.\n", var);
    }

    // Zwolnienie pamięci
    for (i = 0; i < rows; i++) {
        free(tab_3[i]);
    }
    free(tab_3);
    free(tab_33[0]); // Zwolnienie bloku pamięci dla tab_33
    free(tab_33);

    return 0;
}
