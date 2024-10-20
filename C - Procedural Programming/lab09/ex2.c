#include <stdio.h>

int add2(int * , int *); 
int comp2(int * , int *);
int add2_or_comp2(int a , int b, int (*fun)(int*, int*));

int main() {

  int a, b;
  printf("Prosze podac liczbe calkowita a: ");
  scanf("%d",&a);
  printf("Prosze podac liczbe calkowita b: ");
  scanf("%d",&b);

  // int (*fun_1)(int*, int*) = add2;
  // int (*fun_2)(int*, int*) = comp2;

  int suma = add2_or_comp2(a, b, add2);
  int c = add2_or_comp2(a, b, comp2);
  printf("a = %d\n", a);
  printf("b = %d\n", b);
  printf("a + b =  %d\n", suma);
  if(c > 0)
    printf("a + b = %d\n", a+b);
  else if (c < 0)
    printf("a - b = %d\n", a-b);
  else 
    printf("a = b\n");
}


int add2(int *a, int *b){
  return *a + *b;
}

int comp2(int *a , int *b){
  if (*a > *b)
    return 1;
  else if (*a < *b)
    return -1;
  else 
    return 0;
}

int add2_or_comp2(int a , int b, int (*fun)(int*, int*)){
  int val = fun(&a,&b);
  return val;
}
