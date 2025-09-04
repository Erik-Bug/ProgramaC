#include <stdio.h>

int main() {

    float N1, N2, N3;
    float media;

    printf("\n*** PROGRAMA DE CÁLCULO DE MÉDIA ***\n");

    printf("Digite sua nota de N1: \n");
    scanf("%f", &N1);

    printf("DIgite sua nota de N2: \n");
    scanf("%f", &N2);

    printf("DIgite sua nota de N3: \n");
    scanf("%f", &N3);

    media = (N1 + N2 + N3) / 3;
    printf("\nSua média total do semestre é: %.2f \n", media);


    return 0;
}