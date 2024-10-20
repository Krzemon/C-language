#include <stdio.h>

// Funkcja bits - zeruje parzyste bity (0, 2, 4,...)
unsigned bits(unsigned x) {
    unsigned mask = 0x55555555; // maska do wyzerowania parzystych bitów
    return x & mask;
}

// Procedura write_binar - zamienia liczbę na string reprezentujący jej zapis binarny
void write_binar(unsigned n, char *wsk) {
    int size = sizeof(unsigned) * 8; // całkowita liczba bitów w unsigned
    wsk[size] = '\0'; // zakończenie stringu

    for (int i = size - 1; i >= 0; i--) {
        wsk[i] = (n & 1) ? '1' : '0'; // ustawianie bitu w odpowiedniej pozycji
        n >>= 1; // przesunięcie bitowe w prawo o 1
    }
}

int main() {
    unsigned number;
    printf("Podaj liczbe calkowita bez znaku: ");
    scanf("%u", &number);

    char binary_representation[sizeof(unsigned) * 8 + 1]; // +1 na zakończenie stringu

    write_binar(number, binary_representation);

    printf("Liczba wczytana: %u %s\n", number, binary_representation);

    unsigned result = bits(number);
    write_binar(result, binary_representation);

    printf("%u nowa liczba: %s\n", result, binary_representation);

    return 0;
}
