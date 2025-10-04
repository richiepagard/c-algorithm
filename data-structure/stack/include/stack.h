#ifndef STACK_H
#define STACK_H

typedef struct stack {
    int length; // the maximum size of the stack
    int *items; // pointer to dynamically allocated array
    int top;
} Stack;

Stack *init_stack(int length);
void free_stack(Stack *st);

int is_full(Stack *st);
int is_empty(Stack *st);
void push(Stack *st, int number);
int pop(Stack *st);
int peek(Stack *st);

#endif  // STACK_H
