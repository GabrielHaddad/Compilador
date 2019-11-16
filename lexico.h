#ifndef RELOP_H_INCLUDED
#define RELOP_H_INCLUDED

#include "file.h"
#include "tabelaHash.h"

#define RELOP 0
#define OPT 1
#define ID 2
#define CONST 3
#define PNT 4
#define RWD 5

int move(int **tabela, int row, int col, int state, int caracter);
struct Token *tabelaTransicao(struct hash* ha, FILE *arq, struct Buffer *buffer, int **tabela, int row, int col, int initialState);
struct Token *defineToken(struct Buffer* buffer, struct hash* ha, int state);
#endif // RELOP_H_INCLUDED
