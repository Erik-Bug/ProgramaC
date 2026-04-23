#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 50

#define TAM_MAX 10

//LISTA ESTÁTICA

typedef struct{
    char dados[TAM_MAX][MAX_STR_LEN];
    int quantidade;
} ListaEstatica;


void inicializarListaEstatica(ListaEstatica *lista);

void inserirListaEstatica(ListaEstatica *lista, const char* texto);
void removerListaEstatica(ListaEstatica *lista, const char* texto);
void listarListaEstatica(const ListaEstatica *lista);

//LISTA ENCADEADA

typedef struct No{
    char* dado;
    struct No *proximo;
} No;

typedef No* ListaEncadeada;

void inicializarListaEncadeada(ListaEncadeada *lista);

void inserirListaEncadeada(ListaEncadeada *lista, const char* texto);
void removerListaEncadeada(ListaEncadeada *lista, const char* texto);
void listarListaEncadeada(const ListaEncadeada lista);
void liberarListaEncadeada(ListaEncadeada *lista);


void MenuListaEstatica();
void MenuListaEncadeada();

int main(){
    int opcao;
    do {
        printf("\n ---- MENU DE LISTAS (TEXTO) ---- \n");
        printf("1 - Lista Estática\n");
        printf("2 - Lista Encadeada\n");
        printf("0 - Sair do programa...\n");
        printf("Escolha uma opção: ");
        scanf("%d", opcao);

        switch (opcao)
        {
        case 1:
            MenuListaEstatica();
            break;
        
        case 2:
            MenuListaEncadeada();
            break;
        
        case 0: 
            printf("saindo...........");
            break;

        default:
            printf("opção invalida...");
            break;
        }
    } while (opcao != 0);

    return 0;
}

void inicializarListaEstatica(ListaEstatica *lista) {
    lista->quantidade = 0;
}

void inserirListaEstatica(ListaEstatica *lista, const char* texto){
    if (lista->quantidade == TAM_MAX){
        printf("error: lista está cheia! não dá para botar mais😩");
        return;
    }

strcpy(lista->dados[lista->quantidade], texto);

lista->quantidade++;
printf("Texto \"%s\" inserido com sucesso\n", texto);