#include <stdio.h>
int main(){
    int i, num;

    printf("Digite um número para ser tabuado: ");
    scanf("%d", &num);

    for (i = 0; i <= 10; i++)
    {
        printf("%d X %d = %d\n", i, num, i * num);
    }
    
    return 0;
}
