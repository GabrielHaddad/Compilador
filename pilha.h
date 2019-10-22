#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

struct stack
{
    int maxsize;
    int top;
    int *items;
};

struct stack* newStack(int capacity);
int stackSize(struct stack *pt);
int isStackEmpty(struct stack *pt);
int isStackFull(struct stack *pt);
int push(struct stack *pt, int x);
int peekStack(struct stack *pt);
int pop(struct stack *pt);

#endif // PILHA_H_INCLUDED
