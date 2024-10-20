#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DIGITS 100 // Maksymalna liczba cyfr w liczbie

// Struktura elastyna
typedef struct {
    int sign; // 0 dla dodatnich, 1 dla ujemnych
    int length; // Długość tablicy liczb
    int *digits; // Wskaźnik do tablicy cyfr
} elastyna;

// Funkcja porównująca do sortowania
int compare(const void *a, const void *b) {
    elastyna *num1 = *(elastyna **)a;
    elastyna *num2 = *(elastyna **)b;

    // Porównywanie znaków
    if (num1->sign != num2->sign)
        return num1->sign - num2->sign;

    // Porównywanie długości (dłuższe liczby są większe, jeśli są tego samego znaku)
    if (num1->length != num2->length)
        return (num1->sign == 0 ? num1->length - num2->length : num2->length - num1->length);

    // Porównywanie cyfry po cyfrze
    for (int i = 0; i < num1->length; i++) {
        if (num1->digits[i] != num2->digits[i])
            return (num1->sign == 0 ? num1->digits[i] - num2->digits[i] : num2->digits[i] - num1->digits[i]);
    }

    return 0;
}

// Funkcja do generowania losowych liczb
void generate_random_number(elastyna *num) {
    num->sign = rand() % 2; // Losowy znak
    num->length = rand() % MAX_DIGITS + 1; // Losowa długość od 1 do MAX_DIGITS
    num->digits = malloc(num->length * sizeof(int));

    // Generowanie losowych cyfr
    for (int i = 0; i < num->length; i++) {
        num->digits[i] = rand() % 10;
    }

    // Unikanie zera jako pierwszej cyfry
    if (num->digits[0] == 0) {
        num->digits[0] = rand() % 9 + 1;
    }
}

// Funkcja do wypisywania liczby
void print_number(elastyna *num) {
    if (num->sign == 1) {
        printf("-");
    }
    for (int i = 0; i < num->length; i++) {
        printf("%d", num->digits[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    // Tworzenie tablicy wskaźników do struktur
    elastyna *tab[5];

    // Generowanie losowych liczb
    for (int i = 0; i < 5; i++) {
        tab[i] = malloc(sizeof(elastyna));
        generate_random_number(tab[i]);
    }

    // Wypisywanie liczb przed sortowaniem
    printf("Liczby przed sortowaniem:\n");
    for (int i = 0; i < 5; i++) {
        printf("tab[%d]: ", i);
        print_number(tab[i]);
    }

    // Sortowanie tablicy
    qsort(tab, 5, sizeof(elastyna *), compare);

    // Wypisywanie liczb po sortowaniu
    printf("\nLiczby po sortowaniu:\n");
    for (int i = 0; i < 5; i++) {
        printf("tab[%d]: ", i);
        print_number(tab[i]);
    }

    // Zwolnienie pamięci
    for (int i = 0; i < 5; i++) {
        free(tab[i]->digits);
        free(tab[i]);
    }

    return 0;
}
