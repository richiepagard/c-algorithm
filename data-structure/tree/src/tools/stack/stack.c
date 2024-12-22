#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../../../include/stack.h"


StackNode *initializeStackNode(TreeNode *tree_node) {
    /*  initialize a new stack node.
        creates a new stack node, assings the provided tree node to it,
        and initializes the next pointer to the NULL.


        @tree_node: pointer to the tree node to be stored in the stack node

        proccess:
            - allocate a new stack node
            - check if memory allocation was successful
            - set the tree node of the new stack node to the provided tree node
            - make the new node point to the NULL
    */
    
    StackNode *new_node = (StackNode*) malloc(sizeof(StackNode));   // allocate the memory for the new stack node

    if(new_node == NULL)
    {
        printf("Memory Allocation Failed For StackNode! \n");
        return NULL;
    }

    new_node->tree_node = tree_node;    // store the tree node in the stack node
    new_node->next = NULL;

    return new_node;
}

bool isEmpty(StackNode *top) {
    return (top == NULL);
}


void push(StackNode **top, TreeNode *node) {
    /*  push the tree node onto the stack

        @top: pointer to the pointer of the stack's top node -updated to the new node-
        @node: pointer to the tree node to be stored in the stack

        proccess:
            - make the new node point to the current top of the stack
            - update the top pointer to the newly created stack node
    */

    StackNode *new_node = initializeStackNode(node);

    if(new_node == NULL) return;

    new_node->next = *top;  // link the new node to the current top of the stack

    (*top) = new_node;  // update the top of the stack to the new node
}

TreeNode *pop(StackNode **top) {
    if(isEmpty(*top))
    {
        printf("Stack Underflow. No elements to pop.\n");
        return NULL;
    }

    StackNode *current = *top;
    TreeNode *result = current->tree_node;

    *top = current->next; // update the top pointer to the next node in the stack
    free(current);  // deallocate the memory of the popped node
    return result;  // return the tree node of the popped stack node
}
