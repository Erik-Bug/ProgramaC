#include <stdio.h>
#include <stdlib.h>

struct No {
    int dado;
    struct No* proximo;
};

void InserirNoInicio(struct No** inicio, int valor){

    struct No* novo = (struct No*)malloc(sizeof(struct No));

    if(novo == NULL){
        printf("Erro!! Falha ao alocar memória\n");

        return;
    }

    novo->dado = valor;

    novo->proximo = *inicio;

    *inicio = novo;
}

int main(){



    return 0;
}