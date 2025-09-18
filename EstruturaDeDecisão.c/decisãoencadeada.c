#include <stdio.h>

int main(){
    int estrelas;

    printf("\nBem vindo ao cadastro de estrelas do ranking.\n");
    
    printf("Digite a quantidade de estrelas:\n");
    scanf("%d", &estrelas);

    if (estrelas == 0) {
        printf("sem ranking\n");
    } else if (estrelas > 0 && estrelas < 5){
        printf("Low rank");
    } else if (estrelas > 5 && estrelas < 15){
        printf("Average rank");
    } else if (estrelas > 15 && estrelas < 30){
        printf("Medium rank");
    } else if (estrelas > 30 && estrelas < 50){
        printf("High rank");
    } else if (estrelas > 50){
        printf("Peak God");
    } else {
        printf("Out ranking");
    }
    
    
    return 0;
}

