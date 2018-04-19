#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "criar.c"
#include "exibir.c"
#include "extras.c"

int main(){

    int aux;
    criarArquivo();

    aux = exibirFluxo();

    return 0;
}
