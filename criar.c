#include "estrutura.h"

void criarArquivo(){
    FILE *arquivo = fopen("fluxo.dat", "wb");
    Item umItem;
    int i, j;

    for(i=0; i<=17; i++){
        for(j=0; j<=1; j++){
            umItem.x = i;
            umItem.y = j;
            umItem.valor = i+j;
            fwrite(&umItem, sizeof(Item), 1, arquivo);
        }
    }

    fclose(arquivo);
}
