#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "include/queue.h"


RegularQueue *init_regular_queue(unsigned capacity) {
	RegularQueue *q;
	q = (RegularQueue*) malloc(sizeof(RegularQueue));

	q->capacity = capacity;
	q->front = 0;
	q->rear = capacity - 1;
	q->size = 0;
	q->items = (int*) malloc(q->capacity * sizeof(int));

	return q;
}

int is_full(RegularQueue *q) { return (q->size == q->capacity); }
int is_empty(RegularQueue *q) { return (q->size == 0); }

void enqueue(RegularQueue *q, int item) {
	int tmp;

	if(is_full(q)) return;

	q->rear = (q->rear + 1) % q->capacity;
	tmp = q->rear;
	q->items[tmp] = item;
	q->size = q->size + 1;

	printf("\t%d Added to the Queue.\n", item);
}

int dequeue(RegularQueue *q) {
	int item, tmp;

	if(is_empty(q)) return INT_MIN;

	tmp = q->front;
	item = q->items[tmp];
	q->front = (q->front + 1) % q->capacity;
	q->size = q->size - 1;

	return item;
}
