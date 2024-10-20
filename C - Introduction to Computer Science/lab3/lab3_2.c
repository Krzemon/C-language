#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

int main(){
 double tab[10],tmp,suma=0,srednia;
 srand(time(NULL));
for(int i=0;i<10;i++){ 
 tab[i]=200*(double)rand()/(double)RAND_MAX-100;
 suma+=tab[i];
 if(tab[i]>=0)
  printf("tab[%d]= %5.2f\n",i,tab[i]);
 else
  printf("tab[%d]=%5.2f\n",i,tab[i]);
}

printf("Teraz tablice posortowane\n");

for(int i=0;i<9;i++){
 for(int j=i+1;j<10;j++){
  if(tab[i]>tab[j]){
   tmp=tab[i];
   tab[i]=tab[j];
   tab[j]=tmp;
  }
 }
}
for(int i=0;i<10;i++){ 
 if(tab[i]>=0)
  printf("tab[%d]= %5.2f\n",i,tab[i]);
 else
  printf("tab[%d]=%5.2f\n",i,tab[i]);
}

srednia = suma/10;
printf("Srednia = %5.6f\n",srednia);

double x = srednia-tab[0];
int xn;
for(int i=1;i<10;i++){
 if(tab[i]<x){
  x=srednia-tab[i];
  xn=i;}
}

printf("Element tab najblizszy sredniej ma indeks %d i jest rowny %f\n",xn, tab[xn]);


return 0;
}
