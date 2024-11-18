#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct tree_node {
    /* the structure for a binary tree */

    int data;
    struct node *left;  // pointer to the left child
    struct node *right; // pointer to the right child
} TreeNode;

typedef struct linked_list_node {
    /* the structure for a node in the linked list stack */

    TreeNode *tree_node;    // pointer to a tree node (data stored in the stack)
    struct linked_list_node *next;  // pointer to the next node in the stack
} StackNode;


TreeNode *initializeTreeNode(int value) {
    /*  initialize a new tree node.
        creates a new tree node, assigns the provided value to its data field,
        and sets the left and right children to the NULL.

        @value: the value to assign to the data field of the new tree node

        proccess:
            - allocate a new tree node
            - check if memory allocation was successfull
            - assign the provided value to the data field of the new node
            - set the left and right child pointers to NULL
    */

    TreeNode *new_node = (TreeNode*) malloc(sizeof(TreeNode));    // allocate the memory for the new tree node

    if(new_node == NULL)
    {
        printf("Memory Allocation Failed For TreeNode! \n");
        return NULL;
    }

    new_node->data = value; // assign the provided value to the new node
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

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
