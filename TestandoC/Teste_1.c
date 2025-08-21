#include <stdio.h> 
int main() {
    
    int idade;
    float altura;
    char nome[30];
    double peso;
    char tiposangue[3];

    printf("Digite seu nome: \n");
    scanf("%s", &nome);

    printf("Digite sua idade: \n");
    scanf("%d", &idade);

    printf("Digite seu peso: \n");
    scanf("%lf", &peso);

    printf("Digite sua altura: \n");
    scanf("%f", &altura);

    printf("Digite seu tipo sanguíneo: \n");
    scanf("%s", &tiposangue);

printf("\n");
    printf("Nome: %s - Tipo sanguíneo: %s\n", nome, tiposangue);
    printf("Idade: %d\n", idade);
    printf("Peso: %.2lf - Altura: %.2f\n", peso, altura);
printf("\n");
    
return 0;
} 