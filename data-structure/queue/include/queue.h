#ifndef QUEUE_H
#define QUEUE_H

// Regular Queue
typedef struct queue {
    int *items;
    int front;
    int rear;
    int size;
    unsigned capacity;
} RegularQueue;

int is_full(RegularQueue *q);
int is_empty(RegularQueue *q);

RegularQueue *init_regular_queue(unsigned capacity);
void enqueue(RegularQueue *q, int item);
int dequeue(RegularQueue *q);


// Curcular Queue
typedef struct circularQueue {
	int *items;
	int front;
	int rear;
	int size;
} CircularQueue;


CircularQueue *init_circular_queue(unsigned capacity);
void enqueue_circular(CircularQueue *q, int item);
int dequeue_circular(CircularQueue *q);
void show(CircularQueue *q);

#endif // QUEUE_H
