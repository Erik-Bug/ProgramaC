#include <stdio.h>

int main(){
    char ProdutoA[30] = "produto A";
    char ProdutoB[30] = "Produto B";

    unsigned int EstoqueProdutoA = 2000;
    unsigned int EstoqueProdutoB = 4000;

    float PreçoProdutoA = 10.50;
    float PreçoProdutoB = 8.50;

    unsigned int EstoqueMinimoA = 1000;
    unsigned int EstoqueMinimoB = 5000;

    double ValorTotalA;
    double ValorTotalB;

    int resultadoA, resultadoB;

    printf("Produto %s tem estoque %u e o valor unitário é R$ %.2f\n", ProdutoA, EstoqueProdutoA, PreçoProdutoA);
    printf("Produto %s tem estoque %u e o valor unitário é R$ %.2f\n", ProdutoB, EstoqueProdutoB, PreçoProdutoB);


    resultadoA = EstoqueProdutoA > EstoqueMinimoA;
    resultadoB = EstoqueProdutoB > EstoqueMinimoB;

    printf("O produto %s tem estoque mínimo %d\n", ProdutoA, resultadoA);
    printf("O produto %s tem estoque mínimo %d\n", ProdutoB, resultadoB);

    return 0;
}