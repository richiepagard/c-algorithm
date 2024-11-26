#include <stdio.h>
#include <stdlib.h>

#include "../include/binary_tree.h"
#include "../include/traverse.h"


void run_binary_tree_example() {
    /*  creates a simple binary tree structure

        The tree structure created:
            1
           / \
          2   3
         / \
        4   5
           /
          6
    */

    TreeNode *root_node;

    printf("Running Binary Tree Example...\n");

    root_node = initializeTreeNode(1);  // initialize the root node with a value of 1

    // create left and right children of the root node
    root_node->left = initializeTreeNode(2);
    root_node->right = initializeTreeNode(3);

    // create left and right children of the left node
    root_node->left->left = initializeTreeNode(4);
    root_node->left->right = initializeTreeNode(5);

    root_node->left->right->left = initializeTreeNode(6);   // create a left child for the node with value 5

    // print the height of the binary tree from the root node
    printf("The height of the root node is: %d\n", heightNode(root_node));

    // call the tool functions here
    printf("The total quantity of leafs from the node is: %d\n", leafQuantity(root_node));  // total quantity of leafs


    /*  call the traversal functions
        e.g.
            inorder_recursive(root_node)
    */

    printf("\n LevelOrder traverse on the binary tree (ITERATOR): \n");
    levelorder(root_node, 100);


    // delete the whole tree
    printf("\n\nDelete the whole tree:\n");
    deleteTree(&root_node);
}
