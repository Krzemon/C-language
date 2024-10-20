#include <stdio.h>

int main(){
int n,suma=0;
printf("Wpisz liczbe: ");
scanf("%d",&n);
printf("Liczby pierwsze: ");
for(int i=2; i<=n;i++){
    int x=0;
    for(int j=2; j<i;j++){
        if(i%j==0)
	  x++;
    }
    if(x==0){
	suma=suma+i;
	printf("%d ",i);}
}
printf("Ich suma wynosi %d\n", suma);
return 0;
}
