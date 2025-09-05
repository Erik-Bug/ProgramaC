#include <stdio.h>

int main(){
    int num1, num2;

    printf("digite o primeiro número:\n");
    scanf("%d", &num1);
    printf("digite o segundo número:\n");
    scanf("%d", &num2);

    if (num1 > num2) {
    printf("número 1 é MAIOR que número 2\n");
    }

    if (num1 < num2) {
    printf("Número 1 é MENOR que número 2\n");
    }

    if (num1 == num2) {
    printf("Os dois números são iguais\n");
    }

    return 0;
    
}