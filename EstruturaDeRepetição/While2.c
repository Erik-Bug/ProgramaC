#include <stdio.h>

int main(){
    int num;

    printf("Digite um número (negativo para sair) ");
    scanf("%d", &num);

    while(num >= 0){
        printf("Você digitou: %d\n", num);

        printf("Digite um Número (negativo para sair): ");
        scanf("%d", &num);
    }
    
    return 0;
}