#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(){
 int n,m,s=0;
 double x,y, sum,pi; 
 srand(time(NULL));
 printf("Podaj liczbe calkowita dodatnia: ");
 scanf("%d",&n);
 if(n<1){
  while(n<1){
  printf("Zla liczba! Podaj liczbe spelniajaca kryterium: ");
  scanf("%d",&n);
 }}
m=n;
do{
 x=(double)rand()/(double)RAND_MAX-1;
 y=(double)rand()/(double)RAND_MAX-1;
 sum=pow(x,2)+pow(y,2);
 if(sum<1){
  s++;}
 m--;
}while(m>0);

pi=4*(double)s/(double)n;
printf("PI = %f\n",pi);

return 0;
}
