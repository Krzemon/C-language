#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define N 4

void oct(int p){
	char tab[N+1];

	//TU EDYTOWAC

	printf("%4d = %s\n", p, tab);
}

int main(void){
	for(int i=-2; i<=4097; i++)
		if((i%2==0 && i<10) || i>4093 || i%2000==0)
			oct(i);
	return 0;
}
