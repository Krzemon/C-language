#include <stdio.h>


void Mask(int a, int b){
 int maska = 0, x1,x2;
 long unsigned int N = 8*sizeof(int);
 for(int i=0; i<N/2;i++){maska+=1<<i;}
 printf("Maska wynosi:%d\n",maska);
 x1=(a & maska);
 x2=(b & maska);
 if(x1 == x2)
  printf("Prawda\n");
 else
  printf("Falsz\n");
}


int main(){

  printf("ile bitow: %lu\n", 8*sizeof(int));
  //int a=1048579, b=3;
  int a,b;
  printf("Podaj a: ");
  scanf("%d",&a);
  printf("Podaj b: ");
  scanf("%d",&b);
  Mask(a,b);
  return 0;
}
