#include <stdio.h>

int main() {
    printf("\nDesafio lógica Super Trunfo: nível Mestre - Comparação Cruzada\n");

    char Estado;
    int PontosTuristicos;
    char Codigo[4];
    int População;
    char cidade[30];
    float Área;
    float PIB;
    float Densidade;
    float percapita;

    char Estado2;
    int PontosTuristicos2;
    char Codigo2[4];
    int População2;
    char cidade2[30];
    float Área2;
    float PIB2;
    float Densidade2;
    float percapita2;

    // Cadastro da Carta 1
    printf("\n----------Cadastre os dados da Carta 1----------\n\n");
    printf("Digite o Estado: ");
    scanf(" %c", &Estado);
    printf("Digite o Código da sua cidade: ");
    scanf("%3s", Codigo);
    printf("Digite o Nome da Cidade: ");
    scanf("%s", cidade);
    printf("Digite a População da sua cidade: ");
    scanf("%d", &População);
    printf("Digite a Área da cidade(km²): ");
    scanf("%f", &Área);
    printf("Digite o PIB da Cidade(bilhões): ");
    scanf("%f", &PIB);
    printf("Digite o número de pontos turísticos da Cidade: ");
    scanf("%d", &PontosTuristicos);

    // Cadastro da Carta 2
    printf("\n----------Cadastre os dados da Carta 2----------\n\n");
    printf("Digite o Estado: ");
    scanf(" %c", &Estado2);
    printf("Digite o Código da sua cidade: ");
    scanf("%3s", Codigo2);
    printf("Digite o Nome da Cidade: ");
    scanf("%s", cidade2);
    printf("Digite a População da sua cidade: ");
    scanf("%d", &População2);
    printf("Digite a Área da cidade(km²): ");
    scanf("%f", &Área2);
    printf("Digite o PIB da Cidade(bilhões): ");
    scanf("%f", &PIB2);
    printf("Digite o número de pontos turísticos da Cidade: ");
    scanf("%d", &PontosTuristicos2);

    // Cálculos
    Densidade = (float)População / Área;
    percapita = (PIB * 1000000000.0) / População;
    Densidade2 = (float)População2 / Área2;
    percapita2 = (PIB2 * 1000000000.0) / População2;

    int escolhaAtributo1, escolhaAtributo2;
    int resultado1 = 0, resultado2 = 0;

    printf("\n----------Escolha os Atributos para Comparação Cruzada----------\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade\n");
    printf("6 - Renda perCapita\n");
    
    printf("\nEscolha o atributo da CARTA 1: ");
    scanf("%d", &escolhaAtributo1);
    printf("Escolha o atributo da CARTA 2: ");
    scanf("%d", &escolhaAtributo2);

    // Primeira comparação: Atributo da Carta 1 vs Atributo da Carta 2
    printf("\n----------Comparação Cruzada----------\n");
    
    float valorCarta1, valorCarta2;
    char nomeAtributo1[30], nomeAtributo2[30];
    char formato1[50], formato2[50];
    
    // Obter valores e nomes usando SWITCH
    switch (escolhaAtributo1) {
        case 1: 
            valorCarta1 = (float)População;
            sprintf(nomeAtributo1, "População");
            sprintf(formato1, "%d habitantes", População);
            break;
        case 2: 
            valorCarta1 = Área;
            sprintf(nomeAtributo1, "Área");
            sprintf(formato1, "%.2f km²", Área);
            break;
        case 3: 
            valorCarta1 = PIB;
            sprintf(nomeAtributo1, "PIB");
            sprintf(formato1, "%.2f bilhões", PIB);
            break;
        case 4: 
            valorCarta1 = (float)PontosTuristicos;
            sprintf(nomeAtributo1, "Pontos Turísticos");
            sprintf(formato1, "%d pontos", PontosTuristicos);
            break;
        case 5: 
            valorCarta1 = Densidade;
            sprintf(nomeAtributo1, "Densidade");
            sprintf(formato1, "%.2f hab/km²", Densidade);
            break;
        case 6: 
            valorCarta1 = percapita;
            sprintf(nomeAtributo1, "Renda perCapita");
            sprintf(formato1, "R$ %.2f", percapita);
            break;
        default: 
            valorCarta1 = 0;
            sprintf(nomeAtributo1, "Inválido");
            sprintf(formato1, "N/A");
    }
    
    switch (escolhaAtributo2) {
        case 1: 
            valorCarta2 = (float)População2;
            sprintf(nomeAtributo2, "População");
            sprintf(formato2, "%d habitantes", População2);
            break;
        case 2: 
            valorCarta2 = Área2;
            sprintf(nomeAtributo2, "Área");
            sprintf(formato2, "%.2f km²", Área2);
            break;
        case 3: 
            valorCarta2 = PIB2;
            sprintf(nomeAtributo2, "PIB");
            sprintf(formato2, "%.2f bilhões", PIB2);
            break;
        case 4: 
            valorCarta2 = (float)PontosTuristicos2;
            sprintf(nomeAtributo2, "Pontos Turísticos");
            sprintf(formato2, "%d pontos", PontosTuristicos2);
            break;
        case 5: 
            valorCarta2 = Densidade2;
            sprintf(nomeAtributo2, "Densidade");
            sprintf(formato2, "%.2f hab/km²", Densidade2);
            break;
        case 6: 
            valorCarta2 = percapita2;
            sprintf(nomeAtributo2, "Renda perCapita");
            sprintf(formato2, "R$ %.2f", percapita2);
            break;
        default: 
            valorCarta2 = 0;
            sprintf(nomeAtributo2, "Inválido");
            sprintf(formato2, "N/A");
    }
    
    printf("%s (%s) vs %s (%s)\n", cidade, nomeAtributo1, cidade2, nomeAtributo2);
    printf("%s: %s\n", cidade, formato1);
    printf("%s: %s\n", cidade2, formato2);

    // Determinar vencedor usando IF/ELSE
    int temDensidade = (escolhaAtributo1 == 5 || escolhaAtributo2 == 5) ? 1 : 0;
    
    if (temDensidade) {
        // Para densidade, menor valor vence
        if (valorCarta1 < valorCarta2) {
            printf("\nRESULTADO: %s VENCEU! (menor densidade)\n", cidade);
            resultado1 = 1;
        } else if (valorCarta1 > valorCarta2) {
            printf("\nRESULTADO: %s VENCEU! (menor densidade)\n", cidade2);
            resultado1 = 2;
        } else {
            printf("\nRESULTADO: EMPATE!\n");
            resultado1 = 0;
        }
    } else {
        // Para outros atributos, maior valor vence
        if (valorCarta1 > valorCarta2) {
            printf("\nRESULTADO: %s VENCEU!\n", cidade);
            resultado1 = 1;
        } else if (valorCarta1 < valorCarta2) {
            printf("\nRESULTADO: %s VENCEU!\n", cidade2);
            resultado1 = 2;
        } else {
            printf("\nRESULTADO: EMPATE!\n");
            resultado1 = 0;
        }
    }

    // Segunda comparação: Atributo da Carta 2 vs Atributo da Carta 1 (invertido)
    printf("\n----------Comparação Cruzada Invertida----------\n");
    
    float valorCarta1_inv, valorCarta2_inv;
    char formato1_inv[50], formato2_inv[50];
    
    // Usando operador ternário para obter valores invertidos
    valorCarta1_inv = (escolhaAtributo2 == 1) ? (float)População :
                     (escolhaAtributo2 == 2) ? Área :
                     (escolhaAtributo2 == 3) ? PIB :
                     (escolhaAtributo2 == 4) ? (float)PontosTuristicos :
                     (escolhaAtributo2 == 5) ? Densidade : percapita;
                     
    valorCarta2_inv = (escolhaAtributo1 == 1) ? (float)População2 :
                     (escolhaAtributo1 == 2) ? Área2 :
                     (escolhaAtributo1 == 3) ? PIB2 :
                     (escolhaAtributo1 == 4) ? (float)PontosTuristicos2 :
                     (escolhaAtributo1 == 5) ? Densidade2 : percapita2;
    
    // Formatar valores invertidos
    switch (escolhaAtributo2) {
        case 1: sprintf(formato1_inv, "%d habitantes", (int)valorCarta1_inv); break;
        case 2: sprintf(formato1_inv, "%.2f km²", valorCarta1_inv); break;
        case 3: sprintf(formato1_inv, "%.2f bilhões", valorCarta1_inv); break;
        case 4: sprintf(formato1_inv, "%d pontos", (int)valorCarta1_inv); break;
        case 5: sprintf(formato1_inv, "%.2f hab/km²", valorCarta1_inv); break;
        case 6: sprintf(formato1_inv, "R$ %.2f", valorCarta1_inv); break;
        default: sprintf(formato1_inv, "N/A");
    }
    
    switch (escolhaAtributo1) {
        case 1: sprintf(formato2_inv, "%d habitantes", (int)valorCarta2_inv); break;
        case 2: sprintf(formato2_inv, "%.2f km²", valorCarta2_inv); break;
        case 3: sprintf(formato2_inv, "%.2f bilhões", valorCarta2_inv); break;
        case 4: sprintf(formato2_inv, "%d pontos", (int)valorCarta2_inv); break;
        case 5: sprintf(formato2_inv, "%.2f hab/km²", valorCarta2_inv); break;
        case 6: sprintf(formato2_inv, "R$ %.2f", valorCarta2_inv); break;
        default: sprintf(formato2_inv, "N/A");
    }
    
    printf("%s (%s) vs %s (%s)\n", cidade, nomeAtributo2, cidade2, nomeAtributo1);
    printf("%s: %s\n", cidade, formato1_inv);
    printf("%s: %s\n", cidade2, formato2_inv);

    // Determinar vencedor usando OPERADOR TERNÁRIO
    int temDensidade_inv = (escolhaAtributo2 == 5 || escolhaAtributo1 == 5) ? 1 : 0;
    
    if (temDensidade_inv) {
        resultado2 = (valorCarta1_inv < valorCarta2_inv) ? 1 : 
                    (valorCarta1_inv > valorCarta2_inv) ? 2 : 0;
    } else {
        resultado2 = (valorCarta1_inv > valorCarta2_inv) ? 1 : 
                    (valorCarta1_inv < valorCarta2_inv) ? 2 : 0;
    }

    // Exibir resultado usando IF/ELSE
    if (resultado2 == 1) {
        printf("\nRESULTADO: %s VENCEU!", cidade);
        if (temDensidade_inv) {
            printf(" (menor densidade)");
        }
        printf("\n");
    } else if (resultado2 == 2) {
        printf("\nRESULTADO: %s VENCEU!", cidade2);
        if (temDensidade_inv) {
            printf(" (menor densidade)");
        }
        printf("\n");
    } else {
        printf("\nRESULTADO: EMPATE!\n");
    }

    // Resultado final
    printf("\n----------Resultado Final----------\n");
    
    if (resultado1 == 1 && resultado2 == 1) {
        printf("%s VENCEU AMBAS AS COMPARACOES! CAMPEA ABSOLUTA!\n", cidade);
    } else if (resultado1 == 2 && resultado2 == 2) {
        printf("%s VENCEU AMBAS AS COMPARACOES! CAMPEA ABSOLUTA!\n", cidade2);
    } else if ((resultado1 == 1 && resultado2 == 2) || (resultado1 == 2 && resultado2 == 1)) {
        printf("EMPATE TECNICO! Cada cidade venceu em uma comparacao.\n");
        printf("%s venceu na primeira comparacao\n", (resultado1 == 1) ? cidade : cidade2);
        printf("%s venceu na segunda comparacao\n", (resultado2 == 1) ? cidade : cidade2);
    } else if (resultado1 != 0 && resultado2 == 0) {
        printf("%s VENCEU O DESAFIO! (vitoria na primeira comparacao)\n", 
               (resultado1 == 1) ? cidade : cidade2);
    } else if (resultado1 == 0 && resultado2 != 0) {
        printf("%s VENCEU O DESAFIO! (vitoria na segunda comparacao)\n", 
               (resultado2 == 1) ? cidade : cidade2);
    } else {
        printf("EMPATE COMPLETO! As cidades estao equilibradas.\n");
    }

    return 0;
}