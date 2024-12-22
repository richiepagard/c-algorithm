#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../include/traverse.h"
#include "../include/stack.h"


void postorderIterator(TreeNode *root) {
    /*  the function performs a postorder traversal of a binary tree using two stacks approach

        1- use two stacks:
            - main stack used to traverse the tree nodes in the modified order
            - auxiliary stack temporarily stores nodes to reverse the traversal order

        2- process:
            - push the root node into the `main stack`
            - while main stack isn't empty:
                a- pop a node from `main stack` and push it into the `auxiliary stack`
                b- push the left child (if it exists) of the popped node into `main stack`
                c- push the right child (if it exists) of the popped node into the `main stack`

        3- final step:
            - at the end of the process, `auxiliary stack` contains nodes in reverse postorder
            - pop each node from `auxiliary stack` to print them in postorder sequence

        Postorder( L R V )
    */
    
    if(root == NULL)
    {
        printf("Tree Is Empty !\n");
        return;
    }

    StackNode *main_stack = NULL;  // initialize main stack for traverse
    StackNode *aux_stack = NULL;   // initialize auxiliary stack for storing temporary nodes during traversal
    push(&main_stack, root);   // push the root node onto the stack

    while(!isEmpty(main_stack))
    {
        /* pop from first stack and push to the second(auxiliar) stack */
        TreeNode *current =  pop(&main_stack);  // pop from main stack
        push(&aux_stack, current);  // push it to the auxiliary stack

        if(current->left != NULL) push(&main_stack, current->left);    // push the left chile
        if(current->right != NULL) push(&main_stack, current->right);  // push the right child
    }

    while(!isEmpty(aux_stack))
    {
        TreeNode *node = pop(&aux_stack);
        printf(" %d ", node->data);
    }
}

void postorderRecursive(TreeNode *node) {
    /*  postorder traverse on the binary tree

        @node: pointer to the current node being visited

        traverse the left subtree first, then traverse the right subtree,
        and finally print the value of the current node

        Postorder( L R V )
    */

    if(node == NULL) return;

    postorderRecursive(node->left);  // recursively traverse the left subtree
    postorderRecursive(node->right); // recursively traverse the right subtree
    printf(" %d ", node->data); // print the data of the current node
}
