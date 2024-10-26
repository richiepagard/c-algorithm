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

void enqueueLinkedList(RegularQueueLinkedList *q, int item);
void dequeueLinkedList(RegularQueueLinkedList *q);

int isEmptyRegularQLL(RegularQueueLinkedList *q);
int getFront(RegularQueueLinkedList *q);
int getRear(RegularQueueLinkedList *q);

#endif // QUEUE_LINKEDLIST_H
