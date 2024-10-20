#include <stdio.h>

void wypisz_i (int *poczatek, int *koniec);
void razem(int* tab1, int* tab2, size_t st1, size_t st2, int* tab3);

int main(){

    int tab1[] = {1,12,13,14,22};
    int tab2[] = {3,4,13,45,54,55,56,66};

    printf("Przed (osobno):\n");
    size_t st1 = sizeof(tab1) / sizeof(tab1[0]);
    size_t st2 = sizeof(tab2) / sizeof(tab2[0]);
    int tab3[st1+st2];

    wypisz_i(tab1, tab1 + st1);
    wypisz_i(tab2, tab2 + st2);

    printf("Po (razem):\n");
    razem(tab1, tab2, st1, st2, tab3);
    wypisz_i(tab3, tab3 + st1 + st2);

    return 0;
}


void wypisz_i (int *poczatek, int *koniec) {
    while (poczatek < koniec)
    printf ("%4d", *poczatek++);
    printf ("\n");
return;}


void razem(int* tab1, int* tab2, size_t st1, size_t st2, int* tab3){

    size_t a = 0, b = 0;
    int t = 0;
    
    do{
    // printf("%d, %d \n", a,b);
        if((tab1[a] <= tab2[b]) && (a != st1-1)){
            tab3[a+b] = tab1[a++];
        }
        else if((tab1[a] > tab2[b]) && (b != st2-1)){
            tab3[a+b] = tab2[b++];
        }
        else if(a == st1){
            tab3[a+b] = tab2[b++];
        }
        ++t;
    // }while(!((a == st1-1) && (b == st2-1)) && t < st1+st2);
    }while((a + b) < (st1 + st2) && t < (st1 + st2) );
}