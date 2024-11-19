#include <stdio.h>
#include <stdlib.h>

#include "../../include/traverse.h"


void postorder_recursive(TreeNode *node) {
    /*  postorder traverse on the binary tree

        @node: pointer to the current node being visited

        traverse the left subtree first, then traverse the right subtree,
        and finally print the value of the current node

        Postorder( L R V )
    */

    if(node == NULL) return;

    postorder_recursive(node->left);  // recursively traverse the left subtree
    postorder_recursive(node->right); // recursively traverse the right subtree
    printf(" %d ", node->data); // print the data of the current node
}
