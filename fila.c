#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct queue* newQueue(int capacity)
{
    struct queue *qu = (struct queue*)malloc(sizeof(struct queue));

    qu->maxsize = capacity;
    qu->front = -1;
    qu->rear = 0;
    qu->items = (int*)malloc(sizeof(int) * capacity);

    return qu;
};

int peekQueue(struct queue *qu)
{
    return qu->items[++qu->front];
}

int isQueueEmpty(struct queue *qu)
{
    return qu->front == -1;
}

int isQueueFull(struct queue *qu)
{
    return  qu->front == qu->maxsize -1;;
}

int queueSize(struct queue *qu)
{
    return qu->front + 1;
}

int insertQueue(struct queue *qu, int x)
{
    if(isQueueFull(qu))
    {
        return -1;
    }

    qu->items[++qu->front] = x;

    return 1;
}

int removeQueue(struct queue *qu)
{
    if(isQueueEmpty(qu))
    {
        return -1;
    }

    return qu->items[qu->rear++];
}
