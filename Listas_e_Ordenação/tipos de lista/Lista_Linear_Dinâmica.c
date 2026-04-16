#include <stdio.h>

int main(){
    int* num = (int*) malloc(3 * sizeof(int));

    num[0] = 10;
    num[1] = 20;
    num[2] = 30;


    num = (int*) realloc(num, 5 * sizeof(int));

    num[3] = 40;
    num[4] = 50;

printf("%d, %d, %d, %d, %d\n", num[0], num[1], num[2], num[3], num[4]);
    return 0;
}