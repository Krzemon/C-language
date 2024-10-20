#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 10
#define MIN -20.0
#define MAX 20.0

//Array version

double suma(double[],int,double*,double*,double*,double*,double*);
double d_rand(double,double);

int main(void){
  double tab[N];
  int i=-1;
  srand(time(NULL));
  while(++i<N){tab[i]=d_rand(MIN, MAX);}
  double sum,min,max,mean,s_min,s_max;
  sum = suma(&tab[0], N, &min,&max,&mean,&s_min,&s_max);
  printf("the sum of the elements of the tab array is: %g\n",sum);
  printf("the average of the elements of the tab array is: %g\n",mean);
  printf("the minimum value of the tab array is: %g\n",min);
  printf("the maximum value of the tab array is: %g\n", max);
  printf("the minimum deviation of tab table values is: %g\n",s_min);
  printf("the maximum deviation of tab table values is: %g\n",s_max);

  return 0;
}

double d_rand(double min, double max){
  double r = (double) rand()/RAND_MAX;
  return r*(max-min) + min;
}

double suma(double tab[],int n,double *min,double *max,double *mean,double *s_min,double *s_max){
  double sum=0;
  *min = tab[0]; 
  *max = tab[0];
  *s_min = fabs(tab[n-1]-tab[0]);
  *s_max = fabs(tab[n-1]-tab[0]);
    int i=-1;
    while(++i<n){
      sum+=tab[i];
      if(tab[i] < *min)
        *min = tab[i];
      if(tab[i] > *max)
        *max = tab[i];
    }  
      *mean = sum/n;
      i=-1;
      int d;
    while(++i<n){
      d = fabs((float)(tab[i]-*mean));
      if(d < *s_min)
        *s_min = d;
      if(d > *s_max)
        *s_max = d;
    }  
  return sum;
}
