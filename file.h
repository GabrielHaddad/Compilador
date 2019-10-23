#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

#define BUFFER_SIZE 512

struct Buffer
{
    int *content;
    int ini;
    int prox;
};

struct Buffer* createBuffer();
int fillBuffer(struct Buffer *buffer, FILE *arq);
int getProxChar(struct Buffer *buffer);
void rollbackHead(struct Buffer *buffer);
int* getProxToken(struct Buffer *buffer);

#endif // FILE_H_INCLUDED
