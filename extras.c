#include "estrutura.h"

void criaEspacos(char *palavraInicial, char *espacos, int tamanhoLinha){
    int tam = tamanhoLinha - strlen(palavraInicial);
    int i;

    for(i=0; i < tam; i++){
        espacos[i] = ' ';
    }

    espacos[tam] = '\0';
}
