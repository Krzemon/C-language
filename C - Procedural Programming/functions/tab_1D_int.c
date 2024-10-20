// Procedura wypisująca tablicę jednowymiarową integer'ów

void wypisz_i (int *poczatek, int *koniec) {
while (poczatek < koniec)
printf ("%4d", *poczatek++);
printf ("\n");
return;}