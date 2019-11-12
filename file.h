#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

#define BUFFER_SIZE 512

struct Buffer
{
    int *content;
    int ini;
    int prox;
};

struct Content
{
    int value;
    int col;
    int line;
};

struct Token
{
    int name;
    struct Content content;
};

struct Buffer* createBuffer();
int fillBuffer(struct Buffer *buffer, FILE *arq);
int getProxChar(struct Buffer *buffer);
void rollbackHead(struct Buffer *buffer);
struct Token* criaToken(struct Buffer *buffer, int name, int value);
int getActualLine();
int getActualColumn();

#endif // FILE_H_INCLUDED
