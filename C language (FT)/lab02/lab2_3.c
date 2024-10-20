#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MIN 30
#define N 70

//porównuje dwie bardzo długie liczby zapisane w postaci stringów

int number_cmp(char *, char *);
int i_rand(int , int );

int main(void){
  srand(time(NULL));

  int A=i_rand(MIN,i_rand(MIN,N));
  char tab_A[A+1];
  tab_A[A]='\0';
  tab_A[0] = '0' + i_rand(1, 9); 

  int B=i_rand(MIN,i_rand(MIN,N));
  char tab_B[B+1];
  tab_B[B]='\0';
  tab_B[0] = '0' + i_rand(1, 9);
  
  for(int i = 1; i < A; ++i)
    tab_A[i] = '0' + i_rand(0, 9);
  for(int i = 1; i < B; ++i)
    tab_B[i] = '0' + i_rand(0, 9);
  const char *odp[] = {"Pierwsza liczba jest mniejsza","Obie sa rowne","Pierwsza liczba jest wieksza"};

  printf("%s\n",tab_A);
  printf("%s\n",tab_B);
  printf("%s\n",odp[1+number_cmp(tab_A, tab_B)]);
  
  return 0;
}
int number_cmp(char *A, char *B){
    int N1 = strlen(A);
    int N2 = strlen(B);
    if(N1!=N2)
      return (N1>N2) ? 1 : -1;
    if (strcmp(A, B) == 0) 
      return 0;
    else
      return (strcmp(A, B) < 0) ? -1 : 1;
}

int i_rand(int min, int max){
  return rand() % (max-min+1) + min;}

