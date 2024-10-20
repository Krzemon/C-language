#include <stdio.h>

int main(void){
    printf("Hello world!\n");
    int i1 = -100;
    int i3;
    printf("Zmienna całkowita i1 jest zainicjalizowana od razu przy deklaracji i ma wartość %d\n",i1);
    printf("Zmienna całkowita i3 jest zadeklarowana, ale nie zainicjalizowana i ma  wartość %d\n",i3);

    i3=200;
    printf("Nadałem i3 wartość %d\n",i3);

    int i4=i1+i3;
    printf("Suma i1 i i3 wynosi %d\n",i4);


    float f1 = -100;
    float f3;
    printf("Zmienna zmiennoprzecinkowa f1 jest zainicjalizowana od razu przy deklaracji i ma wartość %f\n",f1);
    printf("Zmienna zmiennoprzecinkowa f3 jest zadeklarowana, ale nie zainicjalizowana i ma  wartość %f\n",f3);

    f3=200.;
    printf("Nadałem f3 wartość %f\n",f3);

    float f4=f1+f3;
    printf("Suma f1 i f3 wynosi %f\n",f4);
    
    int i5=i1-i3;
    printf("Roznica i1 i i3 wynosi %d\n",i5);
    
    float f5=f1-f3;
    printf("Roznica f1 i f3 wynosi %f\n",f5);
    
    int i6=i1/i3;
    printf("Wynik dzielenia i1 przez i3 wynosi %d\n",i6);

    float f6=f1/f3;
    printf("Wynik dzielenia f1 przez f3 wynosi %f\n",f6);
    
    float f7=i1/i3;
    printf("Wynik dzielenia i1 przez i3 wynosi %f\n",f7);
    
    float f8=(float)i1/i3;
    printf("Wynik dzielenia i1 przez i3 wynosi %f\n",f8);


    return 0;
}
