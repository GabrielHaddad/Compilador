#ifndef RELOP_H_INCLUDED
#define RELOP_H_INCLUDED

#include "file.h"
#include "tabelaHash.h"

#define RELOP 0

#define LE 1
#define NE 2
#define LT 3
#define EQ 4
#define GE 5
#define GT 6

// int adHoc (char *input, int *posAtual);
int move(int **tabela, int row, int col, int state, int caracter);
struct Token *tabelaTransicao(struct hash* ha, FILE *arq, struct Buffer *buffer, int **tabela, int row, int col, int initialState);
struct Token *defineToken(struct Buffer* buffer, struct hash* ha, int state);
// int codificacaoDireta(char *input, int *posAtual, int initialState);
#endif // RELOP_H_INCLUDED
