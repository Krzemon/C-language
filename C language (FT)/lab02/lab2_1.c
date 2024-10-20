#include <stdio.h>

void swap(int *, int *);
void wypisz_i(int *, int *);
int* find_min_wsk(int *, int ); 
void sort(int *, int *);

int main(void){
  int tab_A[] = {3,5,33,1,7,9,55,1,11,22,12,6,8,4,44,6,42,2,8,26,64,80,22,12,6,8,4,44,6,42,2,16,5,33,1,7,9,55,1,11,22,34,78,11,21,9,12,5,3,9};
  int N = sizeof(tab_A)/sizeof(tab_A[0]);
  printf("element minimalny to:%d\n\n",*(find_min_wsk(tab_A,N)));
  
  for(int i=0;i<N/10;i++){
    printf("Zakres %d - %d --> ",i*10, 10*(i+1)-1);
      if((N-i*10)>=10){
        for(int j=0;j<10;j++){
          printf("tab[%d] = %d, ",j+i*10,tab_A[j+i*10]);
        }
        printf("\n Element minimalny: wartosc = %d, adres = %p, indeks = %d\n",*(find_min_wsk(i*10+tab_A,10)),find_min_wsk(i*10+tab_A,10), (int)(find_min_wsk(i*10+tab_A,10)-tab_A));
      }
      else{
        for(int j=N-N%10;j<N;j++){
          printf("tab[%d] = %d, ",j,tab_A[j]);
        }
        printf("\n Element minimalny: wartosc = %d, adres = %p, indeks = %d\n",*(find_min_wsk(N-N%10 + tab_A,10)),find_min_wsk(N-N%10 + tab_A,10), (int)(find_min_wsk(N-N%10 + tab_A,10)-tab_A));
      }
  }
  
  for(int i=0;i<N/10;i++){
    printf("Zakres %d - %d:",i*10, 10*(i+1)-1);
      printf("[");
      if((N-i*10)>=10){
        sort(tab_A+i*10,tab_A+10*(i+1)-1);
        wypisz_i(tab_A+i*10,tab_A+10*(i+1));
      }
      else{
        sort(tab_A+i*10,tab_A+10*(i+1)-(10-N%10)-1);
        wypisz_i(tab_A+i*10,tab_A+(i+1)*10);
      }
      printf("]\n");
  } 

  return 0;
}

void swap(int*a, int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void wypisz_i (int *begin, int *end) {
    while (begin < end) 
        printf ("%4d ", *begin++);
}

int* find_min_wsk(int* begin, int size) { 
    int* p = begin;
    for(int i=0; i<size; i++)
        if(*p > begin[i])
            p = begin + i;
    return p;
}

void sort(int *begin, int *end) {
    int *p=begin;
    for(;p < end;p++)
        swap(p, find_min_wsk(p, end-p));
}
