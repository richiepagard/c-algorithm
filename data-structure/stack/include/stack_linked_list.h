#ifndef STACK_LINKEDLIST_H
#define STACK_LINKEDLIST_H

typedef struct node {
	int data;
	struct node *next;
} Node;

typedef struct stack_linked_list {
	/* struct representing a node in the linked list  */

	Node *top;
} StackLinkedList;

Node *init_node_singly(int value);
StackLinkedList *init_stack_linked_list();

void push_linked_list(StackLinkedList *st, int value);
void pop_linked_list(StackLinkedList *st);

int is_empty_stack_linked_list(StackLinkedList *st);
int peek_linked_list(StackLinkedList *st);

#endif
