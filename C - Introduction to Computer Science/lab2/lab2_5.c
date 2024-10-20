#include <stdio.h>

int main(){
char n;
int a;
printf("wpisz litere trojkata: ");
do{
 scanf("%c",&n);
}while(n<65 || n>90);
a=n-64;

printf("wysokosc=%d\n",a);

for(int i=1; i<=a;i++){
 for(int j=1;j<=2*a+1;j++){
  if((j<i)||(j>2*a-i))
	printf(" ");
  else if(j<=a){
  char x = n-j+1;
  printf("%c",x);
  }
  else if(j>a){
  char y = n-2*a+1+j;
  printf("%c",y);
  }
 }
 printf("\n");
}

return 0;
}
