#include "estrutura.h"

int exibirFluxo(){
    FILE *arquivo = fopen("fluxo.dat", "rb");
    int totColuna = nColunas();
    if(arquivo == NULL){
        return 0;
    }

    fclose(arquivo);

    exibirItem("(=) Saldo Anterior", 0, totColuna);
    exibirTitulo("Fluxo de Caixa Operacional");
    exibirItem("(+) Receita de Vendas", 1, totColuna);
    exibirItem("(-) Pagamento a fornecedores", 2, totColuna);
    exibirItem("(-) Pagamento a funcionarios", 3, totColuna);
    exibirItem("(-) Pagamento de impostos", 4, totColuna);
    exibirItem("(=) Saldo Caixa Operacoes", 5, totColuna);
    exibirTitulo("Fluxo de Caixa de Investimentos");
    exibirItem("(+) Venda de Imobilizados", 6, totColuna);
    exibirItem("(-) Aquisicao de ativo permanente", 7, totColuna);
    exibirItem("(+) Recebimento de Dividendos", 8, totColuna);
    exibirItem("(=) Saldo Caixa de Investimento", 9, totColuna);
    exibirTitulo("Fluxo de Caixa de Financiamento");
    exibirItem("(+) Aquisicao de Emprestimos", 10, totColuna);
    exibirItem("(-) Amortizacao de Emprestimos", 11, totColuna);
    exibirItem("(+) Aporte de Capital", 12, totColuna);
    exibirItem("(-) Pagamento de Dividendos", 13, totColuna);
    exibirItem("(=) Saldo de Caixa de Financiamento", 14, totColuna);
    puts("");
    exibirItem("(=) Saldo Inicial do Periodo", 15, totColuna);
    exibirItem("(=) Resultado do Periodo", 16, totColuna);
    exibirItem("(=) Saldo final do Periodo", 17, totColuna);
    pausarExibicao();

    return 1;
}

void exibirItem(char nome[], int linha, int nColuna){
    FILE *arquivo = fopen("fluxo.dat", "rb");
    Item umItem;
    char espacos[255], aux[10];
    int i, j, cont = 0;

    criaEspacos(nome, espacos, 60);
    printf("\n\t%s %s", nome, espacos);

    fread(&umItem, sizeof(Item), 1, arquivo);

    while(!feof(arquivo)){
        if(umItem.x == linha){
                sprintf(aux, "%.2f", umItem.valor);
                criaEspacos(aux, espacos, 10);
                if(cont == nColuna-1){
                    printf("|  ");
                }
                printf("%.2f %s", umItem.valor, espacos);
                cont++;
            }
        fread(&umItem, sizeof(Item), 1, arquivo);
    }

    fclose(arquivo);
}

void exibirTitulo(char nome[]){
    printf("\n\n\t%s\n", nome);
}
