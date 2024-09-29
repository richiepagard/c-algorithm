#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


int main() {
    Stack *st;
    st = initialStack(5);
    push(st);
    push(st);
    push(st);

    if(isEmpty(st)) printf("\nThe Stack is empty...\n");
    else
    {
        printf("Elements: \n");
        for(int i = 0; i <= st->top; i++)
        {
            printf("%d\n", st->items[i]);
        }
    }

	freeStack(st);
    return 0;
}
