#include <stdio.h>

int main() {
   /*
   Atribuição simples(=)
   Atribuição de soma(+=)
   Atribuição de subtração(-=)
   Atribuição de multiplicação(*=)
   Atribuição de divisão(/=)
   */
   
    int num1;
    int num2;
    int resultado;

resultado = 10;

printf("O resultado é: %d \n", resultado);

resultado +=20;
printf("O resultado é: %d \n", resultado);

resultado -=10;
printf("O resultado é: %d \n", resultado);

resultado *=5;
printf("O resultado é: %d \n", resultado);

resultado /=4;
printf("O resultado é: %d \n", resultado);
return 0;
}