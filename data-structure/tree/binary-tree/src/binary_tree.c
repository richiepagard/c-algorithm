#include <stdio.h>
#include <stdlib.h>

#include "../include/binary_tree.h"


Node *initializeNode(int value) {
    Node *new_node = (Node*) malloc(sizeof(Node));

    if(new_node == NULL)
    {
        printf("Couldn't Allocate...\n");
        return NULL;    // return NULL if memory allocation fails
    }

    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;    // return the new node
}

int heightNode(Node *node) {
    /*  finds the height of the binary tree node

        @node: pointer to the node to find the height of

        return -1 if the node is NULL (no heigh),
        return 0 if the node has no children (leaf node),
        otherwise, return 1 plus the height of the greater subtree
    */
    
    int left_height, right_height;  // height of the left and right subtrees

    if(node == NULL) return -1; // return -1 for NULL nodes, indicating no height
    else if( (node->left == NULL) && (node->right == NULL) )
        return 0;   // return 0 for leaf nodes, as they have height 0
    else
    {
        // calculate the heights of left and right subtrees
        left_height = heightNode(node->left);
        right_height = heightNode(node->right);

        /*  return the greater height between left and right subtrees,
            adding 1 to account for the current node level
        */
        if(left_height > right_height) return (left_height + 1);
        else return (right_height + 1);
    }
}
