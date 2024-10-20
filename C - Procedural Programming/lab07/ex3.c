#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int rand_i(int a, int b);
void wypisz_i (int *poczatek, int *koniec);
int (*multi_tab_all(int k1,int a[][k1], int w1, int k2,int b[][k2], int w2))[];
void print_tab2d_all(int y,int a[][y], int x);

int main(){

    int tab_A [2][3] = {{1,2,3},{4,5,6}};
    int tab_B [3][4] = {{1,1,1,1},{1,1,1,1},{1,1,1,1}};
    printf("\n  tab_A [2][3] = \n");
    print_tab2d_all(3, tab_A, 2);
    printf("\n  tab_B [3][4] = \n");
    print_tab2d_all(4, tab_B, 3);
    printf("\n  ---------  \n");
    
    printf("\n  tab_A * tab_B = \n");
    int (*result_1)[];
    result_1 = multi_tab_all(3,tab_A,2, 4,tab_B,3);
    
    print_tab2d_all (4,result_1,2);
    printf("\n  --------- ---------------\n");

    int tab_C [4][2] = {{1,2},{2,5},{1,0},{1,5}};
    int tab_D [2][2] = {{1,-1},{1,0}};
    printf("\n  tab_C [4][2] = \n");
    print_tab2d_all(2, tab_C, 4);
    printf("\n  tab_D [2][2] = \n");
    print_tab2d_all(2, tab_D, 2);
    printf("\n  ---------  \n");
    
    printf("\n  tab_C * tab_D = \n");
    int (*result_2)[];
    result_2 = multi_tab_all(2,tab_C,4, 2,tab_D,2);
    
    print_tab2d_all (2,result_2,4);    
    

    free(result_1);
    free(result_2);

    return 0;
}

void print_tab2d_all(int y,int a[][y], int x){//x wierszy o dlugosci y
    int i, j;
    for (i = 0; i < x; i++){
        for (j = 0; j < y; j++)
            printf ("%3d", a[i][j]);
        printf ("\n"); 
    }
return;}

int (*multi_tab_all(int k1,int a[][k1], int w1,
                     int k2,int b[][k2], int w2))[]{ // a * b
    if(k1 != w2){
        printf("niedozwolone mnozenie\n");
        return NULL;
    }
    int (*TAB)[k2] = calloc (w1 * k2,sizeof(int));
    for(int i = 0; i < w1; ++i){
        for(int j = 0; j < k2; ++j){
            TAB[i][j] = 0;
            for(int l = 0; l < k1; ++l)
                TAB[i][j] += a[i][l] * b[l][j];
        }
    }
    return TAB;
}
