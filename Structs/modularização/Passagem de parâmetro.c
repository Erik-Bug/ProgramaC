#include <stdio.h>

void dobrar(int x){
    x = x * 2;
    printf("O número dentro da função é: %d\n", x);
}

int main(){
    int numero = 5;
    printf("Número antes da função: %d\n", numero);
    
    dobrar(numero);

    printf("Número depois da função: %d\n", numero);


    return 0;
}