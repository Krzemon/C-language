#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *wynik(char *x, char *y) {
    char *ex = "";
    int L1 = strlen(*x);
    int L2 = strlen(*y);
    if(L1>=L2){
	const char * strstr(char *x, char *y);
	ex = "lancuch pierwszy zawiera w sobie lancuch drugi";
    }
    
    else{
    	ex = "lancuch drugi zawiera w sobie lancuch pierwszy";
    }

    return ex;
}



int main(int argc, char *argv[]) {
    char *p1 = argv[0];
    char *p2 = argv[1];
    printf("Wczytane ciagi znakow:\n");
    printf("argv[0]: %s \n",argv[0]); 
    printf("argv[1]: %s \n",argv[1]); 

    printf("wynik: %s\n",*wynik(p1,p2));
    free(p1);
    free(p1);
    return 0;
}
