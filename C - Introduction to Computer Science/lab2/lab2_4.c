#include <stdio.h>

int main(){
int n;
do{
 printf("wpisz wysokosc trojkata: ");
 scanf("%d",&n);
}while(n<0);

printf("wysokosc=%d\n",n);

for(int i=1; i<=n;i++){
 for(int j=1;j<=2*n+1;j++){
  if((j<i)||(j>2*n-i))
	printf(" ");
  else
	printf("*");
 }
 printf("\n");
}
return 0;
}
