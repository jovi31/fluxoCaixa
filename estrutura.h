#ifndef ESTRUTURA_H_INCLUDED
#define ESTRUTURA_H_INCLUDED

typedef struct{
    int x, y;
    float valor;
}Item;

// CRIAR

void criarArquivo();

// CALCULO

int nColunas();

// EXIBIR

int exibirFluxo();
void exibirItem(char nome[], int linha, int nColuna);
void exibirTitulo(char nome[]);

// EXTRAS

void criaEspacos(char *palavraInicial, char *espacos, int tamanhoLinha);
void pausarExibicao();

#endif // ESTRUTURA_H_INCLUDED
