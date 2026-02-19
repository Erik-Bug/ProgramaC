#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

// Constantes globais

#define MAX_LIVROS 50
#define MAX_EMPRÉSTIMO 100
#define TAM_STRING 100

// DEFINDO ESTRUTURA

struct Livro {
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
    int disponivel; // 1 para disponivel, 0 para indisponivel

};

struct Empréstimo {
    int indicelivro; // Para saber qual livro do array 'biblioteca' foi emprestado
    char nome_do_usuário[TAM_STRING];
};


// limapeza do buffer de entrada 
void LimparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função principal

int main() {
    struct Livro *biblioteca;
    struct Empréstimo *emprestimos;

    //uso primeiro 'calloc' para o array biblioteca. calloc(num_elementos, tamanho_de_cada_elemento)
    //vantagem: inicializa a memória com 0
    biblioteca = (struct Livro *) calloc(MAX_LIVROS, sizeof(struct Livro));

    // uso de 'malloc' para o array de empréstimo. malloc(tamanho_total_em_bytes)
    emprestimos = (struct Empréstimo *) (MAX_EMPRÉSTIMO * sizeof(struct Empréstimo));

    //Verificação para caso de erro na alocação
    if (biblioteca == NULL ||emprestimos == NULL ){
        printf("Erro: Falha na alocação de memória\n");
    } return 1;

    int totalLivros = 0;
    int totalEmprestimos = 0;
    int opcao;
     do
    {
        printf("======================================\n");
        printf("            --- BIBLIOTECA ---          \n");
        printf("======================================\n");
        printf("1 - Cadastrar novo Livro\n");
        printf("2 - Ver lista de livros\n");
        printf("3 - Realizar Empréstimos\n");
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
                    printf("Edição: %d\n", biblioteca[1].edicao);
                }
                printf("-----------------------------------\n");
            }
           // pausa para que o usuário veja a lista
            printf("\npressione ENTER para continuar");
            getchar();
            break;
        case 3: //EMPRÉSTIMO
            printf(" --- REALIZAR EMPRÉSTIMOS ---");
            if(totalEmprestimos >= MAX_EMPRÉSTIMO){
                printf("Empréstimos máximos alcançados!\n");
            } else {
                printf("Livros disponíveis: \n");
                int disponiveis = 0;
                for(int i = 0; i < totalLivros; i++){
                    if(biblioteca[i].disponivel) {
                        printf("%d - %f\n", i + 1, biblioteca[i]. nome);
                        disponiveis++
                    }
                }

                if (disponiveis == 0){
                    printf("Nenhum livro disponivel para empréstimo\n");
                } else {
                    printf("Digite o numero do livro que deseja emprestar: \n");
                    int numlivro;
                    scanf("%d", &numlivro);
                    LimparBufferEntrada();

                    int indice = numlivro - 1
                }
            }


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
