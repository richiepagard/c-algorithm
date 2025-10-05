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

Node *init_node_singly(int value);
RegularQueueLinkedList *init_regular_queue_linked_list(unsigned capacity);

void enqueue_linked_list(RegularQueueLinkedList *q, int item);
void dequeue_linked_list(RegularQueueLinkedList *q);

int is_empty_regular_queue_linked_list(RegularQueueLinkedList *q);
int get_front(RegularQueueLinkedList *q);
int get_rear(RegularQueueLinkedList *q);

#endif // QUEUE_LINKEDLIST_H
