#include <stdio.h>
#include <stdlib.h>
#include "lexico.h"
#include "file.h"

struct Token *tabelaTransicao(struct hash* ha, FILE *arq, struct Buffer *buffer, int **tabela, int row, int col, int initialState)
{
    struct Token *token = NULL;
    int stateAtual = initialState;
    int oldState = stateAtual;
    int oldCaracter = -1;
    int caracter = -1;
    if(buffer->prox < BUFFER_SIZE)
    {

        caracter = getProxChar(buffer);
        while(caracter == ' ' || caracter == '\n' || caracter == '\t')
        {
            caracter = getProxChar(buffer);
        }

    }
    else
    {
        fillBuffer(buffer, arq);
        caracter = getProxChar(buffer);
        while(caracter == ' ' || caracter == '\n' || caracter == '\t')
        {
            caracter = getProxChar(buffer);
        }

    }

    if(caracter == EOF)
    {
        token = NULL;
        return token;
    }

    while(caracter != EOF && stateAtual != -1)
    {
        stateAtual = move(tabela, row, col, stateAtual, caracter);
        if(stateAtual == -1)
        {
            break;
        }

        if(tabela[stateAtual][0] == 'S')
        {
            oldState = stateAtual;
            oldCaracter = caracter;
        }

        if(buffer->prox < BUFFER_SIZE)
        {
            caracter = getProxChar(buffer);

        }
        else
        {
            fillBuffer(buffer, arq);
            caracter = getProxChar(buffer);
        }
    }

    token = defineToken(buffer, ha, oldState, oldCaracter);

    return token;
}

int move(int **tabela, int row, int col, int state, int caracter)
{
    int i;
    for(i=1; i<col; i++)
    {
        if(tabela[68][i] == caracter)
        {
            return tabela[state][i];
        }
    }
    return -1;
}

struct Token *defineToken(struct Buffer* buffer, struct hash* ha, int state, int caracter)
{
    struct Token* token = NULL;

    //relop
    if(state == 1 || state == 18 || state == 25 || state == 34)
    {
        token = criaToken(buffer, RELOP, 0);

        return token;
    }

    //opt
    if(state == 6 || state == 8 || state == 14 || state == 16 || state == 17)
    {
        token = criaToken(buffer, OPT, 1);

        return token;
    }

    //identificador
    if(state == 4)
    {
        if(procuraHash(ha, caracter) == -1)
        {
            token = criaToken(buffer, ID, caracter);
            insereHash(ha, token);

            return token;
        }

        return ha->token[caracter];
    }

    //constante
    if(state == 11 || state == 36 || state == 67)
    {
        token = criaToken(buffer, CONST, 2);

        return token;
    }

    //pontuação
    if(state == 12 || state == 13 || state == 19 || state == 21 || state == 23)
    {
        token = criaToken(buffer, PNT, 3);

        return token;
    }

    //rwd
    if(state == 37 || state == 41 || state == 43 || state == 48 || state == 49 || state == 51 || state == 52 || state == 59 || state == 60 || state == 65 || state == 66  )
    {
        token = criaToken(buffer, RWD, 4);

        return token;
    }

    token = criaToken(buffer, -1, -1);
    return token;
}
