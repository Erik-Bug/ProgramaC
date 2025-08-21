#include <stdio.h>
    int main() {
        
        int num1, num2;
        int soma, subtração, divisão, multiplicação;

        printf("digite o num1: \n");
        scanf("%d", &num1);
        printf("digite o num2: \n");
        scanf("%d", &num2);
        // operação de soma
        soma = num1 + num2;

        //operção de subtração
        subtração = num1 - num2;

        // operação de divisão
        divisão = num1 / num2;

        // operação de multiplicação
        multiplicação = num1 * num2;


printf("\nO resultado da soma é: %d \n", soma);
printf("\nO resultado da subtração é: %d \n", subtração);
printf("\nO resultado da divisão é: %d \n", divisão);
printf("\nO resultado da multiplicação é: %d \n", multiplicação);


return 0; 
    }
