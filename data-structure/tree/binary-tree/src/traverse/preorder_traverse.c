#include <stdio.h>
#include <stdlib.h>

#include "../../include/traverse.h"


void preorder_recursive(TreeNode *node) {
    /*  preorder traverse on the binary tree

        @node: pointer to the current node being visited

        print the value of the current node, then recursively traverse
        the left subtree and the right subtree

        Preorder( V L R )
    */
    
    if(node == NULL) return;

    printf(" %d ", node->data); // print the data of the current node
    preorder_recursive(node->left);   // recursively traverse the left subtree
    preorder_recursive(node->right);  // recursively traverse the right subtree
}
