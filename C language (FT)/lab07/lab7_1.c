#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//generowanie liczb losowych calkowitych z przedziału (min, max)
int i_rand(int min, int max){
    return rand() % (max-min+1) + min;
}
//generowanie liczb losowych rzeczywistych z przedziału (min, max)
double d_rand(double min, double max){
    double r = (double) rand()/RAND_MAX;
    return r*(max-min) + min;
}
void wypisz_f (float *poczatek, float *koniec) { 
  while (poczatek < koniec) 
    printf ("%6.2f", *poczatek++); 
  printf ("\n");    
  return;}
void wypisz_i (int *poczatek, int *koniec) { 
  while (poczatek < koniec) 
    printf ("%4d ", *poczatek++);   
  printf ("\n");    
  return;}
void print_tab_all(int y,int a[][y], int x){
 int i, j;
  for (i = 0; i < x; i++){
    for (j = 0; j < y; j++)
       printf ("%3d", a[i][j]);
    printf ("\n");   }
   return;}
void swap (float *p, float *q) { 
  float temp = *p;
  *p = *q;
  *q = temp;
  return;}

int main() {
    srand(time(NULL));
    // wylosować dwie liczby całkowite  z zakresu  <3, 7> i przypisać je do zmiennych rows oraz columns
    int rows = i_rand(3, 7), columns = i_rand(3,7);
    
    // przydzielić pamięć na dynamiczną tablicę dwuwymiarową o rozmiarze rows x columns
    int **array_1 = calloc(rows, sizeof(int*));
    for(int i = 0; i < rows; ++i)
        array_1[i] = calloc(columns, sizeof(int));
    int **array_2 = calloc(rows, sizeof(int*));
    array_2[0] = calloc(rows * columns, sizeof(int));
    for(int i = 1; i < rows; ++i)
        array_2[i]  =  array_2[i-1] + columns;
    int (*array_3)[columns] = calloc(rows * columns, sizeof(int));
    
    // wypełnić elementy tablicy wartościami całkowitymi wylosowanymi z zakresu <1,15>
    for(int i = 0; i < rows; ++i)
        for(int j = 0; j < columns; ++j) {
            int c = i_rand(1, 15);
            array_1[i][j] = c;
            array_2[i][j] = c;
            array_3[i][j] = c;
        }

    // wypisać wartości tablicy wykorzystując operator tablicowy [ ]
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < columns; ++j)
            printf("%3d ", array_1[i][j]);
        printf("\n");
    }
    printf("\n");
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < columns; ++j)
            printf("%3d ", array_2[i][j]);
        printf("\n");
    }
    printf("\n");
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < columns; ++j)
            printf("%3d ", array_3[i][j]);
        printf("\n");
    }
    printf("\n");

    // wylosować wartość całkowitą z zakresu <3,7> i przypisać ją do zmiennej rows_new
    int rows_new = i_rand(3, 7);
    printf("---\n%d -> %d\n---\n\n", rows, rows_new);

    // wykorzystując funkcję realloc stworzyć tablicę dwuwymiarową o rozmiarze rows_new x columns
    for(int i = rows_new; i < rows; ++i) // nie wykona się gdy rows_new ≥ rows
        free(array_1[i]);
    array_1 = realloc(array_1, rows_new * sizeof(int*));
    for(int i = rows; i < rows_new; ++i) // nie wykona się gdy rows_new ≤ rows
        array_1[i] = calloc(columns, sizeof(int));
    array_2[0] = realloc(array_2[0], rows_new * columns * sizeof(int*));
    array_2 = realloc(array_2, rows_new * sizeof(int*));
    for(int i = 1; i < rows_new; ++i)
        array_2[i]  =  array_2[i-1] + columns;
    array_3 = realloc(array_3, rows_new * columns * sizeof(int));

    // jeżeli rows_new > rows dodatkowe wiersze wypełnić wartościami wylosowanymi z zakresu  <-15,-1>
    for(int i = rows; i < rows_new; ++i) // nie wykona się gdy rows_new ≤ rows
        for(int j = 0; j < columns; ++j) {
            int c = i_rand(-15, -1);
            array_1[i][j] = c;
            array_2[i][j] = c;
            array_3[i][j] = c;
        }
    
    // wypisać wartości tablicy wykorzystując operator tablicowy [ ]
    rows = rows_new;
    
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < columns; ++j)
            printf("%3d ", array_1[i][j]);
        printf("\n");
    }
    printf("\n");
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < columns; ++j)
            printf("%3d ", array_2[i][j]);
        printf("\n");
    }
    printf("\n");
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < columns; ++j)
            printf("%3d ", array_3[i][j]);
        printf("\n");
    }
    printf("\n");
    
    // zwolnić pamięć
    for(int i = 0; i < rows; ++i) // rows = rows_new
        free(array_1[i]);
    free(array_1);
    free(array_2[0]);
    free(array_2);
    free(array_3);

}

