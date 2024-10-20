#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 10


int main(){
 
 double TAB[N]={0},suma=0,srednia=0,odchylenie=0,pom=0;;
 
 srand(time(NULL));
 for(int i=0; i<N; i++){
  TAB[i] = 3*(double)rand()/RAND_MAX-1.5;
  //printf("%f\n",TAB[i]);
  suma+=TAB[i];
 }
 
 srednia = suma/N;
 
 for(int i=0; i<N; i++){
  pom += pow(TAB[i] - srednia,2);
 }
 
 odchylenie = pom/N;
 
 printf("Suma wynosi: %f\n",suma);
 printf("Srednia wynosi: %f\n",srednia);
 printf("Odchylenie standardowe wynosi: %f\n", odchylenie);
 
 return 0;
}
