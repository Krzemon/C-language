#include <stdio.h>
#include <string.h>
#define N 8

int zwroc_bit(int n, int m){
 int d,x; 
 x = (n >> m);
 d = x%2;
  
 return d;
}

int main(){
 int n,m;
 char bit[N];
 printf("Podaj liczbe: ");
 scanf("%d",&n);
 printf("Podaj ktory bit: ");
 scanf("%d",&m);
 printf("%d bit liczby %d to %d \n",m,n,zwroc_bit(n,m));

 for(int i=0; i<N;i++){
  bit[i]=(char)zwroc_bit(n,i);
 }
printf("Liczba %d to ",n);
for(int i=0; i<N;i++){
   printf("%d",bit[i]);}
printf("\n");
 
 return 0;
}
