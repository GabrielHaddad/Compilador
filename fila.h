#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

struct queue
{
    int front;
    int rear;
    int maxsize;
    int *items;
};

struct queue* newQueue(int capacity);
int queueSize(struct queue *qu);
int isQueueEmpty(struct queue *qu);
int isQueueFull(struct queue *qu);
int insertQueue(struct queue *qu, int x);
int peekQueue(struct queue *qu);
int removeQueue(struct queue *qu);


#endif // FILA_H_INCLUDED
