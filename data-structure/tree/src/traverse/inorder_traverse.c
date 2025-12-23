#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../include/traverse.h"
#include "../include/stack.h"


void inorder_iterator(TreeNode *root) {
    TreeNode *current = root;   // initialize the current node to the root
    StackNode *top = NULL;  // initialize the stack

    if(root == NULL)
    {
        printf("Tree Is Empty !\n");
        return;
    }

    while(current != NULL || !is_empty(top))
    {
        if(current != NULL) {
            push(&top, current);    // push the current node onto the stack
            current = current->left;    // move to the left child
        }
        else
        {
            current = pop(&top);    // pop the top node from the stack
            printf(" %d ", current->data);  // print the node's data
            current = current->right;   // move the right child
        }
    }
    printf("\n");
}

void inorder_recursive(TreeNode *node) {
    /*  inorder traverse on the binary tree

        @node: pointer to the current node being visited

        traverse the left subtree first, then print the value of the current node,
        and finally the right subtree

        Inorder( L V R )
    */

   if(node == NULL) return;

   inorder_recursive(node->left); // recursively traverse the left subtree
   printf(" %d ", node->data);    // print the data of the current node
   inorder_recursive(node->right);    // recursively traverse the right subtree
}
