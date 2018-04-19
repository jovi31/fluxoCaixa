#include "estrutura.h"

int nColunas(){
    int n = 0;
    Item umItem;
    FILE *arquivo = fopen("fluxo.dat", "rb");

    fread(&umItem, sizeof(Item), 1, arquivo);

    while(!feof(arquivo)){
        n++;
        fread(&umItem, sizeof(Item), 1, arquivo);
    }

    fclose(arquivo);

    return n/18;
}

