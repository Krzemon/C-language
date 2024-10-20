#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

float* va_tables(int num_tables, ...) {
    va_list args;
    int total_size = 0;

    // Oblicz całkowity rozmiar nowej tablicy
    va_start(args, num_tables);
    for (int i = 0; i < num_tables; i++) {
        int size = va_arg(args, int);
        float* table = va_arg(args, float*);
        total_size += size;
    }
    va_end(args);

    // Alokacja pamięci dla nowej tablicy
    float* result = (float*)malloc(total_size * sizeof(float));
    if (result == NULL) {
        printf("Błąd alokacji pamięci\n");
        exit(1);
    }

    // Kopiowanie wartości do nowej tablicy
    va_start(args, num_tables);
    int pos = 0;
    for (int i = 0; i < num_tables; i++) {
        int size = va_arg(args, int);
        float* table = va_arg(args, float*);
        for (int j = 0; j < size; j++) {
            result[pos++] = table[j];
        }
    }
    va_end(args);

    return result;
}

void print_array(float* array, int size) {
    printf("{");
    for (int i = 0; i < size; i++) {
        printf("%.2f", array[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("}\n");
}

int main() {
    // Przykład 1
    float tab_W[] = {131, 32, 33, 341, 35, 36};
    float tab_X[] = {47};
    float tab_Y[] = {52, 50, 56, 155};
    float tab_Z[] = {62, 165, 66, 65, 67, 68, 69};

    float* result1 = va_tables(4, 
        sizeof(tab_W) / sizeof(tab_W[0]), tab_W, 
        sizeof(tab_X) / sizeof(tab_X[0]), tab_X, 
        sizeof(tab_Y) / sizeof(tab_Y[0]), tab_Y, 
        sizeof(tab_Z) / sizeof(tab_Z[0]), tab_Z);
    print_array(result1, sizeof(tab_W) / sizeof(tab_W[0]) + sizeof(tab_X) / sizeof(tab_X[0]) + sizeof(tab_Y) / sizeof(tab_Y[0]) + sizeof(tab_Z) / sizeof(tab_Z[0]));
    free(result1);

    // Przykład 2
    float tab_A[] = {11, 2, 31, 4};
    float tab_B[] = {13, 2, 14, 15, 17};
    float tab_C[] = {212, 20};

    float* result2 = va_tables(3, 
        sizeof(tab_A) / sizeof(tab_A[0]), tab_A, 
        sizeof(tab_B) / sizeof(tab_B[0]), tab_B, 
        sizeof(tab_C) / sizeof(tab_C[0]), tab_C);
    print_array(result2, sizeof(tab_A) / sizeof(tab_A[0]) + sizeof(tab_B) / sizeof(tab_B[0]) + sizeof(tab_C) / sizeof(tab_C[0]));
    free(result2);

    return 0;
}