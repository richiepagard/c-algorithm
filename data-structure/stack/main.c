#include <stdio.h>
#include <stdlib.h>

#include "include/stack.h"
#include "include/stack_linked_list.h"


int main() {
    Stack *st;
    st = init_stack(5);
    push(st, 1);
    push(st, 2);
    push(st, 3);

    pop(st);

    if(is_empty(st)) printf("\nThe Stack is empty...\n");
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

	free_stack(st);

	StackLinkedList *stack_ll;
    stack_ll = init_stack_linked_list();

    push_linked_list(stack_ll, 3);
    push_linked_list(stack_ll, 6);
    push_linked_list(stack_ll, 9);
    printf("The top item of the stack linked list: %d\n", peek_linked_list(stack_ll));

    popLinkedList(stack_ll);
    printf("The top item of the stack linked list after deletion: %d\n", peek_linked_list(stack_ll));

    free(stack_ll);

    return 0;
}
