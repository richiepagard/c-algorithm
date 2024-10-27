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

Node *initialNodeSingly(int value);
StackLinkedList *initialStackLinkedList();

void pushLinkedList(StackLinkedList *st, int value);
void popLinkedList(StackLinkedList *st);

int isEmptyStackLL(StackLinkedList *st);
int peekLinkedList(StackLinkedList *st);

#endif
