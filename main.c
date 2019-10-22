#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"
#include "relop.h"
#include "file.h"

int main()
{
    FILE *arq;

    arq = fopen("input.txt", "rt");

    printf("%c", (char)getProxChar(arq));
    printf("%c", (char)getProxChar(arq));
    printf("%c", (char)getProxChar(arq));
    printf("%c", (char)getProxChar(arq));
    printf("%c", (char)getProxChar(arq));
    printf("%c", (char)getProxChar(arq));
    printf("%c", (char)getProxChar(arq));

    fclose(arq);

    /*
    char string[10] = "12";
    int posAtual = 0;

    printf("%d",codificacaoDireta(string, &posAtual, 0));
    */
    //printf("%d",adHoc(string, &posAtual));
    /*
    int i = 0, j = 0, row = 10, col = 5;
    int **tabela = (int **)malloc(sizeof(int *) * row);
    for(i = 0; i < row; i++){
        tabela[i] = (int *) malloc(sizeof(int) * col);
        for(j = 0; j < col; j++){
            tabela[i][j] = 0;
        }
    }

    tabela[0][0] = 'N';
    tabela[1][0] = 'N';
    tabela[2][0] = 'S';
    tabela[3][0] = 'S';
    tabela[4][0] = 'S';
    tabela[5][0] = 'S';
    tabela[6][0] = 'N';
    tabela[7][0] = 'S';
    tabela[8][0] = 'S';
    tabela[9][0] = 'F';

    tabela[0][1] = 1;
    tabela[1][1] = -1;
    tabela[2][1] = -1;
    tabela[3][1] = -1;
    tabela[4][1] = -1;
    tabela[5][1] = -1;
    tabela[6][1] = -1;
    tabela[7][1] = -1;
    tabela[8][1] = -1;
    tabela[9][1] = '<';

    tabela[0][2] = 5;
    tabela[1][2] = 2;
    tabela[2][2] = -1;
    tabela[3][2] = -1;
    tabela[4][2] = -1;
    tabela[5][2] = -1;
    tabela[6][2] = 7;
    tabela[7][2] = -1;
    tabela[8][2] = -1;
    tabela[9][2] = '=';

    tabela[0][3] = 6;
    tabela[1][3] = 3;
    tabela[2][3] = -1;
    tabela[3][3] = -1;
    tabela[4][3] = -1;
    tabela[5][3] = -1;
    tabela[6][3] = -1;
    tabela[7][3] = -1;
    tabela[8][3] = -1;
    tabela[9][3] = '>';

    tabela[0][4] = -1;
    tabela[1][4] = 4;
    tabela[2][4] = -1;
    tabela[3][4] = -1;
    tabela[4][4] = -1;
    tabela[5][4] = -1;
    tabela[6][4] = 8;
    tabela[7][4] = -1;
    tabela[8][4] = -1;
    tabela[9][4] = 'O';

    for(i = 0; i< row; i++){
        for(j = 0; j < col; j++){
            printf("[%d][%d]: %d ", i,j,tabela[i][j]);
        }
        printf("\n");
    }

    printf("\n %d \n ",tabelaTransicao(string, &posAtual, tabela, row, col, 0));
    */
    return 0;
}

