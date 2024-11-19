#include <stdio.h>
#include <stdlib.h>

#include "../../include/traverse.h"
#include "../../include/binary_tree.h"


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
