#include <stdio.h>
#include <stdlib.h>

struct No
{
    int dados;
    struct No* proximo;
};


int main(){
    
    struct No* primeiro = (struct No*) malloc(sizeof(struct No));
    struct No* segundo = (struct No*) malloc(sizeof(struct No));
    struct No* terceiro = (struct No*) malloc(sizeof(struct No));

    primeiro->dados = 10;
    primeiro->proximo = segundo;

    segundo->dados = 20;
    segundo->proximo = terceiro;

    terceiro->dados = 30;
    terceiro->proximo = NULL;

    struct No* atual = primeiro;
    while(atual != NULL){
        printf("%d\n", atual->dados);
        atual = atual->proximo;
    }

    return 0;
}