#include <stdio.h>

int main() {

    int opcao;
    float saldo = 10000.00;
    float deposito;
    float saque;
    

    printf("Digite 1: verificar saldo\n");
    printf("Digite 2: fazer depósito\n");
    printf("Digite 3: fazer saque\n");
    scanf("%d", &opcao);


    switch (opcao)
    {
    case 1:
        printf("O deu saldo é de: R$ %.2f\n", saldo);
        break;
    case 2:
        printf("Quanto deseja depositar: R$");
        scanf("%f", &deposito);
        printf("Agora seu saldo é de: R$ %.2f", saldo + deposito);
        break;
    case 3:
        printf("Digite o valor a sacar: R$ ");
        scanf("%f", &saque);
        printf("Agora o seu saque é de: R$ %.2f\n", saldo - saque);
        break;
    default:
        printf("Opçaõ Invalida!");
        break;
    }

    return 0;
}