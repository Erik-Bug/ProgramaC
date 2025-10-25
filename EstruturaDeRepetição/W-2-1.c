#include <stdio.h>
int main(){
    int i, j;

    char letra;

    for(int i = 1; i <= 5; i++){
        letra = 'A';
        
        for(int j = 1; j <= i; j++){
            printf("%c", letra);
            ++letra;
        }
        printf("\n");
    }
    return 0;
}