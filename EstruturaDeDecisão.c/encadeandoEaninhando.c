#include <stdio.h>

int main() {
    int numero;

    printf("digite um número: ");
    scanf("%d", &numero);
    
    if (numero > 0){
        if (numero % 2 == 0){
            printf("Número Par, ");
        } else {
            printf("Número Impar, ");
        }
        printf("Positivo");
    } else if(numero == 0){
        printf("Nulo");
    } else{
        printf("Negativo");
    }
    

    return 0;
}
