#include <stdio.h>


void swap(int *x, int *y){
 int td=*x;
 *x=*y;
 *y=td;
}

int main(){
 int a,b;
 printf("Podaj a: ");
 scanf("%d",&a);
 printf("Podaj b: ");
 scanf("%d",&b);
 swap(&a,&b);
  printf("Po zamianie\n");
  printf("a = %d\n",a);
  printf("b = %d\n",b);
 return 0;
}
