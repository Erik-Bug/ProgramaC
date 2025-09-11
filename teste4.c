#include <stdio.h>

void main(){
    char letra;
    int num;

    printf("entre com uma letra e um inteiro\n");
    scanf("%c, %d", &letra, &num);

    printf("você informou a letra %c e numero %d\n", letra, num);

    return 0;
}