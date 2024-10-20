// obsluga kolejki FIFO w oparciu o tablice jednowymiarowa

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 10

// deklaracje funkcji 
char menu(); // wybor opcji
void show(int FIFO[N], int num); // wypisanie kolejki od najstarszego elementu
bool empty(int num); // sprawdzanie czy kolejka jest pusta
bool full(int num);  // sprawdzenie czy kolejka jest pełna
void push(int *num, int FIFO[N]); // dokładania do kolejki, pod warunkiem, że jest miejsce
int pop(int *num,int FIFO[N]);   // zbierania z kolejki, pod warunkiem, że jest element do zebrania



int main() {

    int FIFO[N];
    char TN, NN;
    static int num = 0;

    do {
        if(num == 0){
            printf("Czy chcesz zainicjalizowac kolejke?\n");
            printf ("T - Tak\n"); // zadziala inne od N
            printf ("N - Nie\n");

            scanf ("%c", &NN);
            if(NN == 'N')
                break;
            system("@cls||clear");//czyszczenie ekranu

        }

        printf("Wstepna inicjalizacja kolejki, podaj element numer %d\n", num+1);
        scanf ("%d", &FIFO[num++]);
        system("@cls||clear");//czyszczenie ekranu

        printf("Aktualnie zawiera %d elementow, moze pomiescic jeszcze %d\n", num, N - num);
        printf ("N - Chce zakonczyc dodawanie\n");

        scanf ("%c", &TN);
    }while ((TN != 'N') && (num != N)); 

    char opc = menu();
    switch (opc) {
        case 'W' : printf ("obsluga wypisania zawartosci kolejki\n"); show(FIFO, num);
            break;
        case 'S' : printf ("obsluga wypisania stanu kolejki (pusta/pelna)\n"); 
            if(empty(num) == 0){
                printf("True\n"); 
            }
            else{
                printf("False\n"); 
            }
            break;
        case 'A' : printf ("obsluga dolozenia elementu do kolejki\n");
            if(full(num) != 0){
                printf("True\n"); 
            }
            else{
                printf("False\n"); 
            }
            break;
        case 'Z' : printf ("obsluga zebrania elementu z kolejki\n"); push(&num, FIFO);break;
        case 'K' : printf ("Koniec\n"); pop(&num, FIFO); break;
    }


return 0;
}


char menu (){
    char opcja = 'X';

    while ((opcja != 'W') && (opcja != 'S') && (opcja != 'A') && (opcja != 'Z') && (opcja != 'K')) {
        system("@cls||clear");//czyszczenie ekranu
        printf ("Wybierz opcje :\n");
        printf ("W - Wypisanie zawartosci kolejki\n");
        printf ("S - Wypisanie stanu kolejki (pusta/pelna)\n");
        printf ("A - Dolozenie elementu do kolejki\n");
        printf ("Z - Zebranie elementu z kolejki\n");
        printf ("K - Koniec \n");
        printf ("podaj opcje :");
        scanf ("%c", &opcja);
    }
return opcja;
}

void show(int FIFO[N], int num){
    for(int i= 0; i < num-1; ++i){
        printf ("%3d\n", FIFO[i]);
    }
}

bool empty(int num){
    if(num == 0)
        return 1;
    else 
        return 0;
}

bool full(int num){
    if(num == N)
        return 1;
    else 
        return 0;
}

void push(int *num, int FIFO[N]){
    if(*num >= N){
        printf("Nie mozna wykonac dzialania, kolejka pelna\n");
        return;
    }
    printf("Podaj element FIFO[%d]\n", num);

    scanf("%d", &FIFO[*num - 1]);
    printf("dodano! :)\n");
}

int pop(int *num, int FIFO[N]){
    if(*num == 0){
        printf("Nie mozna wykonac dzialania, kolejka pusta\n");
        return -1;
    }
    printf("Wyciagniety element: ");

    return FIFO[--(*num)];
}