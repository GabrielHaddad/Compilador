#include <stdio.h>
#include <stdlib.h>
#include "relop.h"

char proxChar(char *input, int *posAtual)
{
    char result = input[*posAtual];
    *posAtual += 1;
    return result;
}

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

int tabelaTransicao(char *input, int *posAtual, int **tabela, int row, int col, int initialState)
{
    int stateAtual = initialState;
    char c = proxChar(input, posAtual);

    while(c != '\0' && stateAtual != -1)
    {
        stateAtual = move(tabela, row, col, stateAtual, c);
        if(stateAtual == -1)
        {
            return -1;
        }
        c = proxChar(input, posAtual);
    }
    if(tabela[stateAtual][0] == 'S')
    {
        return 1;
    }

    return -1;
}

int move(int **tabela, int row, int col, int state, char caracter)
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
