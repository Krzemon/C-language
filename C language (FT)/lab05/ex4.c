#include <stdio.h>
#include <stdlib.h>

double *my_alloc(int,int);

int main(void) {
  int i_min = -5;
  int i_max = 2;
  int n = i_max - i_min + 1;
  double *tab = my_alloc(i_min, n);

  for (int i = i_min; i <= i_max; i++) {
    tab[i] = i * 1.5;
  }
  for (int i = i_min; i <= i_max; i++) {
    printf("tab[%d] = %.2f\n", i, tab[i]);
  }
    free(tab + i_min);
    return 0;
}

double *my_alloc(int i_min, int n) {
  double *ptr = (double *)malloc(n * sizeof(double));
  return ptr - i_min;
}
