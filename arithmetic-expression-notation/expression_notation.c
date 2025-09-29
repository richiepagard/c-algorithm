#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "expression_notation.h"


Stack *initial(unsigned capacity) {
	/* get a number(for capacity) and create a empty stack */

	Stack *st;
	st = (Stack*) malloc(sizeof(Stack));	// allocate memory to stack
	if(!st) return NULL;

	st->top = -1;
	st->capacity = capacity;
	st->items = (int*) malloc(st->capacity * sizeof(int));	// allocate memory to items
	if(!st->items) return NULL;

	return st;
}

int is_empty(Stack *st) {
	return st->top == -1;
}

int peek(Stack *st) {
	return st->items[st->top];
}

char pop(Stack *st) {
	/* remove the top item of the stack  */
	if(!is_empty(st)) return st->items[st->top--];
	return '$';	// if the stack is empty, return a `$`
}

void push(Stack *st, char op) {
	/* `op` means `operator`. The function push the operator on the top of the stack  */
	st->items[++st->top] = op;
}

int is_operand(char character) {
	/* check if the character is alpha, return True, otherwise, return False  */
	return (character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z');
}

int precedence(char character) {
	/* check the precedence of not operand characters  */

	switch(character)
	{
		case '+': case '-': return 1; break;
		case '*': case '/': return 2; break;
		case '^': return 3;
	}
	return -1;
}
