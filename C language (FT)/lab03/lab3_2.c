#include <stdio.h>
#include <stdlib.h>
#define N 5

//transponowanie tablicy

void swap(int *, int *);

int main(){
  int abc[N][N];
  for(int w = 0; w < N; ++w) {    
    for(int k = 0; k < N; ++k) {
      abc[w][k] = k;
      printf("TAB[%d][%d] = %d", w, k, abc[w][k]);
      printf("%s", k == N-1 ? "\n" : ", ");
      }
  }

  for(int i = 0; i < N-1; ++i)
    for(int j = i+1; j < N; ++j)
      swap(*(abc+j)+i, *(abc+i)+j);
  printf("\n");
  for(int w = 0; w < N; ++w) {    
    for(int k = 0; k < N; ++k) {
      printf("TAB[%d][%d] = %d", w, k, abc[w][k]);
      printf("%s", k == N-1 ? "\n" : ", ");
    }
  }
  printf("\n");

  int i=0,w = -1;
  while(i<N-1)
     printf("TAB[%d][%d] = %d, ", w, i, abc[++w][++i]);
  printf("\n");

return 0;}

void swap (int *p_1, int *p_2) { 
  int temp = *p_1;
  *p_1 = *p_2;
  *p_2 = temp;
}