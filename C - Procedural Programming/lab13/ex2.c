#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// globalne tablice
char *first[10] = {"Art", "Bruno", "Tom", "John", "Mike", "Frank", "Jim", "Emil", "Mark", "Paul"};
char *last[6] = {"Smith", "Jones", "Evans", "Brown", "Lipton", "Scott"};


/**********************/
/* DEFINICJE STRUKTUR */
/**********************/
typedef struct {
    char fname[10][10+1]; // dwa imiona, każde do 10 znaków ze znakiem '\0'
    char lname[10+1];     // nazwisko do 10 znaków ze znakiem '\0'
} data;

typedef struct {
    int room;    // liczba przechowująca numer pokoju
    data emp[5]; // tablica przechowująca 5 pracowników, każdy opisany strukturą struct data
} staff;


/**********************/
/* DEKLARACJE FUNKCJI */
/**********************/
// Funkcja wypelniajaca strukture stuff
void fill_staff(staff *s);
// Funkcja zapisujaca strukture do pliku binarnego
void save_to_bin_file(staff *tab, int size, const char *filename);
// Funkcja przeszukujaca plik binarny
void find_in_bin_file(const char *filename);

int main() {
    srand(time(NULL));

    staff TAB[15];
    for (int i = 0; i < 15; i++) {
        fill_staff(&TAB[i]);
    }

    save_to_bin_file(TAB, 15, "staff.bin");

    printf("Pracownicy o nazwisku Brown:\n");
    find_in_bin_file("staff.bin");

    return 0;
}

void fill_staff(staff *s) {
    s->room = rand() % 101 + 100;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 2; j++) {
            strcpy(s->emp[i].fname[j], first[rand() % 10]);
        }
        strcpy(s->emp[i].lname, last[rand() % 6]);
    }
}

void save_to_bin_file(staff *tab, int size, const char *filename) {
    FILE *file = fopen(filename, "wb");// BINARNY ZAPIS
    if (!file) {
        printf("Nie można otworzyć pliku do zapisu");
        exit(1);
    }
    fwrite(tab, sizeof(staff), size, file);
    fclose(file);
}

void find_in_bin_file(const char *filename) {
    FILE *file = fopen(filename, "rb");// BINARNY ODCZYT
    if (!file) {
        printf("Nie można otworzyć pliku do odczytu");
        exit(1);
    }

    staff s;
    while (fread(&s, sizeof(staff), 1, file) == 1) {
        for (int i = 0; i < 5; i++) {
            if (strcmp(s.emp[i].lname, "Brown") == 0) {
                printf("Imiona: %s %s, Nazwisko: %s, Numer pokoju: %d\n",
                       s.emp[i].fname[0], s.emp[i].fname[1], s.emp[i].lname, s.room);
            }
        }
    }

    fclose(file);
}