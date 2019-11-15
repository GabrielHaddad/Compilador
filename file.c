#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "lexico.h"

int col = 2;
int line = 1;

struct Buffer* createBuffer()
{
    struct Buffer *buffer = (struct Buffer*)malloc(sizeof(struct Buffer));
    buffer->content = (int*)malloc(sizeof(int) * BUFFER_SIZE);
    buffer->ini = 0;
    buffer->prox = 0;

    return buffer;
}

int fillBuffer(struct Buffer *buffer, FILE *arq)
{
    int i = 0;
    while(!feof(arq))
    {
        int result = fgetc(arq);
        buffer->content[i] = result;
        i++;
    }

    buffer->ini = 0;
    buffer->prox = 0;

    if(feof(arq))
    {
        return -1;
    }

    return 1;
}

int getProxChar(struct Buffer *buffer)
{
    if(buffer->content[buffer->prox] != EOF)
    {
        int result = buffer->content[buffer->prox];
        buffer->prox++;
        return result;
    }

    return EOF;
}

struct Token* criaToken(struct Buffer *buffer, int name, int value)
{
    if(buffer->content[buffer->prox] != EOF){
        rollbackHead(buffer);
    }
    struct Token *token = (struct Token*)malloc(sizeof(struct Token));
    token->name = name;
    token->content.value = value;
    token->content.line = getActualLine();
    token->content.col = getActualColumn();

    while(buffer->ini != buffer->prox)
    {
        int result = buffer->content[buffer->ini];
        if(result == 10)
        {
            line++;
            token->content.line++;
            col = 1;
            token->content.col = 1;
        }
        else if(result == 9)
        {
            col += 4;
            token->content.col += 4;
        }else {
            col++;
        }

        if(result == 32)
        {
            token->content.col++;
            col++;
        }

        buffer->ini++;
    }

    return token;
}

void rollbackHead(struct Buffer *buffer)
{
    buffer->prox--;
    col--;
}

int getActualLine()
{
    return line;
}

int getActualColumn()
{
    return col;
}
