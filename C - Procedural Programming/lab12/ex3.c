#include <stdio.h>
#include <stdlib.h>

int main(){
double test[] = {1.0,2.3,2.1,5.2,1.9,2.9,4.3,4.4,5.0,5.2,3.5};

FILE *ptr_txt ; //wskaznik do pliku tekstowego
FILE *ptr_bin ; //wskaznik do pliku binarnego
int i;
size_t test_len = sizeof(test)/sizeof(*test);

//zapis tablicy test do pliku binarnego
ptr_bin = fopen ("b_1","wb");
fwrite(test, 1, sizeof(test), ptr_bin);
fclose(ptr_bin);

//zapis tablicy test do pliku tekstowego
ptr_txt = fopen ("t_1","w");
for (i = 0; i < test_len; i++)
fprintf (ptr_txt, "%.1f ", test[i]);
fclose(ptr_txt);
}<br> 