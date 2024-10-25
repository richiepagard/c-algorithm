#ifndef QUEUE_LINKEDLIST_H
#define QUEUE_LINKEDLIST_H

// Regular Queue With Singly Linked List
typedef struct node {
	int data;
	struct node *next;
} Node;

typedef struct queue_linked_list {
	Node *front, *rear;
	int *items;
	unsigned capacity;
} RegularQueueLinkedList;

Node *initialNodeSingly(int value);
RegularQueueLinkedList *initialRegularQueueLinkedList(unsigned capacity);
int isEmptyRegularQLL(RegularQueueLinkedList *q);
void enqueueLinkedList(RegularQueueLinkedList *q, int item);
int getFront(RegularQueueLinkedList *q);


#endif // QUEUE_LINKEDLIST_H
