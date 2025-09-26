#include <stdio.h>

int main() {

    int opcao;
    int numerodecreto;
    int palpite;

    printf("1. Iniciar jogo\n");
    printf("2. Regras do jogo\n");
    printf("3. Sair do jogo\n");
    printf("Selcione uma opçaõ: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        srand(time(0));
        numerodecreto = rand() % 10;
        printf("Digite um número de 0 a 9: ");
        scanf("%d", &palpite);
        printf("Número da maquina: %d\n", numerodecreto);
        if (numerodecreto == palpite)
        {
            printf("Parabéns!!! Você Ganhou!!");
        } else
        {
            printf("Você perdeu! tente Novamente");
        }
        
        
        break;
    
    default:
        break;
    }
    
    return 0;
}