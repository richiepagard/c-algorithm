#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../include/binary_tree.h"


TreeNode* insertBSTRecursive(TreeNode* root, int value) {
	if(root == NULL) return init_tree_node(value);
	if(value < root->data)
	{
		root->left = insertBSTRecursive(root->left, value);
	}
	if(value > root->data)
	{
		root->right = insertBSTRecursive(root->right, value);
	}

	return root;
}

TreeNode* insertBST(TreeNode* root, int value) {
	if(root == NULL) return init_tree_node(value);

	TreeNode* current = root;
	TreeNode* parent = NULL;

	while(current != NULL) {	// traverse on the tree until find the correct position
		parent = current;	// keep track of the parent node

		if(value < current->data) current = current->left;
		else if(value > current->data) current = current->right;
		else return root;	// value already exists, return the root without any insertion
	}

	// create a new node and attach it to the appropriate parent node
	TreeNode* new_node = init_tree_node(value);

	if(value < parent->data) parent->left = new_node;
	else parent->right = new_node;

	return root;
}

TreeNode* searchNodeBSTRecursive(TreeNode* root, int key) {
	/*	function look at the special node with the key that provided by funciton and return it,

		check if the root is null or the data of the root is equal to the key provided by function,
		return root node.
		check if the key less than root's data, call the function(recursively) for the left node.
		otherwise, call the function(recursively) for the right node.
	*/
	if(root == NULL || root->data == key) return root;
	if(key < root->data) return searchNodeBSTRecursive(root->left, key);
	else return searchNodeBSTRecursive(root->right, key);
}

bool searchNodeBST(TreeNode* root, int key) {
	TreeNode* current = root;

	while(current != NULL)
	{
		if(key < current->data) current = current->left;
		else if(key > current->data) current = current->right;
		else return true;
	}

	return false;
}


TreeNode* findMin(TreeNode* root) {
	/* function to find a minimum value node in the subtree */

	while(root->left != NULL) root = root->left;
	return root;
}

TreeNode* deleteNodeBST(TreeNode* root, int key) {
	if(root == NULL) return root;

	TreeNode* temp;

	// recursively traverse until find the node to be deleted
	if(key < root->data) root->left = deleteNodeBST(root->left, key);
	else if(key > root->data) root->right = deleteNodeBST(root->right, key);
	else
	{
		/*	check node with only one or no child, if the node doesn't have left subtree(child),
			return the whole right subtree and remove the node, otherwise-if node doesn't have right subtree(child)-,
			then return the whole left subtree and remove the node.

			check for the node has two children, get the inorder successor at first,
			the smallest node in the right subtree, then copy the inorder successor to the node,
			then delete the inorder successor recursively.
		*/
		if(root->left == NULL) {
			temp = root->right;	// set the temp to the whole right subtree
			free(root);
			return temp;
		}
		else if(root->right == NULL) {
			temp = root->left;	// set the temp to the whole left subtree
			free(root);
			return temp;
		}

		temp = findMin(root->right);	// get the inorder successor, the smallest node in the right subtree
		root->data = temp->data;	// replace the current node's data to the inorder successor's data
		root->right = deleteNodeBST(root->right, temp->data);	// delete the inorder successor
	}

	return root;
}


void findPredecessorSuccessor(TreeNode* root, TreeNode** predecessor, TreeNode** successor, int key) {
	TreeNode* temp;
	if(root == NULL) return;

	if(key == root->data)
	{
		/*	traverse on the left subtree if it isn't NULL and find the last right node,
			traverse on the right subtree if it isn't NULL and find the last left node,
			at the end, update the predecessor and sucessor to the last left or right node
			of each left and right subtree.
		*/
		if(root->left != NULL) {
			temp = root->left;
			while(temp->right) temp = temp->right;
			*predecessor = temp;
		}
		if(root->right != NULL) {
			temp = root->right;
			while(temp->left) temp = temp->left;
			*successor = temp;
		}
	}
	else if(key < root->data)	// check if the key is smaller than root's data
	{
		*successor = root;
		// recursively find the predecessor and successor of the current node(it's in the left subtree)
		findPredecessorSuccessor(root->left, predecessor, successor, key);
	}
	else
	{
		*predecessor = root;
		// recursively find the predecessor and successor of the current node(it's in the left subtree)
		findPredecessorSuccessor(root->right, predecessor, successor, key);
	}

	// check if predecessor or successor are not NULL, print the data, otherwise, print -1
	printf("Predecessor is %d\tSuccessor is %d\n",
		(*predecessor ? (*predecessor)->data : -1),
		(*successor ? (*successor)->data : -1)
	);
}
