#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "criar.c"
#include "alteracao.c"
#include "calculo.c"
#include "exibir.c"
#include "extras.c"

int main(){

    setlocale(LC_ALL, "Portuguese");

    exibirFluxo();

    system("CLS");

    menuAlteracao(1);

    exibirFluxo();

    return 0;
}
