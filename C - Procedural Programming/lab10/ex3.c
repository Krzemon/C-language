#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

// Struktura przechowująca współrzędne punktu 2D
struct point {
    double x;
    double y;
};

// Struktura przechowująca wektor
struct vect {
    struct point start;  // Początkowy punkt wektora
    struct point end;    // Końcowy punkt wektora
    double len;          // Długość wektora
    char label[20];      // Etykieta/nazwa wektora
};

// Funkcja obliczająca długość wektora
double vect_len(struct point start, struct point end) {
    double dx = end.x - start.x;
    double dy = end.y - start.y;
    return sqrt(dx*dx + dy*dy);
}

// Procedura wypełniająca tablicę struktur vect
void fill_tab(struct vect *tab, int size) {
    srand(time(NULL)); // Inicjalizacja generatora liczb pseudolosowych

    for (int i = 0; i < size; i++) {
        // Generowanie losowych współrzędnych punktów
        double Ax = (double)rand() / RAND_MAX * 10; // Losowe liczby od 0 do 10
        double Ay = (double)rand() / RAND_MAX * 10;
        double Bx = (double)rand() / RAND_MAX * 10;
        double By = (double)rand() / RAND_MAX * 10;

        // Wypełnienie struktury vect
        tab[i].start.x = Ax;
        tab[i].start.y = Ay;
        tab[i].end.x = Bx;
        tab[i].end.y = By;

        // Obliczenie długości wektora i przypisanie do pola len
        tab[i].len = vect_len(tab[i].start, tab[i].end);

        // Generowanie losowej nazwy wektora
        sprintf(tab[i].label, "Vector%d", i + 1);
    }
}

// Funkcja wypisująca wektory z tablicy tab_vect
void print_vectors(struct vect *tab, int size) {
    printf("Numer struktury  Ax   Ay   Bx   By   Dlugosc  Nazwa\n");
    for (int i = 0; i < size; i++) {
        printf("%-15d%.2f %.2f %.2f %.2f %.2f     %s\n",
               i + 1, tab[i].start.x, tab[i].start.y,
               tab[i].end.x, tab[i].end.y,
               tab[i].len, tab[i].label);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Podaj rozmiar tablicy jako argument wywolania programu.\n");
        return 1;
    }

    int size = atoi(argv[1]);
    if (size <= 0) {
        printf("Rozmiar tablicy musi byc dodatni liczba calkowita.\n");
        return 1;
    }

    // Alokacja pamięci dla tablicy struktur vect
    struct vect *tab_vect = (struct vect *)malloc(size * sizeof(struct vect));
    if (tab_vect == NULL) {
        printf("Blad alokacji pamieci.\n");
        return 1;
    }

    // Wypełnienie tablicy tab_vect
    fill_tab(tab_vect, size);

    // Wypisanie wektorów
    print_vectors(tab_vect, size);

    // Zwolnienie zaalokowanej pamięci
    free(tab_vect);

    return 0;
}
