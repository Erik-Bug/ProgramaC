#include <stdio.h>

int main () {
    float nota1;
    float nota2;
    float nota3;
    float media;
    int qtd_estrelas;

    printf("Digite sua primeira nota\n");
    scanf("%f", &nota1);
    printf("Digite sua segunda nota\n");
    scanf("%f", &nota2);
    printf("Digite sua terceira nota\n");
    scanf("%f", &nota3);
   
    printf("quantas estrelas o aluno tem?\n");
    scanf("%d", &qtd_estrelas);

    media = (nota1 + nota2 + nota3) / 3.0;

    if (media >= 7.0) {
        printf("PARABÉNS!!! você passou. Sua nota foi: %.2f\n", media);
    } else {
        printf("BURRO!! Você não passou. Sua nota foi: %.2f\n", media);
    }

    if (qtd_estrelas > 10) {
        printf("O aluno é de alto ranking\n");
    } else {
        printf("O aluno é de baixo ranking\n");
    }

    return 0;
}