#include <stdlib.h>
#include <stdio.h>

double *my_alloc(int i_min, int i_max) {
    double *p = malloc((i_max-i_min+1) * sizeof(double));
    return p - i_min;
}


void my_free(double **my_tab, int i_min) {
    // if(my_tab == NULL) return; // better safe than sorry
    if(*my_tab == NULL) return;
    free(*my_tab + i_min);
    *my_tab = NULL;
}

int main() {
    double *tab = my_alloc(-5, 2);
    for(int i = -5; i <= 2; ++i)
        tab[i] = 0.0;
    my_free(&tab, -5);
    my_free(&tab, -5);
}
