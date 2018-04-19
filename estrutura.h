#ifndef ESTRUTURA_H_INCLUDED
#define ESTRUTURA_H_INCLUDED

typedef struct{
    int x, y;
    float valor;
}Item;

// CRIAR

void criarArquivo();

// EXIBIR

int exibirFluxo();
void exibirItem(char nome[], int linha, int nColuna);

// EXTRAS

void criaEspacos(char *palavraInicial, char *espacos, int tamanhoLinha);

#endif // ESTRUTURA_H_INCLUDED
