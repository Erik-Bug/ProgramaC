#include <stdio.h>
#include <stdlib.h>

struct No {
    int dado;
    struct No* proximo;
};


int buscaLinearLista(struct No* inicio, int valor) {
    int pos = 0;
    struct No* atual = inicio;
    while (atual != NULL) {
        if (atual->dado == valor) {
            return pos;
        }
        atual = atual->proximo;
        pos++;
    }
    return -1;
} 