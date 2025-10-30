#include <stdio.h>

void recursiveloop(int n){
    if(n > 0){
        printf("%d\n", n);
        recursiveloop(n - 1);
    }

}

int main(){
    int num = 5;
    printf("Contagem Regressiva\n");
    recursiveloop(num);

    return 0;
}