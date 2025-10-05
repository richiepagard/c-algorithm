#include <stdio.h>
#include <stdlib.h>

#include "include/queue.h"
#include "include/queue_linked_list.h"


int main() {

    // Regular Queue
    printf("\nThe Regular Queue Test In Main:\n\n");

	RegularQueue *regularQ;
	regularQ = init_regular_queue(5);
	enqueue(regularQ, 1);
	enqueue(regularQ, 3);

	printf("\n\tBefore Deletion Action:\n");
	printf("\tSize:%d\t\tFront:%d\t\tRear:%d\t\tCapacity:%d\n", regularQ->size, regularQ->front, regularQ->rear, regularQ->capacity);

	printf("\tItem %d Deleted.\n", dequeue(regularQ));

	printf("\n\tAfter Deletion Action:\n");
	printf("\tSize:%d\t\tFront:%d\t\tRear:%d\t\tCapacity:%d\n", regularQ->size, regularQ->front, regularQ->rear, regularQ->capacity);

	free(regularQ);

    // Circular Queue
    printf("\nThe Circular Queue Test In Main:\n\n");

    CircularQueue *circularQ;
	circularQ = init_circular_queue(4);
	enqueue_circular(circularQ, 3);
	enqueue_circular(circularQ, 6);
	enqueue_circular(circularQ, 9);
	printf("\tBefore Deletion Action:");
	show(circularQ);

	printf("\n\n\tAfter Deletion Action:");
	int item = dequeue_circular(circularQ);
	show(circularQ);
	printf("\n\n");

	free(circularQ);


	// Regular Queue Linked List
	printf("\nThe Regular Queue Linked List, Test In Main:\n\n");

	RegularQueueLinkedList *regularQLL;	// initialize a new Regular Queue Linked List
	regularQLL = init_regular_queue_linked_list(4);
	enqueue_linked_list(regularQLL, 7);
	enqueue_linked_list(regularQLL, 9);
	enqueue_linked_list(regularQLL, 2);
	printf("\tThe Front Of Queue: %d\n", get_front(regularQLL));
	printf("\tThe Rear Of Queue: %d\n", get_rear(regularQLL));

	dequeue_linked_list(regularQLL);
	printf("\n\tThe Front Of Queue After Deletion: %d\n", get_front(regularQLL));

	printf("\n");

    return 0;
}
