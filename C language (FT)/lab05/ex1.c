#include <stdio.h>

void swap (int *p, int *q);
void swap_tab(int *A, int *B, int n);
void swap_rows(int n, int (*TAB)[n], int x, int y);
void wypisz_i (int *poczatek, int *koniec);
 
int main(void){
  int tab_1[4][5] = {{1,1,1,1,1},{2,2,2,2,2},{3,3,3,3,3},{4,4,4,4,4}};
  int tab_22 [5][2] = {{1,1},{2,2},{3,3},{4,4},{5,5}};
  int m = (int)sizeof(tab_1[0])/sizeof(int);
  int n = (int)sizeof(tab_22[0])/sizeof(int);
  
  printf("Dzialanie swap_tab\n");
    printf("Przed:\n");
    wypisz_i(tab_22[0], tab_22[n]);
    swap_tab(tab_22[0], tab_22[1],n);
    printf("Po:\n");
    wypisz_i(tab_22[0], tab_22[n]);

  printf("Dzialanie swap_rows\n");
    printf("Przed:\n");
    wypisz_i(tab_1[0], tab_1[0]+m);
    swap_rows(m,tab_1,0,m);
    printf("Po:\n");
    wypisz_i(tab_1[0], tab_1[0]+m);

  
  return 0;
}
 
void swap (int *p, int *q) { 
  int temp = *p;
  *p = *q;
  *q = temp;
return;}
 
void swap_tab(int *A, int *B,int n){
  for(int i=0; i<n;++i){
    swap(A+i,B+i);
  }
}
 
void swap_rows(int n, int (*TAB)[n], int x, int y){
  swap_tab(TAB[0]+x,TAB[0]+y,n);
}

void wypisz_i (int *poczatek, int *koniec) { 
  while (poczatek < koniec) 
    printf ("%4d ", *poczatek++);   
  printf ("\n");    
 return;}
 
