#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


int main() {

    // Regular Queue
    printf("\nThe Regular Queue Test In Main:\n");

	RegularQueue *regularQ;
	regularQ = initialRegular(5);
	enqueue(regularQ, 1);
	enqueue(regularQ, 3);

	printf("Before Deletion Action:\n");
	printf("Size:%d\t\tFront:%d\t\tRear:%d\t\tCapacity:%d\n", regularQ->size, regularQ->front, regularQ->rear, regularQ->capacity);

	printf("Item %d Deleted.\n", dequeue(regularQ));

	printf("After Deletion Action:\n");
	printf("Size:%d\t\tFront:%d\t\tRear:%d\t\tCapacity:%d\n", regularQ->size, regularQ->front, regularQ->rear, regularQ->capacity);

    // Circular Queue
    printf("\nThe Circular Queue Test In Main:\n");

    CircularQueue *circularQ;
	circularQ = initialCicular(4);
	enqueueCicular(circularQ, 3);
	enqueueCicular(circularQ, 6);
	enqueueCicular(circularQ, 9);
	printf("\nBefore Deletion Action:");
	show(circularQ);

	printf("\n\nAfter Deletion Action:");
	int item = dequeueCicular(circularQ);
	show(circularQ);
	printf("\n\n");

    return 0;
}
