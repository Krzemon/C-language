#include <stdio.h>
#include <math.h>

int main(){
 int n;
 int i=1;
 float suma=0;
 printf("Podaj liczbe: ");
 scanf("%d",&n);
 while(i!=n){
  suma = suma +1.0/pow(i,2);
  i++;
 }
 printf("Suma %d elementow = %.8f\n",n,suma);

return 0;
}
