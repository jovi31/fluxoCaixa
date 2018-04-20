#include "estrutura.h"

void menuAlteracao(int ehRemocao){
    int x, y, valor, pos;

    x = lerLinhaItem();

    y = lerDia();

    if(ehRemocao){
        valor = 0;
    }else{
        valor = lerValor();
    }

    pos = posicaoDoItem(x - 1, y - 1);

    alterarItem(pos, valor);
}

int lerLinhaItem(){
    int opc;

    printf("----------------ITENS----------------\n\n");

                                        //Linhas
    printf("  (1) Receita de Vendas\n"); //2
    printf("  (2) Pagamento a fornecedores\n"); //3
    printf("  (3) Pagamento a funcionarios\n"); //4
    printf("  (4) Pagamento de impostos\n"); //5
    printf("  (5) Venda de Imobilizados\n"); //7
    printf("  (6) Aquisicao de ativo permanente\n"); //8
    printf("  (7) Recebimento de Dividendos\n"); //9
    printf("  (8) Aquisicao de Emprestimos\n"); //11
    printf("  (9) Amortizacao de Emprestimos\n"); //12
    printf(" (10) Aporte de Capital\n"); //13
    printf(" (11) Pagamento de Dividendos\n\n"); //14

    printf("Digite o número do item:");
    scanf("%d", &opc);
    getchar();


    //Converte o valor digitado para a respectiva linha do item.
    if(opc <= 4){
        return opc + 1;
    }else{
        if(opc <= 7){
            return opc + 2;
        }else{
            return opc + 3;
        }
    }
}

int lerDia(){
    int dia;

    printf("Digite o número do dia:");
    scanf("%d", &dia);
    getchar();

    return dia;
}

float lerValor(){
    float valor;

    printf("Digite o valor do item:");
    scanf("%f", &valor);
    getchar();

    return valor;
}

int posicaoDoItem(int x, int y){
    FILE *arquivo = fopen("fluxo.dat", "rb");
    Item umItem;
    int cont = 0;

    fseek(arquivo, 0, SEEK_SET);

    fread(&umItem, sizeof(Item), 1, arquivo);

    while(!feof(arquivo)){

        if(umItem.x == x && umItem.y == y){
            fclose(arquivo);
            return cont;
        }

        fread(&umItem, sizeof(Item), 1, arquivo);

        cont++;
    }

    fclose(arquivo);

    return -1;
}

int alterarItem(int posicao, float valor){
    FILE *arquivo = fopen("fluxo.dat", "rb+");
    Item umItem;

    fseek(arquivo, posicao * sizeof(Item), SEEK_SET);

    fread(&umItem, sizeof(Item), 1, arquivo);

    fseek(arquivo, posicao * sizeof(Item), SEEK_SET);

    umItem.valor = valor;

    fwrite(&umItem, sizeof(Item), 1, arquivo);

    fseek(arquivo, 0, SEEK_END);

    fclose(arquivo);
}
