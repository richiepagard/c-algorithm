#include <stdio.h>
#include <stdlib.h>
#include <stack.h>


int main() {
    Stack *st;
    st = initialStack(5);
    push(st, 1);
    push(st, 2);
    push(st, 3);

    pop(st);

    if(isEmpty(st)) printf("\nThe Stack is empty...\n");
    else
    {
        printf("Elements: \n");
        for(int i = 0; i <= st->top; i++)
        {
            printf("%d\n", st->items[i]);
        }
    }

    int top = peek(st);
    printf("The top item: %d\n", top);

	freeStack(st);
    return 0;
}
