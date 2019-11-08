#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

#define BUFFER_SIZE 512

struct Buffer
{
    int *content;
    int ini;
    int prox;
};

struct Token
{
    int name;
    int value;
};

struct Buffer* createBuffer();
int fillBuffer(struct Buffer *buffer, FILE *arq);
int getProxChar(struct Buffer *buffer);
void rollbackHead(struct Buffer *buffer);
struct Token* criaToken(struct Buffer *buffer, int name, int value);

#endif // FILE_H_INCLUDED
