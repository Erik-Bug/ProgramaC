#include <stdio.h>

int main() {
    int num;

    printf("digite um número:");
    scanf("%d", &num);

    switch (num)
    {
    case 1:
        printf("Seu número é 1\n");
        break;
    case 2:
        printf("seu número é 2\n");
        break;
    
    default:
        printf("seu número não consta\n");
        break;
    }

    return 0;
}