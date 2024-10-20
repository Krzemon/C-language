#include <stdio.h>
void swap (int *p, int *q) { 
    int temp = *p;
    *p = *q;
    *q = temp;
return;}

void print_tab_all(int y,int a[][y], int x){
    int i, j;
    for (i = 0; i < x; i++){
        for (j = 0; j < y; j++)
            printf ("%3d", a[i][j]);
        printf ("\n");   }
return;}

void swap_tab(int *A, int *B, int n) {
    for(int i=0; i<n; ++i)
        swap(A+i, B+i);
}

void swap_rows(int n, int (*TAB)[n], int x, int y) {
    swap_tab(TAB[x], TAB[y], n);
}

int main() {
    int tab_1[4][5] = {{1,1,1,1,1},{2,2,2,2,2},{3,3,3,3,3},{4,4,4,4,4}};
    print_tab_all(5, tab_1, 4); printf("\n");
    swap_rows(5, tab_1, 1, 3);
    print_tab_all(5, tab_1, 4); printf("\n");
    int tab_22 [5][2] = {{1,1},{2,2},{3,3},{4,4},{5,5}};
    print_tab_all(2, tab_22, 5); printf("\n");
    swap_tab(tab_22[1], tab_22[2], 2);
    print_tab_all(2, tab_22, 5); printf("\n");
}
