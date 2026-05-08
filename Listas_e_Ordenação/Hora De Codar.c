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
        scanf("%d", &opcao);

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
}

void removerListaEstatica(ListaEstatica *lista, const char* texto) {
    int i, pos = -1;  // ✅ Inicializar como -1 (índice inválido)

    for(i = 0; i < lista->quantidade; i++) {
        if(strcmp(lista->dados[i], texto) == 0){
            pos = i;
            break;  // ✅ Bom prática: parar ao encontrar o primeiro
        }
    }

    if(pos == -1) {
        printf("erro: texto \"%s\" não encontrado na lista\n", texto);
        return;
    }

    for(i = pos; i < lista->quantidade - 1; i++){
        strcpy(lista->dados[i], lista->dados[i + 1]);
    }
    lista->quantidade--;
    printf("Texto \"%s\" foi removido com sucesso\n", texto);
}

void listarListaEstatica(const ListaEstatica *lista) {
    if(lista->quantidade == 0){
        printf("Lista estática vazia\n");
        return;
    }

    printf("Itens da lista estática: [ ");
    for(int i = 0; i < lista->quantidade; i++){
        printf("\"%s\" ", lista->dados[i]);
    }
    printf("]\n");
}

// LISTA ENCADEADA

void inicializarListaEncadeada(ListaEncadeada *lista) {
    *lista = NULL;
}

void inserirListaEncadeada(ListaEncadeada *lista, const char* texto) {

    No* novoNo = (No*) malloc(sizeof(No));

    if(novoNo == NULL){
        printf("erro:  falha na alocação de memoria par o no\n");
        return;
    }

    novoNo->dado = (char*) malloc(strlen(texto) + 1);

    if(novoNo->dado == NULL){
        printf("erro:  falha na alocação de memoria par o texto\n");
        free(novoNo);
        return;
    }

    strcpy(novoNo->dado, texto);

    novoNo->proximo = *lista;

    *lista = novoNo;

    printf("Texto \"%s\" inserido com sucesso\n", texto);
}

void removerListaEncadeada(ListaEncadeada *lista, const char* texto) {
    
    No *atual = *lista;
    No *anterior = NULL;

    while(atual != NULL && strcmp(atual->dado, texto) != 0){
    anterior = atual;
    atual = atual->proximo;
    }

    if(atual == NULL){
        printf("erro: texto \"%s\" não encontrado na lista\n", texto);
        return;
    }

    if(anterior == NULL){
        *lista = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }


    free(atual->dado);

    free(atual);
    printf("Texto \"%s\" foi removido com sucesso\n", texto);
}

void listarListaEncadeada(const ListaEncadeada lista) {

    No *temp = lista;
    if(temp == NULL) {
        printf("A lista encadeada está vazia\n");
        return;
    }
    printf("itens da lista encadeada: [");
    while( temp != NULL) {
        printf("\"%s\" ", temp->dado);
        temp = temp->proximo;
    }
    printf("]\n");
}

void liberarListaEncadeada(ListaEncadeada *lista) {
    No *atual = *lista;
    No *temp;
    while(atual != NULL) {
        temp = atual;
        atual = atual->proximo;
        free(temp->dado);
        free(temp);
    }
    *lista = NULL;
}

void MenuListaEstatica() {
    ListaEstatica lista;
    inicializarListaEstatica(&lista);
    
    int opcao;
    char texto[MAX_STR_LEN];
    
    do {
        printf("\n--- MENU LISTA ESTÁTICA ---\n");
        printf("1 - Inserir texto\n");
        printf("2 - Remover texto\n");
        printf("3 - Listar textos\n");
        printf("0 - Voltar\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer
        
        switch(opcao) {
            case 1:
                printf("Digite o texto: ");
                fgets(texto, MAX_STR_LEN, stdin);
                texto[strcspn(texto, "\n")] = 0; // Remove o \n
                inserirListaEstatica(&lista, texto);
                break;
            case 2:
                printf("Digite o texto a remover: ");
                fgets(texto, MAX_STR_LEN, stdin);
                texto[strcspn(texto, "\n")] = 0;
                removerListaEstatica(&lista, texto);
                break;
            case 3:
                listarListaEstatica(&lista);
                break;
            case 0:
                printf("Voltando...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while(opcao != 0);
}

void MenuListaEncadeada() {
    ListaEncadeada lista;
    inicializarListaEncadeada(&lista);
    
    int opcao;
    char texto[MAX_STR_LEN];
    
    do {
        printf("\n--- MENU LISTA ENCADEADA ---\n");
        printf("1 - Inserir texto\n");
        printf("2 - Remover texto\n");
        printf("3 - Listar textos\n");
        printf("0 - Voltar\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer
        
        switch(opcao) {
            case 1:
                printf("Digite o texto: ");
                fgets(texto, MAX_STR_LEN, stdin);
                texto[strcspn(texto, "\n")] = 0;
                inserirListaEncadeada(&lista, texto);
                break;
            case 2:
                printf("Digite o texto a remover: ");
                fgets(texto, MAX_STR_LEN, stdin);
                texto[strcspn(texto, "\n")] = 0;
                removerListaEncadeada(&lista, texto);
                break;
            case 3:
                listarListaEncadeada(lista);
                break;
            case 0:
                printf("Voltando...\n");
                liberarListaEncadeada(&lista);
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while(opcao != 0);
}