#include <stdio.h>

int main() {
    /*
    Incremento(++)
    Pré-incremento(++a)
    Pós-incremento(a++)
    Decremento(--)
    Pré-decremento(--a)
    Pós-decremento(a--)
    */
    int num1 = 1;
    int resultado;


printf("Antes do incremento: %d\n", num1);

    num1++;
printf("Depois do incremento: %d\n", num1);

    num1--;
printf("depois do decremento: %d\n", num1);




resultado = num1++;
printf("Apos o pós-incremento - num1: %d - Resultado: %d\n", num1, resultado);

resultado = ++num1;
printf("Apos o pré-incremento - num1: %d - Resultado: %d\n", num1, resultado);

resultado = num1--;
printf("Apos o pós-decremento - num1: %d - Resultado: %d\n", num1, resultado);

resultado = --num1;
printf("Apos o pré-decremento - num1: %d - Resultado: %d\n", num1, resultado);


return 0;
}