#ifndef EXPRESSION_NOTATION
#define EXPRESSION_NOTATION

typedef struct stack {
	int *items;
	int top;
	unsigned capacity;
} Stack;

Stack *initial(unsigned capacity);

int is_empty(Stack *st);
int peek(Stack *st);
char pop(Stack *st);
void push(Stack *st, char op);

int is_operand(char character);
int precedence(char character);

int infix_to_postfix(char *expression);

#endif // EXPRESSION_NOTATION
