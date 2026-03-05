#include <stdio.h>

// VARIÁVEL GLOBAL
int global = 10;

void mostrarGlobal(){
    printf("Na operação global é %d\n", global);
    //ERRO! A variável 'local' não existe aqui
    //printf("%d", local);
};

int main(){
    int local = 5;

    printf("Na operação local é %d\n", local);
    printf("Na operação global é %d\n", global);

 
   mostrarGlobal();

   return 0;
}