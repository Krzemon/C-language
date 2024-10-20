    #include <stdio.h>
    #include <stdlib.h>
   
    #define BIGNUM 5000

   // prototypy funkcji
   void fun_error (int tab[]);

   int main (void)
   {
      int tab[10];
      fun_error (tab);
      exit (EXIT_SUCCESS);
   }

    void fun_error (int table[])
    {
      int i;
      for (i = 0; i < BIGNUM; ++i)
      table[i] = i;
    }
