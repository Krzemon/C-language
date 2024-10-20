#include <stdio.h>

void wypisz_bin(unsigned int p){
 int N;
 printf("%u", p & 1);
 p = p>>1;
 if(p != 0)
  wypisz_bin(p);
}

int main(){
 unsigned int a;
 printf("Podaj liczbe do wypisania: ");
 scanf("%u",&a);
 printf("Liczba wypisana od prawej to: ");
 wypisz_bin(a);
 printf("\n");
 return 0;
}
