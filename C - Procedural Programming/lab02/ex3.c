#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

// deklaracje uzywanych funkcji
int rand_i(int a, int b);

int main(){

    int dlugosc = rand_i(1,30);
    char ciag[dlugosc + 1];
    ciag[dlugosc] = '\0';

    for(int i = 0; i < dlugosc; ++i){
        ciag[i] = rand_i(97, 122);
    }
    printf("Przed usunieciem samoglosek: %s\n", ciag);

    char samogloski[] = {'a', 'e', 'i', 'o', 'u', 'y'};
    int size_sam = sizeof(samogloski) / sizeof(samogloski[0]); 

    char* w;
    for (int x = 0; x < size_sam; ++x ){
        for (int i = 0; i < dlugosc; ++i){
            w = strchr(ciag, samogloski[x]);
            if (w != NULL){
                w = w+1;
                --dlugosc;
                ciag[dlugosc] = '\0';
            }
        }

    }

   printf("Po usunieciu samoglosek: %s\n", ciag);


    return 0;
}


int rand_i(int a, int b){//funkcja losujaca integery z zakresu <a, b>
return (a + rand()%(b-a+1));}
