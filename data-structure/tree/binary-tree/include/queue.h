#ifndef QUEUE_H
#define QUEUE_H

#include "traverse.h"   // use for get the TreeNode structure

typedef struct queue {
    TreeNode **data;    // array of pointers to the TreeNode
    int front, rear;
    int capacity;   // maximum number of elements in the queue
} Queue;

Queue *initializeQueue(int capacity);

TreeNode *dequeue(Queue *queue);
void enqueue(Queue *queue, TreeNode *node);

int isQueueEmpty(Queue *queue);

#endif  // QUEUE_H
