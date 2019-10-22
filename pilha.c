#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct stack* newStack(int capacity)
{
    struct stack *pt = (struct stack*)malloc(sizeof(struct stack));

    pt->maxsize = capacity;
    pt->top = -1;
    pt->items = (int*)malloc(sizeof(int) * capacity);

    return pt;
};

int stackSize(struct stack *pt)
{

    return pt->top + 1;
}

int isStackEmpty(struct stack *pt)
{

    return pt->top == -1;
}

int isStackFull(struct stack *pt)
{

    return pt->top == pt->maxsize -1;
}

int push(struct stack *pt, int x)
{

    if(isStackFull(pt))
    {
        return -1;
    }

    pt->items[++pt->top] = x;

    return 1;
}

int peekStack(struct stack *pt)
{
    if(!isStackEmpty(pt))
    {
        return pt->items[pt->top];
    }
    else
    {
        return -1;
    }
}

int pop(struct stack *pt)
{
    if(isStackEmpty(pt))
    {
        return -1;
    }

    return pt->items[pt->top--];
}


