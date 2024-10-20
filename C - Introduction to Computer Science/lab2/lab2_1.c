#include <stdio.h>

int main(){
int n;
printf("wpisz liczbe: ");
scanf("%d", &n);
printf("Liczby podzielne przez 6: ");
for(int i=0; i<n; i++){
	if(i%6==0)
		printf("%d ",i);
}
printf("\n");
return 0;
}
