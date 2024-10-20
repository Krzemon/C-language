#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 4096

typedef struct {
     char data[SIZE];
     int key;
} item;
 
item array[] = {
     {"Bill", 62},
     {"Hill", 60},
     {"Barcak", 42},
     {"Dicky", 105},
     {"W.", 1},
};
 
void sort(item *a, int n) { 
      int i = 0, j = 0;
      int s=1;

      for (; i < n && s != 0; i++) {
              s = 0;
              for (j = 0; j < n; j++) {
                       if (a[j].key > a[j+1].key) {
                               item t = a[j];
                               a[j] = a[j+1];
                               a[j+1] = t;
                               s++;
                       }
               }
              n--;
       }
}
   
int main()
{int i;

  for(i = 0; i < 5; i++)
    printf("TEST: Before sort array[%d] = {%s, %d}\n", i, array[i].data, array[i].key);

    sort(array,5); 
  for(i = 0; i < 5; i++)
    printf("TEST: After sort array[%d] = {%s, %d}\n", i, array[i].data, array[i].key);

    return(0);
}
