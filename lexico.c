#include <stdio.h>
#include <stdlib.h>
#include "lexico.h"
#include "file.h"


int tabelaTransicao(struct hash* ha, FILE *arq, struct Buffer *buffer, int **tabela, int row, int col, int initialState)
{
    int stateAtual = initialState;
    int oldState = stateAtual;
    int caracter = -1;
    if(buffer->prox < BUFFER_SIZE)
    {
        caracter = getProxChar(buffer);
        while(caracter == ' ' || caracter == '\n')
        {
            caracter = getProxChar(buffer);
        }
    }
    else
    {
        fillBuffer(buffer, arq);
        caracter = getProxChar(buffer);
        while(caracter == ' ' || caracter == '\n')
        {
            caracter = getProxChar(buffer);
        }
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
        }

        if(buffer->prox < BUFFER_SIZE)
        {
            caracter = getProxChar(buffer);
            while(caracter == ' ' || caracter == '\n')
            {
                caracter = getProxChar(buffer);
            }
        }
        else
        {
            fillBuffer(buffer, arq);
            caracter = getProxChar(buffer);
            while(caracter == ' ' || caracter == '\n')
            {
                caracter = getProxChar(buffer);
            }
        }
    }

    if(!oldState) {
        return 0;
    }

    defineToken(buffer, ha, oldState);
    rollbackHead(buffer);

    return caracter;
}

int move(int **tabela, int row, int col, int state, int caracter)
{
    int i;
    for(i=1; i<col; i++)
    {
        if(tabela[9][i] == caracter)
        {
            return tabela[state][i];
        }
    }
    return tabela[state][col - 1];
}

void defineToken(struct Buffer* buffer, struct hash* ha, int state)
{
    struct Token* token;
    if(state == 2)
    {
        if(procuraHash(ha, LE))
        {
            token = criaToken(buffer, RELOP, LE);
            insereHash(ha, token);
        }
    }
    else if(state == 3)
    {
        if(procuraHash(ha, NE))
        {
            token = criaToken(buffer, RELOP, NE);
            insereHash(ha, token);
        }
    }
    else if(state == 4)
    {
        if(procuraHash(ha, LT))
        {
            token = criaToken(buffer, RELOP, LT);
            insereHash(ha, token);
        }
    }
    else if(state == 5)
    {
        if(procuraHash(ha, EQ))
        {
            token = criaToken(buffer, RELOP, EQ);
            insereHash(ha, token);
        }
    }
    else if(state == 7)
    {
        if(procuraHash(ha, GE))
        {
            token = criaToken(buffer, RELOP, GE);
            insereHash(ha, token);
        }
    }
    else if(state == 8)
    {
        if(procuraHash(ha, GT))
        {
            token = criaToken(buffer, RELOP, GT);
            insereHash(ha, token);
        }
    }
}


/*
int codificacaoDireta(char *input, int *posAtual, int initialState)
{
    int state = initialState;
    while(state == 0 || state == 1 || state == 6)
    {
        char c = proxChar(input, posAtual);

        switch (state)
        {
        case 0:
            if(c == '<')
            {
                state = 1;
                break;
            }
            else if(c == '=')
            {
                state = 5;
                break;
            }
            else if(c == '>')
            {
                state = 6;
                break;
            }
            else
            {
                state = -1;
                break;
            }

        case 1:
            if(c == '<')
            {
                state = -1;
                break;
            }
            else if(c == '=')
            {
                state = 2;
                break;
            }
            else if(c == '>')
            {
                state = 3;
                break;
            }
            else
            {
                state = 4;
                break;
            }

        case 6:
            if(c == '<')
            {
                state = -1;
                break;
            }
            else if(c == '=')
            {
                state = 7;
                break;
            }
            else if(c == '>')
            {
                state = -1;
                break;
            }
            else
            {
                state = 8;
                break;
            }
        }
    }

    if(state == 2 || state == 3  || state == 4 || state == 5 || state == 7 || state == 8)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

int adHoc (char *input, int *posAtual)
{
    char c = proxChar(input, posAtual);
    if(c == '<')
    {
        c = proxChar(input, posAtual);
        if(c == '=')
        {
            return LE;
        }
        if(c == '>')
        {
            return NE;
        }
        else
        {
            return LT;
        }
    }
    else if(c == '=')
    {
        return EQ;
    }
    else if(c == '>')
    {
        c = proxChar(input, posAtual);
        if(c == '=')
        {
            return GE;
        }
        else
        {
            return GT
        }
    }

    return -1;
}
*/
