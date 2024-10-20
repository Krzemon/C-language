#include <stdio.h>

int main(void){
    float a = -1.8e-10;
    printf("Pojedyncza precyzja: %f = %.10f = %.20f\n", a, a, a);

    double b = -1.8e-10;
    printf("Podwojna precyzja: %f = %.10f = %.20f\n", b, b, b);

    long double c = -1.8e-10;
    printf("long double: %Lf = %.10Lf = %.20Lf\n\n", c, c, c);

    printf("Notacja wykladnicza: %e = %e = %Le\n\n", a, b, c);

    b = 5./3;
    printf("5 dzielone przez 3 = %f\n\n", b);

    printf("Wpisz liczbe rzeczywista: ");
    scanf("%lf", &b);
    printf("Wpisales: %f.\n", b);

    int calkowita;
    printf("Wpisz liczbe calkowita: ");
    scanf("%d", &calkowita);
    printf("Wpisales: %d.\n", calkowita);

    return 0;
}
