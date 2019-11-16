#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"
#include "lexico.h"
#include "file.h"
#include "tabelaHash.h"

int main()
{
    FILE *newTable;
    newTable = fopen("afdTabelaMerged.txt", "rt");

    int i = 0, j = 0, row = 69, col = 51;
    char c[1024];
    int **novaTabela = (int **)malloc(sizeof(int *) * row);
    for(i = 0; i < row; i++)
    {
        novaTabela[i] = (int *) malloc(sizeof(int) * col);
        for(j = 0; j < col; j++)
        {
            if(fscanf(newTable, " %1023s", c) == 1)
            {
                if(atoi(c) == 0)
                {
                    novaTabela[i][j] = c[0];
                }
                else
                {
                    novaTabela[i][j] = atoi(c);
                }
            }
        }
    }
    /*
    for(i = 0; i< row; i++)
    {
        for(j = 0; j < col; j++)
        {
            printf("[%d][%d]: %d ", i,j,novaTabela[i][j]);
        }
        printf("\n");
    }
    */
    fclose(newTable);


    FILE *arq;
    struct Buffer *buffer;

    buffer = createBuffer();

    arq = fopen("input.txt", "rt");

    fillBuffer(buffer, arq);




    struct hash* ha = criaHash();

    printf("\n\n");
    struct Token *token = tabelaTransicao(ha, arq, buffer, novaTabela, row, col, 0);
    while(token != NULL && token->name != -1)
    {
        printf("Name: %d Value: %d  Line: %d  Column: %d\n", token->name, token->content.value,
                   token->content.line, token->content.col);
        token = tabelaTransicao(ha, arq, buffer, novaTabela, row, col, 0);
    }


    printf("\n \n");

    int h = 0;
    for(h = 0; h < HASH_SIZE; h++)
    {
        if(ha->token[h] != NULL)
        {
            printf("Name: %d Value: %d  Line: %d  Column: %d\n", ha->token[h]->name, ha->token[h]->content.value,
                   ha->token[h]->content.line, ha->token[h]->content.col);
        }
    }

    if (token == NULL)
    {
        printf("\nFinal do Arquivo\n");
        token = criaToken(buffer, -2, -2);
        printf("Name: %d Value: %d  Line: %d  Column: %d\n", token->name, token->content.value,
                   token->content.line, token->content.col);
    }else if(token->content.value == -1){
        printf("\nErro ao reconhecer o token\n");
    }


    fclose(arq);

    return 0;
}

