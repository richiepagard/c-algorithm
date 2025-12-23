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

    root_node = init_tree_node(1);  // initialize the root node with a value of 1

    // create left and right children of the root node
    root_node->left = init_tree_node(2);
    root_node->right = init_tree_node(3);

    // create left and right children of the left node
    root_node->left->left = init_tree_node(4);
    root_node->left->right = init_tree_node(5);

    root_node->left->right->left = init_tree_node(6);   // create a left child for the node with value 5

    // print the height of the binary tree from the root node
    printf("The height of the root node is: %d\n", height_node(root_node));

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
    delete_tree(&root_node);
}
