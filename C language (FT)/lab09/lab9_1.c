#include <stdio.h>
#include <stdlib.h>

int suma (int *p, int len);
void proc_1 (int k, int t[][k], int w);
void proc_2 (int k, int t[][k], int w);
void print_tab_all(int y,int a[][y], int x);
int porownaj_1(const void *a , const void *b );
int porownaj_2(const void *a , const void *b );
//zdefiniowana w stdlib.h
//void qsort(void * base,size_t num, size_t width,int( * compare )( const void *, const void * ));
int K = 0;

int main(void) {
    int tab_A[3][6] = {{1,-4,1,2,11},{12,2,32,2},{72,2,-32,2}};
    int tab_B[4][3] = {{1,-24,1},{9,32,2},{5,64,1},{3,32,1}};

    print_tab_all(6, tab_A, 3);
    printf("\n");
    proc_1(6, tab_A, 3);
    print_tab_all(6, tab_A, 3);
    printf("\n");
    proc_2(6, tab_A, 3);
    print_tab_all(6, tab_A, 3);
    
    printf("\n\n");

    print_tab_all(3, tab_B, 4);
    printf("\n");
    proc_1(3, tab_B, 4);
    print_tab_all(3, tab_B, 4);
    printf("\n");
    proc_2(3, tab_B, 4);
    print_tab_all(3, tab_B, 4);
}

int suma (int *p, int len) { 
  int sum = 0;
  for (int i = 0; i < len; i++)
      sum += p[i];
return sum;
}

void print_tab_all(int y,int a[][y], int x){
 int i, j;
  for (i = 0; i < x; i++){
    for (j = 0; j < y; j++)
       printf ("%3d", a[i][j]);
    printf ("\n");   }
}

int porownaj_1(const void *a , const void *b ){
    return *(int*)a - *(int*)b;
}

void proc_1(int k, int t[][k], int w){
    for(int i = 0; i < w; ++i)
        qsort(t[i], k, sizeof(int), porownaj_1);
}

int porownaj_2(const void *a , const void *b ){
    int A = suma((int *) a, K);
    int B = suma((int *) b, K);
    return A - B;
}

void proc_2(int k, int t[][k], int w){
    K = k;
    qsort(t, w, k * sizeof(int), porownaj_2);
}