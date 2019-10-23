#include <stdio.h>
#include <stdlib.h>
#include "file.h"

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

    return -1;
}

int getProxChar(struct Buffer *buffer){
    if(buffer->content[buffer->prox] != EOF){
        int result = buffer->content[buffer->prox];
        buffer->prox++;

        return result;
    }

    return EOF;
}

int* getProxToken(struct Buffer *buffer) {
    int size = buffer->prox - buffer->ini;
    int *token = (int*)malloc(sizeof(int) * size);
    int i = 0;
    while(buffer->ini != buffer->prox){
        token[i] = buffer->content[buffer->ini];
        buffer->ini++;
        i++;
    }

    return token;
}

void rollbackHead(struct Buffer *buffer){
    buffer->prox--;
}

