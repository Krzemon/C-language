#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**********************/
/* DEKLARACJE FUNKCJI */
/**********************/
// Funkcja do wypisania zawartości pliku binarnego
void print_file(const char *filename);
// Funkcja losujaca double z przedziału <a, b>
float rand_f(float a, float b);
// Funkcja zapisujaca strukture do pliku binarnego
void save_to_bin_file(float *tab, int size, const char *filename);
// Funkcja zapisujaca strukture do pliku tekstowego
void save_to_txt_file(float *tab, int size, const char *filename);

int main() {
    float array[100];
    // losujemy liczby z przedziałuu <0.0, 1.0>
    for (int i = 0; i < 100; i++) {
        array[i] = rand_f(0.0f, 1.0f);
    }

    // Zapis do pliku tekstowego
    save_to_txt_file(array, 100, "data.txt");

    // Zapis do pliku binarnego
    save_to_bin_file(array, 100, "data.bin");

    // Określenie długości plików
    FILE* text_file = fopen("data.txt", "r");
    fseek(text_file, 0, SEEK_END);
    int text_size = ftell(text_file);
    fclose(text_file);

    FILE* binary_file = fopen("data.bin", "rb");
    fseek(binary_file, 0, SEEK_END);
    int binary_size = ftell(binary_file);
    fclose(binary_file);

    printf("Rozmiar pliku tekstowego: %ld bajtów\n", text_size);
    printf("Rozmiar pliku binarnego: %ld bajtów\n", binary_size);

    printf("\nZawartość pliku binarnego przed modyfikacją:\n\n");
    print_file("data.bin");

    binary_file = fopen("data.bin", "rb+"); // ODCZYT BINARNY Z MODYFIKACJA 
    if (!binary_file) {
        printf("Nie można otworzyć pliku binarnego do modyfikacji");
        exit(1);
    }

    for (int i = 0; i < 100; i += 5) {
        fseek(binary_file, i * sizeof(float), SEEK_SET);
        float zero = 0.0;
        fwrite(&zero, sizeof(float), 1, binary_file);
    }
    fclose(binary_file);


    printf("\nZawartość pliku binarnego po modyfikacji:\n\n");
    print_file("data.bin");

    return 0;
}

void print_file(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Nie można otworzyć pliku");
        exit(EXIT_FAILURE);
    }

    float value;
    int new_line_arg = 5, temp = 0;
    while (fread(&value, sizeof(float), 1, file) == 1) {
        if(temp == new_line_arg){
            temp = 0;
            printf("\n");
        }
        printf("%f, ", value);
        ++temp;
    }
    printf("\n");
    fclose(file);
}

float rand_f(float a, float b){
    float r = (float)rand() / RAND_MAX;
return r * (b - a) + a;}

void save_to_bin_file(float *tab, int size, const char *filename) {
    FILE *file = fopen(filename, "wb");// BINARNY ZAPIS
    if (!file) {
        printf("Nie można otworzyć pliku do zapisu");
        exit(1);
    }
    fwrite(tab, sizeof(float), size, file);
    fclose(file);
}

void save_to_txt_file(float *tab, int size, const char *filename) {
    FILE *file = fopen(filename, "w");// TXT ZAPIS
    if (!file) {
        printf("Nie można otworzyć pliku do zapisu");
        exit(1);
    }

    for (int i = 0; i < 100; i++) {
        fprintf(file, "%f\n", tab[i]);
    }
    fclose(file);
}
