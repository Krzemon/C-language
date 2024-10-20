#include <stdio.h>
#include <string.h>
#include <ctype.h>

int spaces(char *s){
 int x=0,n=0;
 while(s[n]!='\0'){
  if(s[n]==' ')
   x++;
  n++;
 }
 return x;
}

int numbers(char *s){
 int x=0,n=0;
 while(s[n]!='\0'){
  if(isdigit(s[n])!=0)
   x++;
  n++;
 }
 return x;
}

int letters(char *s){
 int x=0,n=0;
 while(s[n]!='\0'){
  if(isalpha(s[n])!=0)
   x++;
  n++;
 }
 return x;
}

int main(){
 
 char str[]="Jestem stringiem";
 int n;
 printf("Wybuerz opcje:\n");
 printf("1 - Liczba spacji\n");
 printf("2 - Liczba liter\n");
 printf("3 - Liczba cyfr\n");
 scanf("%d",&n);
 switch(n){
  case 1:
    printf("Liczba spacji: %d",spaces(str));
   break;
  case 2:
    printf("Liczba liter: %d",letters(str));
   break;
  case 3:
    printf("Liczba cyfr: %d",numbers(str));
   break;
  default:
   printf("nie ma takiej opcji\n");
 }
 return 0;
}