#include <stdio.h>


double sumuj(double (*tab)[3], size_t row_num);
void wypisz_d (double *poczatek, double *koniec);


int main(){

    double A_1[][3] = {1.3, 3.4, 1.1, 26.3, 34.4, 12.3, 8.1};
    double A_2[][3] = {11.3, 23.4, 10.1, -2.3, -4.4, 2.3, 0.1, 13.1, 6.1, 14.4};

    size_t row_num_1 = sizeof(A_1) / sizeof(*A_1);
    size_t row_num_2 = sizeof(A_2) / sizeof(*A_2);

    double suma_1 = sumuj(A_1, row_num_1); 
    double suma_2 = sumuj(A_2, row_num_2); 


    printf("wypis calych tablic na raz:\n\n");
    wypisz_d(A_1[0], A_1[row_num_1 - 1] + 3);
    wypisz_d(A_2[0], A_2[row_num_2 - 1] + 3);   


    printf("\n");
    printf("wypis wierszami:\n\n");

    printf("Tablica A_1:\n");
    for(int i = 0; i < row_num_1; ++i){
        wypisz_d(A_1[i], A_1[i]+3);
    }

    printf("Tablica A_2:\n");
    for(int i = 0; i < row_num_2; ++i){
        wypisz_d(A_2[i], A_2[i]+3);
    }

    printf("\n\n");
    printf("Ilosc wierszy tablicy A_1 wynosi: %d\n", row_num_1);
    printf("Ilosc wierszy tablicy A_2 wynosi: %d\n", row_num_2);

return 0;
}


void wypisz_d (double *poczatek, double *koniec) {
    while (poczatek < koniec)
    printf ("%6.3g ", *poczatek++);
    printf ("\n");
return;
}


double sumuj(double (*tab)[3], size_t row_num){

    double sum = 0;
    for(int i = 0; i < row_num; ++i){
        for(int j = 0; j < 3; ++j){
            sum += tab[i][j];
        }
    }

    return sum;
}