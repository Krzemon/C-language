#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
#define MIN 1
#define MAX 20


void swap_int(int*,int*);        //swaps arguments
void reverse(int*);              //reverses the elements of an array
void swap_tab(int*,int*);        //swaps tables


int main(void){

srand(time(NULL));
printf("swap_int function check\n");
  int a=1,b=2;
  printf("Before: a=%d, b=%d\n",a,b);`
  swap_int(&a,&b);
  printf("After:    a=%d, b=%d\n",a,b);

printf("\nreverse function check\n");
  int i=-1;
  int tab1[N]={0},tab2[N]={0};
  
  while(++i<N){tab1[i]=rand()%(MAX-MIN+1)+MIN;}
  printf("Before: tab1[0]=%d, tab1[9]=%d\n",tab1[0],tab1[9]);
  reverse(tab1);
  printf("After   : tab1[0]=%d, tab1[9]=%d\n",tab1[0],tab1[9]);
  i=-1;
printf("\nswap_tab function check\n");
  while(++i<N){tab2[i]=rand()%(MAX-MIN+1)+MIN;}

  printf("Before:\n");
  i=-1;
  while(++i<N){printf("tab1[%d]=%d, tab2[%d]=%d\n",i,tab1[i],i,tab2[i]);}
  swap_tab(tab1,tab2);
  printf("After:\n");
  i=-1;
  while(++i<N){printf("tab1[%d]=%d, tab2[%d]=%d\n",i,tab1[i],i,tab2[i]);}
  
return 0;
}

void swap_int(int* p1,int* p2){
  int temp;
  temp=*p1;
  *p1=*p2;
  *p2=temp;
}

void reverse(int* P){
  int i=0;
  while(i<N/2){
    swap_int(P+i,P+N-1-i);
    i++;
  }
}

void swap_tab(int* P1,int* P2){
  int i=0;
  while(i<N){
    swap_int(P1+i,P2+i);
    i++;
  }
}
