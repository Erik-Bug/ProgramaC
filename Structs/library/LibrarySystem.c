#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constantes globais

#define MAX_LIVROS 50
#define TAM_STRING 100

// DEFINDO ESTRUTURA

struct Livro {
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;

};

// limapeza do buffer de entrada 
void LimparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função principal

int main() {
    
    struct Livro biblioteca[MAX_LIVROS];
    int totalLivros = 0;
    int opcao;

// laço principal

    do
    {
        printf("======================================\n");
        printf("            --- BIBLIOTECA ---          \n");
        printf("======================================\n");
        printf("1 - Cadastrar novo Livro\n");
        printf("2 - Ver lista de livros\n");
        printf("0 - Sair\n");
        printf("|   |   |   |   |   |   |   |   |   |   |   \n");
        printf("Escolha uma opção: ");
    
    //escolha de opções
        scanf("%d", &opcao);
        LimparBufferEntrada();
    
    //manipulação de switches
        switch (opcao) {
            case 1:
                printf("        ---Cadastro de Livro---         \n\n");

                if (totalLivros < MAX_LIVROS){
                    printf("Digite o nome do Livro: ");
                    fgets(biblioteca[totalLivros].nome, TAM_STRING, stdin);

                    printf("Digite o autor do livro: ");
                    fgets(biblioteca[totalLivros].autor, TAM_STRING, stdin);

                    printf("Digite a editora do livro: ");
                    fgets(biblioteca[totalLivros].editora, TAM_STRING, stdin);

                    biblioteca[totalLivros].nome[strcspn(biblioteca[totalLivros].nome, "\n")] = '\0';
                    biblioteca[totalLivros].autor[strcspn(biblioteca[totalLivros].autor, "\n")] = '\0';
                    biblioteca[totalLivros].editora[strcspn(biblioteca[totalLivros].editora, "\n")] = '\0';

                    printf("Digite a edição: ");
                    scanf("%d", &biblioteca[totalLivros].edicao);
                    LimparBufferEntrada();

                    totalLivros ++;
                    printf("\nLivro Cadastrado com sucesso\n");
                
                } else {
                    printf("Biblioteca cheia! Não há mais espaço para cadastro");
                }
                break;
            case 2:
            printf("\n ---Lista de Livros Cadastrados--- \n");

            if(totalLivros == 0){
                printf("Não há nenhum livro cadastrado!");
            } else {
                for(int i = 0; i < totalLivros; i++){
                    printf("-----------------------------------\n");
                    printf("LIVRO %d\n", i + 1);
                    printf("Nome: %s\n", biblioteca[i].nome);
                    printf("Autor: %s\n", biblioteca[i].autor);
                    printf("Editora: %s\n", biblioteca[i].editora);
                    printf("Edição: %d\n", biblioteca[i].edicao);
                }
                printf("-----------------------------------\n");
            }
           // pausa para que o usuário veja a lista
            printf("\npressione ENTER para continuar");
            getchar();
            break;
        
        case 0: //SAIR
            printf("Saindo do programa...\n");
            break;

        default:
        printf("OPÇÃO INVALIDA! Tente novamente...\n");
        printf("\npressione ENTER para continuar");
        getchar();
            break;
        }

    } while (opcao != 0);
    

    
    
    
    return 0;
}
