#include "estrutura.h"

int exibirFluxo(){
    FILE *arquivo = fopen("fluxo.dat", "rb");
    int totColuna = 2;   // mudar para descobrir n colunas

    if(arquivo == NULL){
        return 0;
    }

    fclose(arquivo);

    exibirItem("(=) Saldo Anterior", 0, totColuna);
    exibirItem("(=) Saldo Anterior", 1, totColuna);
    exibirItem("(=) Saldo Anterior", 2, totColuna);
    exibirItem("(=) Saldo Anterior", 3, totColuna);
    exibirItem("(=) Saldo Anterior", 4, totColuna);
    exibirItem("(=) Saldo Anterior", 5, totColuna);
    exibirItem("(=) Saldo Anterior", 6, totColuna);
    exibirItem("(=) Saldo Anterior", 7, totColuna);
    exibirItem("(=) Saldo Anterior", 8, totColuna);
    exibirItem("(=) Saldo Anterior", 9, totColuna);
    exibirItem("(=) Saldo Anterior", 10, totColuna);
    exibirItem("(=) Saldo Anterior", 11, totColuna);
    exibirItem("(=) Saldo Anterior", 12, totColuna);
    exibirItem("(=) Saldo Anterior", 13, totColuna);
    exibirItem("(=) Saldo Anterior", 14, totColuna);
    exibirItem("(=) Saldo Anterior", 15, totColuna);
    exibirItem("(=) Saldo Anterior", 16, totColuna);
    exibirItem("(=) Saldo Anterior", 17, totColuna);


    return 1;
}

void exibirItem(char nome[], int linha, int nColuna){
    FILE *arquivo = fopen("fluxo.dat", "rb");
    Item umItem;
    char espacos[255], aux[10];
    int i, j;

    criaEspacos(nome, espacos, 30);
    printf("\n\t%s %s", nome, espacos);

    fread(&umItem, sizeof(Item), 1, arquivo);

    while(!feof(arquivo)){
        if(umItem.x == linha){
                sprintf(aux, "%.2f", umItem.valor);
                criaEspacos(aux, espacos, 10);
                printf("%.2f %s", umItem.valor, espacos);
            }
        fread(&umItem, sizeof(Item), 1, arquivo);
    }

    fclose(arquivo);
}
