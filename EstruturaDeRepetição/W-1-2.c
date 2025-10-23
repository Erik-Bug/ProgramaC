#include <stdio.h>
int main(){
    int num;

    do
    {
        printf("Digite um número par para sair do programa: ");
        scanf("%d", &num);

        if (num % 2 == 0)
        {
            printf("O número %d é par\n", num);
        } else
        {
            printf("O numero %d é ímpar\n", num);
        }
        
        
    } while (num % 2 != 0);
    
    return 0;
}