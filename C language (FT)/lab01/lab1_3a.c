#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 10
#define MIN -20.0
#define MAX 20.0

//Pointer version

double suma(double*,int,double*,double*,double*,double*,double*);
double d_rand(double,double);

int main(void){
  double tab[N];
  int i=-1;
  srand(time(NULL));
  for(double *p=tab;p<tab+N;p++){*p=d_rand(MIN, MAX);}
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

double suma(double *tab,int n,double *min,double *max,double *mean,double *s_min,double *s_max){
  double sum=0,*p = NULL;
  *min = *tab; 
  *max = *tab;
  *s_min = fabs(*(tab+n-1)-*tab);
  *s_max = fabs(*(tab+n-1)-*tab);
    int i=-1;
    for(p=tab;p<tab+n;p++){
      sum+=*p;
      if(*p < *min)
        *min = *p;
      if(*p > *max)
        *max = *p;
    }  
      *mean = sum/n;
      i=-1;
      int d;
    while(++i<n){
      d = fabs((float)(*p-*mean));
      if(d < *s_min)
        *s_min = d;
      if(d > *s_max)
        *s_max = d;
    }  
  return sum;
}
