#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../include/binary_tree.h"
#include "../include/bst.h"
#include "../include/traverse.h"


void run_bst_example() {
	/*	creates a simple bst-binary search tree- structure

        The tree structure created:
            8
           / \
          5   30
             /
            20
	*/

	TreeNode *root_node;

	printf("Running BST Example...\n");

	root_node = initializeTreeNode(8);	// initialize the root node with a value of 8
	
	// create left and right children of the root node
	root_node->left = initializeTreeNode(5);
	root_node->right = initializeTreeNode(30);

	root_node->right->left = initializeTreeNode(20);	// create a left child for the right node
	
	insertBST(root_node, 9);	// insert a new node with value 9

	printf("\nInorder traverse on BST (ITERATOR): \n");
	inorderIterator(root_node);

	deleteNodeBST(root_node, 8);
	printf("\nInorder traverse on BST (ITERATOR) after deletion action of key `8`: \n");
	inorderIterator(root_node);


	// call the tool functions here
}
