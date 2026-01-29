#include <stdio.h>

typedef struct
{
  char nome[50];
  int idade;
  float media;
} Aluno;


int main() {
Aluno aluno1 = {"Lucas", 20, 5.5};

printf("nome do aluno: %s\n", aluno1.nome);
printf("Idade do aluno: %d\n", aluno1.idade);
printf("Media do aluno: %.2f\n", aluno1.media);



return 0;
}