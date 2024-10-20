#include <stdio.h>
void swap (int *p, int *q) { 
    int temp = *p;
    *p = *q;
    *q = temp;
return;}
int suma (int *tab, int len) { 
    int ss = 0.0;
    for (int i = 0; i < len; i++)  
        ss+= tab[i]; 
return ss;}


void print_tab_all(int y,int a[][y], int x){
    int i, j;
    for (i = 0; i < x; i++){
        for (j = 0; j < y; j++)
            printf ("%3d", a[i][j]);
//        printf("%4d", suma(a[i], y));
        printf ("\n");   }
return;}

void swap_tab(int *A, int *B, int n) {
    for(int i=0; i<n; ++i)
        swap(A+i, B+i);
}
void swap_rows(int n, int (*TAB)[n], int x, int y) {
    swap_tab(TAB[x], TAB[y], n);
}


void sort_by_sum(int y,int a[][y], int x) {
    for(int i = 0; i < x-1; ++i) {
        int min_i = i;
        int min_v = suma(a[i], y), v;
        for(int j = i+1; j < x; ++j)
            if(min_v > (v = suma(a[j], y)))
                min_i = j, min_v = v;
        swap_rows(y, a, i, min_i);
    }
}

int main() {
    int tab_A[3][6] = {{1,-4,1,2,11},{12,2,32,2},{72,2,-32,2}};
    print_tab_all(6, tab_A, 3); printf("\n");
    sort_by_sum(6, tab_A, 3);
    print_tab_all(6, tab_A, 3); printf("\n");
    int tab_B[4][3] = {{1,-24,1},{9,32,2},{5,64,1},{3,32,1}};
    print_tab_all(3, tab_B, 4); printf("\n");
    sort_by_sum(3, tab_B, 4);
    print_tab_all(3, tab_B, 4); printf("\n");
    
}
