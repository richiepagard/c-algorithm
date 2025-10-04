#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "include/stack_linked_list.h"


Node *init_node_singly(int value) {
    /* initial (create) a new node */
    Node *new_node = (Node*) malloc(sizeof(Node));

    if(new_node == NULL) {
        printf("Couldn't Allocate !\n");
        return NULL;
    } else {
        new_node->data = value;
        new_node->next = NULL;
        return new_node;
    }
}

StackLinkedList *init_stack_linked_list() {
	/* initial (create) a new stack with singly linked list  */
	StackLinkedList *st;
	st = (StackLinkedList*) malloc(sizeof(StackLinkedList));	// allocate the memory to the new stack

	st->top = NULL;
}


int is_empty_stack_linked_list(StackLinkedList *st) {
	/*	StackLL = Stack Linked List
		Check if the stack is empty or not!
	*/
	return st->top == NULL;
}

int peek_linked_list(StackLinkedList *st) {
	/* return the top element(node) of the stack */
	
	if(!is_empty_stack_linked_list(st)) return st->top->data;
	else
	{
		printf("Stack Is Empty...\n");
		return INT_MIN;
	}
}

void push_linked_list(StackLinkedList *st, int value) {
	/* push a new node to the top of the stack */
	
	Node *new_node = init_node_singly(value);

	if(!new_node)
	{
		printf("Stack Overflow...\n");
		return;
	}

	new_node->next = st->top;	// the next of the new node points to the top node
	st->top = new_node;	// update the top node to the new node
}

void pop_linked_list(StackLinkedList *st) {
	/* pop (delete) the top node of the stack and deallocate the memory of the node */
	
	if(is_empty_stack_linked_list(st))
	{
		printf("Stack Underflow...\n");
		return;
	} else {
		Node *temp = st->top;	// assign the current top to the temp variable
		st->top = st->top->next;	// update the top ndoe to the next node

		free(temp);	// deallocate the memory of the old top node
	}
}
