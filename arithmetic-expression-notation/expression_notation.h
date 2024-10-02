#ifndef EXPRESSION_NOTATION
#define EXPRESSION_NOTATION

typedef struct stack {
	int *items;
	int top;
	unsigned capacity;
} Stack;

Stack *initial(unsigned capacity);

int isEmpty(Stack *st);
int peek(Stack *st);
char pop(Stack *st);
void push(Stack *st, char op);

int isOperand(char character);
int precedence(char character);

int infixToPostfix(char *expression);

#endif // EXPRESSION_NOTATION

