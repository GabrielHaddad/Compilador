#ifndef RELOP_H_INCLUDED
#define RELOP_H_INCLUDED

#define TOK_OP 0;

#define LE 1;
#define NE 2;
#define LT 3;
#define EQ 4;
#define GE 5;
#define GT 6;

char proxChar(char *input, int *posAtual);
int adHoc (char *input, int *posAtual);
int move(int **tabela, int row, int col, int state, char caracter);
int tabelaTransicao(char *input, int *posAtual, int **tabela, int row, int col, int initialState);
int codificacaoDireta(char *input, int *posAtual, int initialState);
#endif // RELOP_H_INCLUDED
