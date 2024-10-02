#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "expression_notation.h"


int infixToPostfix(char *expression) {
	int i, k;

	Stack *st;
	st = initial(strlen(expression));	// initialize the stack by length of expression

	if(!st) return -1;
	for(i = 0, k = -1; expression[i]; ++i)
	{
		/* check all the characters of the expression in the loop  
		 * `k` increase when the character is operand*/

		if(isOperand(expression[i])) expression[++k] = expression[i];
		else if(expression[i] == '(') push(st, expression[i]);
		else if(expression[i] == ')')
		{
			// while the Stack is empty and the top operator item isn't `(`, pop the items
			while(!isEmpty(st) && peek(st) != '(') expression[++k] = pop(st);
			if(!isEmpty(st) && peek(st) != '(') return -1;
			else pop(st);	// pop the `(` and don't push it to the output expression
		}
		else
		{
			/* check the operators  */

			while( !isEmpty(st) && precedence(expression[i]) <= precedence(peek(st)) )
			{
				/* if the priority of the current operator character is less than the
				 *  top item(top operator character) of the Stack, then pop it off the Stack. Otherwise,
				 *  push it to the Stack */
				expression[++k] = pop(st);
			}
			push(st, expression[i]);	// push the operator character to the stack
		}
	}
	while(!isEmpty(st)) expression[++k] = pop(st);
	expression[++k] = '\0';	// Null-terminate the expression string
	printf("%s\n", expression);
}

