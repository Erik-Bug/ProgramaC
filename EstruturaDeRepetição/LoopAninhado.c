#include <stdio.h>

int main(){
    for(int i = 1; i <= 10; i++){ //loop Externo
        for(int j = 1; j<= 10; j++){ //Loop Interno

            printf("%d\t", i * j);
        }
        printf("\n");
    }
    return 0;
}