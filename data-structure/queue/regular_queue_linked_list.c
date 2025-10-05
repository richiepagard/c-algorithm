#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "include/queue_linked_list.h"


Node *init_node_singly(int value) {
    /* initial (create) a new node */
    Node *new_node = (Node*) malloc(sizeof(Node));

    if(new_node == NULL) {
        printf("Couldn't Allocate !\n");
        return NULL;
    } else {
        new_node->data = value;
        new_node->next = NULL;
        return new_node;
    }
}

RegularQueueLinkedList *init_regular_queue_linked_list(unsigned capacity) {
    /* initial (create) a new regular queue with singly linked list */
    RegularQueueLinkedList *q;
    q = (RegularQueueLinkedList*) malloc(sizeof(RegularQueueLinkedList));

    q->capacity = capacity;
    q->front = q->rear = NULL;
    q->items = (int*) malloc(q->capacity * sizeof(int));

    return q;
}

int is_empty_regular_queue_linked_list(RegularQueueLinkedList *q) {
    /*  RegularQLL = Regular Queue Linked List 
        Check if the queue is empty or not!
    */
    if(q->front == NULL && q->rear == NULL) return 1;
    return 0;
}

void enqueue_linked_list(RegularQueueLinkedList *q, int item) {
    Node *new_node = init_node_singly(item);    // initialize a new node
    
    if(q->rear == NULL) {
        /* if queue is empty, the new node is both the front and rear */
        q->front = q->rear = new_node;
        return;
    }
    q->rear->next = new_node;    // add the new node at the end of the queue
    q->rear = new_node;    // change the rear
}

void dequeue_linked_list(RegularQueueLinkedList *q) {
    /* delete the front item of the queue and deallocate the memory of the item */
    
    Node *temp = q->front;
    
    if(is_empty_regular_queue_linked_list(q))
    {
        printf("Queue Underflow...\n");
        return;
    }

    q->front = q->front->next;  // move front a node ahead

    if(q->front == NULL) q->rear = NULL;

    free(temp); // deallocate the memory of the old front node
}

int get_front(RegularQueueLinkedList *q) {
    if(is_empty_regular_queue_linked_list(q))
    {
        printf("Queue Is Empty...\n");
        return INT_MIN;
    }
    return q->front->data;
}

int get_rear(RegularQueueLinkedList *q) {
    if(is_empty_regular_queue_linked_list(q))
    {
        printf("Queue Is Empty...\n");
        return INT_MIN;
    }
    return q->rear->data;
}
