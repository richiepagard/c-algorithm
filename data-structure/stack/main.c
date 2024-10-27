#include <stdio.h>
#include <stdlib.h>

#include "include/stack.h"
#include "include/stack_linked_list.h"


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

	StackLinkedList *stack_ll;
    stack_ll = initialStackLinkedList();

    pushLinkedList(stack_ll, 3);
    pushLinkedList(stack_ll, 6);
    pushLinkedList(stack_ll, 9);
    printf("The top item of the stack linked list: %d\n", peekLinkedList(stack_ll));

    popLinkedList(stack_ll);
    printf("The top item of the stack linked list after deletion: %d\n", peekLinkedList(stack_ll));

    free(stack_ll);

    return 0;
}
