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

int isFull(RegularQueue *q);
int isEmpty(RegularQueue *q);

RegularQueue *initialRegular(unsigned capacity);
void enqueue(RegularQueue *q, int item);
int dequeue(RegularQueue *q);


// Curcular Queue
typedef struct circularQueue {
	int *items;
	int front;
	int rear;
	int size;
} CircularQueue;


CircularQueue *initialCicular(unsigned capacity);
void enqueueCicular(CircularQueue *q, int item);
int dequeueCicular(CircularQueue *q);
void show(CircularQueue *q);

#endif // QUEUE_H
