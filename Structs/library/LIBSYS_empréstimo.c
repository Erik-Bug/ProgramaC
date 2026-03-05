#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Corrigido: era 'strings.h'

// Constantes globais
#define MAX_LIVROS 50
#define MAX_EMPRESTIMO 100 // Corrigido: removido acento
#define TAM_STRING 100

// DEFINDO ESTRUTURA
struct Livro {
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
    int disponivel; // 1 para disponivel, 0 para indisponivel
};

struct Emprestimo { // Corrigido: removido acento
    int indicelivro; // Para saber qual livro do array 'biblioteca' foi emprestado
    char nome_do_usuario[TAM_STRING]; // Corrigido: removido acento
};
// Dclaração de todas as funções:
void LimparBufferEntrada();
void exibirmenu();
void cadastrarLivro(struct Livro *biblioteca, int *totalLivros);
void listarLivro(const struct Livro *biblioteca, int *totalLivros);
void realizarEmprestimo(struct Livro *biblioteca, int totalLivros, struct Emprestimo *emprestimos, int *totalEmprestimos);
void listarEmprestimos(const struct Livro *biblioteca, const struct Emprestimo *emprestimos, int *totalEmprestimos);
void LiberarMemoria(struct Livro *biblioteca, struct Emprestimo *emprestimos);

// Limpeza do buffer de entrada 
void LimparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Exibição do Menu
void exibirmenu() {
    printf("======================================\n");
        printf("            --- BIBLIOTECA ---          \n");
        printf("======================================\n");
        printf("1 - Cadastrar novo Livro\n");
        printf("2 - Ver lista de livros\n");
        printf("3 - Realizar Empréstimos\n");
        printf("4 - Listar Empréstimos\n");
        printf("0 - Sair\n");
        printf("|   |   |   |   |   |   |   |   |   |   |   \n");
        printf("Escolha uma opção: ");
    
}

//Cadastro de Livros
void cadastrarLivro(struct Livro *biblioteca, int *totalLivros) {
    printf("        ---Cadastro de Livro---         \n\n");

    if (*totalLivros < MAX_LIVROS) {
        int indice = *totalLivros;

        printf("Digite o nome do Livro: ");
        fgets(biblioteca[indice].nome, TAM_STRING, stdin);

        printf("Digite o autor do livro: ");
        fgets(biblioteca[indice].autor, TAM_STRING, stdin);

        printf("Digite a editora do livro: ");
        fgets(biblioteca[indice].editora, TAM_STRING, stdin);

         // Remover quebras de linha
        biblioteca[indice].nome[strcspn(biblioteca[indice].nome, "\n")] = '\0';
        biblioteca[indice].autor[strcspn(biblioteca[indice].autor, "\n")] = '\0';
        biblioteca[indice].editora[strcspn(biblioteca[indice].editora, "\n")] = '\0';

        printf("Digite a edição: ");
        scanf("%d", &biblioteca[indice].edicao);
        LimparBufferEntrada();

        biblioteca[indice].disponivel = 1;
        (*totalLivros)++;
        printf("\nLivro Cadastrado com sucesso!\n");
        } else {
            printf("Biblioteca cheia!!\n");
        }
        printf("\nDigite Enter para continuar...");
        getchar();
    }

// Listar livros
void listarLivro(const struct Livro *biblioteca, int *totalLivros) {
    printf("\n ---Lista de Livros Cadastrados--- \n");

    if(totalLivros == 0) {
        printf("Não há nenhum livro cadastrado!\n");
    } else {
        for(int i = 0; i < totalLivros; i++) {
            printf("-----------------------------------\n");
            printf("LIVRO %d\n", i + 1);
            printf("Nome: %s\n", biblioteca[i].nome);
            printf("Autor: %s\n", biblioteca[i].autor);
            printf("Editora: %s\n", biblioteca[i].editora);
            printf("Edição: %d\n", biblioteca[i].edicao); // CORRIGIDO: era biblioteca[1].edicao
            printf("Status: %s\n", biblioteca[i].disponivel ? "Disponível" : "Indisponível");
            }
            printf("-----------------------------------\n");
        }
        printf("\npressione ENTER para continuar");
        getchar();
}

// Função realizar empréstimo
void realizarEmprestimo(struct Livro *biblioteca, int totalLivros, struct Emprestimo *emprestimos, int *totalEmprestimos){
    printf(" --- REALIZAR EMPRÉSTIMOS ---\n");
        if(*totalEmprestimos >= MAX_EMPRESTIMO) {
            printf("Empréstimos máximos alcançados!\n");
        } else {
            printf("Livros disponíveis: \n");
            int disponiveis = 0;
            for(int i = 0; i < totalLivros; i++) {
            if(biblioteca[i].disponivel) {
                    printf("%d - %s\n", i + 1, biblioteca[i].nome);
                    disponiveis++;
                }
            }

            if (disponiveis == 0) {
                printf("Nenhum livro disponivel para empréstimo\n");
            } else {
                printf("Digite o numero do livro que deseja emprestar: ");
                int numlivro;
                scanf("%d", &numlivro);
                LimparBufferEntrada();

                int indice = numlivro - 1;
                        
                if (indice >= 0 && indice < totalLivros && biblioteca[indice].disponivel) {
                    printf("Digite o nome do usuário que está pegando o livro: ");
                    fgets(emprestimos[*totalEmprestimos].nome_do_usuario, TAM_STRING, stdin);
                            
                    // CORRIGIDO: strcspn (estava strcpn)
                    emprestimos[*totalEmprestimos].nome_do_usuario[strcspn(emprestimos[*totalEmprestimos].nome_do_usuario, "\n")] = '\0';
                        
                    emprestimos[*totalEmprestimos].indicelivro = indice;
                    biblioteca[indice].disponivel = 0;
                    (*totalEmprestimos)++;
                            
                    printf("\nEmpréstimo realizado com sucesso\n");  
                } else {
                    printf("\nNúmero de Livro invalido ou Livro indisponivel\n");
            
                }
            
            }
        }
        printf("\npressione ENTER para continuar");
        getchar();
}

//Função Listar Emprestimo
void listarEmprestimos(const struct Livro *biblioteca, const struct Emprestimo *emprestimos, int *totalEmprestimos){
    printf("\n --- LISTA DE EMPRÉSTIMOS ---\n");
                if(totalEmprestimos == 0) {
                    printf("Nenhum empréstimo realizado\n");
                } else {
                    for(int i = 0; i < totalEmprestimos; i++) {
                        int idxLivro = emprestimos[i].indicelivro;
                        printf("-----------------------------------\n");
                        printf("EMPRÉSTIMO %d\n", i + 1);
                        printf("Usuário: %s\n", emprestimos[i].nome_do_usuario);
                        printf("Livro: %s\n", biblioteca[idxLivro].nome);
                        printf("Autor: %s\n", biblioteca[idxLivro].autor);
                    }
                    printf("-----------------------------------\n");
                }
                printf("\npressione ENTER para continuar");
                getchar();
}

// Liberar memória alocada
void LiberarMemoria(struct Livro *biblioteca, struct Emprestimo *emprestimos){
free(biblioteca);
free(emprestimos);
printf("Memória liberada com Sucesso!\n");
}
// Função principal
int main() {
    struct Livro *biblioteca;
    struct Emprestimo *emprestimos; // Corrigido: removido acento

    // Alocação de memória
    biblioteca = (struct Livro *) calloc(MAX_LIVROS, sizeof(struct Livro));
    
    // CORRIGIDO: faltava o malloc
    emprestimos = (struct Emprestimo *) malloc(MAX_EMPRESTIMO * sizeof(struct Emprestimo));

    // Verificação para caso de erro na alocação
    if (biblioteca == NULL || emprestimos == NULL) {
        printf("Erro: Falha na alocação de memória\n");
        return 1; // CORRIGIDO: return estava dentro do if
    }

    int totalLivros = 0;
    int totalEmprestimos = 0;
    int opcao;
    
    do {
        exibirmenu();
        scanf("%d", &opcao);
        LimparBufferEntrada();
    
        switch (opcao) {
            case 1:
                cadastrarLivro(biblioteca, &totalLivros);
                break;

            case 2:
                listarLivro(biblioteca, totalLivros);
                break;

            case 3: // EMPRÉSTIMO
                realizarEmprestimo(biblioteca, totalLivros, emprestimos, &totalEmprestimos);
                break;
        
            case 4: // CORRIGIDO: implementado case 4
                listarEmprestimos(biblioteca, emprestimos, totalEmprestimos);
                break;

            case 0: // SAIR
                printf("Saindo do programa...\n");
                break;

            default:
                printf("OPÇÃO INVALIDA! Tente novamente...\n");
                printf("\npressione ENTER para continuar");
                getchar();
                break;
        }
    } while (opcao != 0);
    
LiberarMemoria(biblioteca, emprestimos);
    
    return 0;
}


