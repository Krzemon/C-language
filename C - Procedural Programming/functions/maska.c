#include <stdio.h>
                                            
 unsigned bits(unsigned int x, unsigned int n);  //nalezy zbudowac i wykorzystac maske bitowa 
 void write_binar (unsigned int n, char *wsk); //nalezy zbudowac i wykorzystac maske bitowa 
 
int main () { 
  unsigned int number, bit_num, result ;                   // deklaracje 
  char number_str [sizeof(unsigned)+1]; 
  //przygotowujemy tablice , ktorej rozmiar odpowiada ilo�ci bitow, na kt�rych zapisana jest liczba (typ liczby), ktora bedzie zamienianana string
  number_str [sizeof(unsigned)] = '\0';//wstawiamy na koniec znak konca stringu
 
 scanf("%u",&number) ;         //wcztanie liczby
  
 scanf("%u",&bit_num) ;         //wcztanie ilosci bitow do wypisania
  
 write_binar (number,number_str);     //zamiana liczby na string procedura write_binar 
 printf("liczba wczytana %u : %s \n", number, number_str);             
 result = bits (number,  bit_num);  
 write_binar (result,number_str);                     //zamiana wyniku na string procedura write_binar 
 printf("%u nowa liczba %s\n", result, number_str);               
 return 0; }
 

void write_binar(unsigned int n, char * wsk)
{   int i;
    static int liczba = 8 * sizeof(unsigned);
    for (i = liczba - 1; i >= 0; i--, n >>= 1)
        wsk[i] = (01 & n) + '0';
     
    return;
}

unsigned bits(unsigned int x, unsigned int n){
  	
	unsigned int mask = 1;

	for (int i = 0; i < n-1; i++) 
		mask = mask<<1 | 1;
	
 		
	x >>= (8 * sizeof(unsigned) - n) ; 
	x = x&mask;
	return x;
} 