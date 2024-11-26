#include <stdio.h>
#include <stdlib.h>

#include "../../include/binary_tree.h"
#include "../../include/queue.h"


Queue *initializeQueue(int capacity) {
    Queue *new_queue = (Queue *) malloc(sizeof(Queue));
    if(!new_queue)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    new_queue->data = (TreeNode **) malloc(capacity * sizeof(TreeNode*));
    if(!new_queue->data)
    {
        printf("Memory allocation failed!\n");
        free(new_queue);
        return NULL;
    }

    new_queue->front = new_queue->rear = 0;
    new_queue->capacity = capacity;
    return new_queue;
}

void enqueue(Queue *queue, TreeNode *node) {
    if(queue->rear == queue->capacity)
    {
        printf("Queue is full!\n");
        return;
    }

    queue->data[queue->rear++] = node; // add the node and increment rear
}

TreeNode *dequeue(Queue *queue) {
    if(queue->front == queue->rear)
    {
        printf("Queue is empty!\n");
        return NULL;
    }

    return queue->data[queue->front++]; // remove the node and increment front
}

int isQueueEmpty(Queue *queue) {
    return queue->front == queue->rear;
}
