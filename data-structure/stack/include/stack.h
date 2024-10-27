#ifndef STACK_H
#define STACK_H

typedef struct stack {
    int length; // the maximum size of the stack
    int *items; // pointer to dynamically allocated array
    int top;
} Stack;

Stack *initialStack(int length);
void freeStack(Stack *st);

int isFull(Stack *st);
int isEmpty(Stack *st);
void push(Stack *st, int number);
int pop(Stack *st);
int peek(Stack *st);

#endif  // STACK_H
