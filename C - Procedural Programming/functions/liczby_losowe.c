// Generowanie liczb losowych

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand_i(int a, int b){//funkcja losujaca integery z zakresu <a, b>
return (a + rand()%(b-a+1));}

double rand_d(double a, double b){//funkcja losujaca double z przedziału <a, b>
double r = (double)rand() / RAND_MAX;//liczba z przedziałuu <0.0, 1.0>
return r * (b - a) + a;}

int main(void){
printf ("\n----10 liczb integer z przedzialu <7, 15>-------------\n");
//10 liczb integer z przedzialu <7, 15>
for (int i = 0; i<10; i++)
printf ("%4d liczba = %4d\n",i, rand_i(7, 15 ));
printf ("\n----10 liczb double z przedzialu <0.0, 1.0>-------------\n");
//10 liczb double z przedzialu <0.0, 1.0>
for (int i = 0; i<10; i++)
printf ("%4d liczba = %.4lf\n",i, rand_d(0.0, 1.0 ));
printf ("\n----10 liczb double z przedzialu <7.0, 15.0>-------------\n");
//10 liczb double z przedzialu <7.0, 15.0>
for (int i = 0; i<10; i++)
printf ("%4d liczba = %.4lf\n",i, rand_d(7.0, 15.0));
return; }