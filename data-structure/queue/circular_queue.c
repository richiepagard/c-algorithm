#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "queue.h"


CircularQueue *initialCicular(unsigned capacity) {
	CircularQueue *q;
	q = (CircularQueue*) malloc(sizeof(CircularQueue));

	q->items = (int*) malloc(capacity * sizeof(int));
	q->front = -1;
	q->rear = -1;
	q->size = capacity;
}

void enqueueCicular(CircularQueue *q, int item) {
	if( (q->front == 0 && q->rear == q->size - 1) || (q->rear == q->front - 1) )
	{
		printf("\nThe Queue is full.");
		return;
	}
	else if(q->front == -1)
	{
		// insert first element
		q->front = 0;
		q->rear = 0;
		q->items[q->rear] = item;
	}
	else if(q->rear == q->size - 1 && q->front != 0)
	{
		// if rear is the last element(size - 1), then item will add to the first(items[0]) element
		q->rear = 0;
		q->items[q->rear] = item;
	}
	else
	{
		q->rear++;
		q->items[q->rear] = item;
	}
}


int dequeueCicular(CircularQueue *q) {
	int item = q->items[q->front];
	q->items[q->front] = -1;

	if(q->front == -1)
	{
		printf("\nThe Queue is empty.");
		return INT_MIN;
	}
	else if(q->front == q->rear)
	{
		q->front = -1;
		q->rear = -1;
	}
	//	if front is the last element(size - 1), then item will add to the first(items[0]) element
	else if(q->front == q->size - 1) q->front = 0;
	else q->front++;

	return item;
}


void show(CircularQueue *q) {
	if(q->front == -1)
	{
		printf("\nThe Queue is empty.");
		return;
	}
	printf("\nElements: ");
	if(q->front <= q->rear)
	{
		for(int i = q->front; i <= q->rear; i++) printf("%d\t", q->items[i]);
	}
	else
	{
		for(int i = q->front; i < q->size; i++) printf("%d\t", q->items[i]);
		for(int i = 0; i <= q->rear; i++) printf("%d\t", q->items[i]);
	}
}
