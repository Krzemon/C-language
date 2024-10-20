 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 
 int main()
  { // 'm' modifier ---> allocate memory
  char* ptr = NULL;
  scanf("%ms", &ptr );
  printf("%s %d\n", ptr, strlen(ptr));
  // WARNING: caller got to free the buffer.
  free(ptr);
 return 0;}