#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../include/traverse.h"
#include "../include/stack.h"


void inorderIterator(TreeNode *root) {
    TreeNode *current = root;   // initialize the current node to the root
    StackNode *top = NULL;  // initialize the stack

    if(root == NULL)
    {
        printf("Tree Is Empty !\n");
        return;
    }

    while(current != NULL || !isEmpty(top))
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

void inorderRecursive(TreeNode *node) {
    /*  inorder traverse on the binary tree

        @node: pointer to the current node being visited

        traverse the left subtree first, then print the value of the current node,
        and finally the right subtree

        Inorder( L V R )
    */

   if(node == NULL) return;

   inorderRecursive(node->left); // recursively traverse the left subtree
   printf(" %d ", node->data);    // print the data of the current node
   inorderRecursive(node->right);    // recursively traverse the right subtree
}
