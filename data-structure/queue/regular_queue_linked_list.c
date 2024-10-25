#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "include/queue_linked_list.h"


Node *initialNodeSingly(int value) {
    /* initial (create) a new node */
    Node *new_node = (Node*) malloc(sizeof(Node));  // Fixed allocation

    if(new_node == NULL) {
        printf("Couldn't Allocate !\n");
        return NULL;
    } else {
        new_node->data = value;
        new_node->next = NULL;
        return new_node;
    }
}

RegularQueueLinkedList *initialRegularQueueLinkedList(unsigned capacity) {
    /* initial (create) a new regular queue with singly linked list */
    RegularQueueLinkedList *q;
    q = (RegularQueueLinkedList*) malloc(sizeof(RegularQueueLinkedList));

    q->capacity = capacity;
    q->front = q->rear = NULL;
    q->items = (int*) malloc(q->capacity * sizeof(int));

    return q;
}

int isEmptyRegularQLL(RegularQueueLinkedList *q) {
    /*  RegularQLL = Regular Queue Linked List 
        Check if the queue is empty or not!
    */
    if(q->front == NULL && q->rear == NULL) return 1;
    return 0;
}

void enqueueLinkedList(RegularQueueLinkedList *q, int item) {
    Node *new_node = initialNodeSingly(item);    // initialize a new node
    
    if(q->rear == NULL) {
        /* if queue is empty, the new node is both the front and rear */
        q->front = q->rear = new_node;
        return;
    }
    q->rear->next = new_node;    // add the new node at the end of the queue
    q->rear = new_node;    // change the rear
}

int getFront(RegularQueueLinkedList *q) {
    if(isEmptyRegularQLL(q))    // Corrected function call
    {
        printf("Queue Is Empty...\n");
        return INT_MIN;
    }
    return q->front->data;
}
