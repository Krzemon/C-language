#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define N 30

int main(){
int x[N],y[N],s[N],m;
srand(time(NULL));
x[0]=0;
y[0]=0;
while(x[0]==0){x[0]=rand()%10;}
while(y[0]==0){y[0]=rand()%10;}

for(int i=1;i<N;i++){x[i]=rand()%10;}
for(int i=1;i<N;i++){y[i]=rand()%10;}

printf("Wylosowane liczby:\n");

for(int i=0;i<N;i++){printf("%d",x[i]);}
printf("\n");
for(int i=0;i<N;i++){printf("%d",y[i]);}
printf("\n");

s[N-1]=(x[N-1]+y[N-1])%10;
int w;
for(int i=28;i>=0;i--){
 if((x[i+1]+y[i+1])>9){w=x[i]+y[i]+1; s[i]=w%10;}
 else{w=x[i]+y[i]; s[i]=w%10;}}

printf("Suma tych liczb wynosi:\n");
if((x[0]+y[0])>9)
 printf("1");
for(int i=0;i<N;i++){printf("%d",s[i]);}
printf("\n");
return 0;
}
