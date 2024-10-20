#include <stdio.h>

int  suma (int *tab, int len);
void sort (int k,int n,int (*TAB)[k]);
void swap (int *p, int *q);
void swap_tab(int *A, int *B,int n);
void swap_rows(int k, int (*TAB)[k], int x, int y);

int main(void){
  int tab_A[3][6] = {{1,-4,1,2,11},{12,2,32,2},{72,2,-32,2}};
  int tab_B[4][3] = {{1,-24,1},{9,32,2},{5,64,1},{3,32,1}};
  int m = (int)sizeof(tab_A[0])/sizeof(int);
  int n = (int)sizeof(tab_B[0])/sizeof(int);
  int k = (int)sizeof(tab_A)/(m*sizeof(int));
  int l = (int)sizeof(tab_B)/(n*sizeof(int));
  sort (m, k,tab_A);
  
  //printf("%d\n",m); 6
  //printf("%d\n",n); 3
  //printf("%d\n",k); 3
  //printf("%d\n",l); 4   
  return 0;
}
//wskaznik do elementu o dlugosci wiersza
void sort (int k, int n, int (*TAB)[k]){
  int min = suma(TAB[k], k);
  for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
      if(suma(TAB[k]+j*k, k*n) < min)
      min = j;
    }
    swap(TAB[i],TAB[min]);
  }
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
 
void swap_rows(int k, int (*TAB)[k], int x, int y){
  swap_tab(TAB[0]+x,TAB[0]+y,k);
}


int suma (int *tab, int len) { 
  int ss = 0.0;
  for (int i = 0; i < len; ++i)  
    ss+= *(tab[i]); 
 return ss;}
 
