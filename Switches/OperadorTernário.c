#include <stdio.h>

int main(){

    int numjogador, numcomputador, resultado;
    char tipocomparação;

    // gerar número aleatório
    srand(time(0));
    numcomputador = rand() % 100 + 1; //Número entre 1 e 100

    printf("Bem-Vindo a esse jogo do caralho \n");
    printf("\n escolha um número e o tipo de comparação \n");
    printf("M - maior \n");
    printf("N - Menor \n");
    printf("I - Igual \n");

    printf("escolha o tipo de comparação: ");
    scanf("%c", &tipocomparação);

    printf("Escolha seu número(entre 1 e 100): ");
    scanf("%d", &numjogador);

    printf("\nO número do computador é: %d \n\n", numcomputador);

    switch (tipocomparação)
    {
    case 'M':
    case 'm':
        printf("Você escolheu Maior\n\n");
        resultado = numjogador > numcomputador ? 1:0 ;
        break;
    case 'N':
    case 'n':
        printf("Você escolheu Menor\n\n");
        resultado = numjogador < numcomputador ? 1:0 ;
        break;
    case 'I':
    case'i':
        printf("Você escolheu Igual\n\n");
        resultado = numjogador == numcomputador ? 1:0 ;

    default:
        break;
    }

    printf("O número do jogador é: %d; O número do computador é: %d \n", numjogador, numcomputador);

    if (resultado == 1)
    {
        printf("Parabéns, Você ganhou!\n");
    } else {
        printf("Você perdeu! MUITO BURRRO!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    }
    
    return 0;
}