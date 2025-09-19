#include <stdio.h>

int main() {
    // idade deve ser maior que 18 e menor que 65
    // renda menor 3000
    // dependencias devem ser maior que 2

    int idade;
    int renda;
    int dependencia;

    printf("Digite sua idade: \n");
    scanf("%d", &idade);
    printf("Digite sua renda mensal: \n");
    scanf("%d", &renda);
    printf("Digite a quantidade de dependendcias: \n");
    scanf("%d", &dependencia);

    if (idade >= 18 && idade < 65 ){ 
        if (renda < 3000){
            if (dependencia > 2)
            {
                printf("Você cumpre a todos os requisitos");
            } else {
                printf("você não cumpre aos requisitos de dependencia");
            }
    } else {
        printf("Os requisitos de renda não são atendidos");
    } 
    
    } else {
        printf("os requisitos de idade não são atendidos");
    }
    

    return 0;
}