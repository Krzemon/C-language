#include <stdio.h>
#define N (sizeof(unsigned)*8)

//zamienia liczbe decymalną na binarną

void write_binar(unsigned int, char *);
unsigned bits(unsigned int);


int main(void){
    unsigned number;
    char tab[N+1] = {0};
    printf("Podaj liczbe do zamiany na binarna: ");
    scanf("%u",&number);
    write_binar(number, tab);
    printf("liczba wczytana %u :     %32s \n", number, tab);             
    unsigned result = bits(number);
    write_binar(result, tab);
    printf("%u po wyzerowaniu bitow: %32s\n", number, tab);
  return 0;
}

//zapis do char*; [0] - najstarszy
void write_binar (unsigned int n, char *wsk) {
    wsk[N] = '\0';
    for(int i = 0; i < N; ++i)
        wsk[i] = (n & (1 << (N-i-1))) ? '1' : '0';
}

// parzyste wyzerowane
unsigned bits(unsigned int x) {
    unsigned m = 0, mm = 0b10;
    for(int i = 1; i < N; i += 2, mm <<= 2)
        m |= mm;
    return x & m;
}

