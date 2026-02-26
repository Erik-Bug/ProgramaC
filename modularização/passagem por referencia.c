#include <stdio.h>

void dobrar(int* x){
    *x = (*x) * 2;

}

int main(){
    int numero = 5;
    printf("O número antes da função: %d\n", numero);
    dobrar(&numero);
    printf("O número dobrado é: %d\n", numero);


    return 0;
}