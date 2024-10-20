#include <stdio.h>

#define N 5
#define M 5

// deklaracje funkcji
void swap(int *a, int *b);
void wypiszTAB_5x5(int (*TAB)[M]);

int main(){

    int abc[N][M];
    printf("\n-------------------- Stan po inicjalizacji ------------------------------\n\n");

    for(int row = 0; row < N; ++row)
        for(int i = 0; i < M; ++i)
            abc[row][i] = i; 

    wypiszTAB_5x5(abc);
    printf("\n------------------------ transpozycja -----------------------------------\n\n");
    

    for(int row = 0; row < N; ++row)
        for(int col = 0; col < M ; ++col)
            if (row == col)
                continue;
            else if(row < col)
                swap(&abc[row][col], &abc[col][row]);

    wypiszTAB_5x5(abc);
    printf("\n");

    printf("\n-------------------- elementy ponad diagonalne  -------------------------\n\n");

    for(int d = 1; d < M; ++d)
        printf("%d, ", *(*(abc + d - 1) + d) );
        
    printf("\n");

return 0;
}


void swap(int*a, int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
return;
}

void wypiszTAB_5x5(int (*TAB)[M]){
    for(int row = 0; row < N; ++row){ 
        for(int i = 0; i < M; ++i){
            printf("TAB[%d][%d] = %d",row, i,TAB[row][i]);
            if(i == M-1)
                continue;
            else
                printf(", ");
        }
        // printf("\b\b"); to tu nie dziala, w petli juz tak, czemu?
        printf("\n");
    }
}



