#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>

int BuscaLinear(int lista[], int tamanho, int valor){

    for (int i = 0; i < tamanho; i++){

        if (lista[i] == valor){

            return i;
        }
    }



    return -1;
}