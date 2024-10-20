// Funkcja licząca sumę elementów jednowymiarowej tablicy liczb double

double suma (double *tab, int len) { 
  double ss = 0.0;
  for (int i = 0; i < len; i++)  
    ss+= tab[i]; 
 return ss;}