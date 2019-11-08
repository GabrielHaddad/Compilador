#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "lexico.h"

struct Buffer* createBuffer(){
    struct Buffer *buffer = (struct Buffer*)malloc(sizeof(struct Buffer));
    buffer->content = (int*)malloc(sizeof(int) * BUFFER_SIZE);
    buffer->ini = 0;
    buffer->prox = 0;

    return buffer;
}

int fillBuffer(struct Buffer *buffer, FILE *arq) {
    int i = 0;
    while(!feof(arq)){
        int result = fgetc(arq);
        buffer->content[i] = result;
        i++;
    }

    buffer->ini = 0;
    buffer->prox = 0;

    if(feof(arq)){
        return -1;
    }

    return 1;
}

int getProxChar(struct Buffer *buffer){
    if(buffer->content[buffer->prox] != EOF){
        int result = buffer->content[buffer->prox];
        buffer->prox++;

        return result;
    }

    return EOF;
}

struct Token* criaToken(struct Buffer *buffer, int name, int value) {

    struct Token *token = (struct Token*)malloc(sizeof(struct Token));
    token->name = name;
    token->value = value;

    while(buffer->ini != buffer->prox){
        buffer->ini++;
    }

    return token;
}

void rollbackHead(struct Buffer *buffer){
    buffer->prox--;
}

