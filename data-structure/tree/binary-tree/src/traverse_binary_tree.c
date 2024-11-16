#include <stdio.h>
#include <stdlib.h>

#include "../include/binary_tree.h"


void preorder(Node *node) {
    /*  preorder traverse on the binary tree

        @node: pointer to the current node being visited

        print the value of the current node, then recursively traverse
        the left subtree and the right subtree

        Preorder( V L R )
    */
    
    if(node == NULL) return;

    printf(" %d ", node->data); // print the data of the current node
    preorder(node->left);   // recursively traverse the left subtree
    preorder(node->right);  // recursively traverse the right subtree
}

void inorder(Node *node) {
    /*  inorder traverse on the binary tree

        @node: pointer to the current node being visited

        traverse the left subtree first, then print the value of the current node,
        and finally the right subtree

        Inorder( L V R )
    */

   if(node == NULL) return;

   inorder(node->left); // recursively traverse the left subtree
   printf(" %d ", node->data);    // print the data of the current node
   inorder(node->right);    // recursively traverse the right subtree
}

void postorder(Node *node) {
    /*  postorder traverse on the binary tree

        @node: pointer to the current node being visited

        traverse the left subtree first, then traverse the right subtree,
        and finally print the value of the current node

        Postorder( L R V )
    */

    if(node == NULL) return;

    postorder(node->left);  // recursively traverse the left subtree
    postorder(node->right); // recursively traverse the right subtree
    printf(" %d ", node->data); // print the data of the current node
}
