#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"


Node *initialNodeSingly(int value) {
    Node *new_node = (Node*) malloc(sizeof(Node));

    if(new_node == NULL)
    {
        printf("Couldn't Allocate !\n");
        return NULL;
    } else {
        new_node->data = value;
        new_node->next = NULL;
        return new_node;
    }
}

void insertBeginSingly(Node **head, Node *new_node) {    
    if(*head == NULL)
    {
        // if the list is empty, the new node is the head node
        *head = new_node;
        new_node->next = NULL;
    } else {
        new_node->next = *head; // the new node point to the current head node
        *head = new_node;   // the new node become to the head node
    }
}

void insertLastSingly(Node **head, Node *new_node) {
    Node *current = *head;

    if(*head == NULL)
    {
        // if the list is empty, the new node is the head node
        *head = new_node;
        new_node->next = NULL;
    } else {
        while(current->next != NULL) current = current->next;   // traverse to the last node
        new_node->next = NULL;  // the next of new node point to the NULL, because this node is the last node
        current->next = new_node;   // the old last node, point to the new node
    }
}

void displaySingly(Node **head) {
    Node *temp;
    temp = *head;

    if(*head == NULL)
    {
        printf("The List Is Empty !\n");
        return;
    }

    printf("The Elements Of The List: \n");
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
