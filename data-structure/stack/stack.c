#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


Stack *initialStack(int length) {
    Stack *st;

    st = (Stack*) malloc(sizeof(Stack));
    if(!st) return NULL;

    st->items = (int*) malloc(length * sizeof(int));    // allocate memory for the items array
    if(!st->items) return NULL;

    st->length = length;
    st->top = -1;

    return st;
}

void freeStack(Stack *st) {
    /* Free the items array and the stack structure itself */
    free(st->items);
    free(st);
}

int isFull(Stack *st) {
    if(st->top == 9) return 1;
    else return 0;
}

int isEmpty(Stack *st) {
    if(st->top == -1) return 1;
    else return 0;
}

int peek(Stack *st) {
    /* Return the top index of the items */
    return st->items[st->top];
}

void push(Stack *st, int number) {
    if(isFull(st)) printf("The Stack is full...\n");
    else
    {
        st->top++;
        st->items[st->top] = number;
    }
}

int pop(Stack *st) {
	int item;

    if(isEmpty(st)) printf("\nThe Stack is empty...\n");
    else
	{
		item = st->items[st->top];
		st->top--;

	}
	return item;
}
