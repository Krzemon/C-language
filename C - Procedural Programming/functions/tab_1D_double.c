// Procedura wypisująca tablicę jednowymiarową double'ów

void wypisz_d (double *poczatek, double *koniec) {
while (poczatek < koniec)
printf ("%6.2f", *poczatek++);
printf ("\n");
return;}