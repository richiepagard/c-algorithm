#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#include "../include/binary_tree.h"
#include "../include/queue.h"


TreeNode *initializeTreeNode(int value) {
    /*  initialize a new tree node.
        creates a new tree node, assigns the provided value to its data field,
        and sets the left and right children to the NULL.

        @value: the value to assign to the data field of the new tree node

        proccess:
            - allocate a new tree node
            - check if memory allocation was successfull
            - assign the provided value to the data field of the new node
            - set the left and right child pointers to NULL
    */

    TreeNode *new_node = (TreeNode*) malloc(sizeof(TreeNode));    // allocate the memory for the new tree node

    if(new_node == NULL)
    {
        printf("Memory Allocation Failed For TreeNode! \n");
        return NULL;
    }

    new_node->data = value; // assign the provided value to the new node
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}


int heightNode(TreeNode *node) {
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
        return (left_height > right_height) ? (left_height + 1) : (right_height + 1);
    }
}

unsigned int leafQuantity(TreeNode *node) {
    /*  return the total quantity of leafs

        @node: pointer to the current node being checked

        return 0 if the node is NULL,
        return 1 if the node is leaf,
        otherwise, return the sum of leaf counts
        from the left and right subtrees
    */
    
    if(node == NULL) return 0;  // return 0 for NULL nodes
    else if( (node->left == NULL) && (node->right == NULL) ) return 1;  // return 1 for the leaf node

    // count leaf nodes in the left and right subtrees
    else return ( leafQuantity(node->left) + leafQuantity(node->right) );
}

unsigned int nodesQuantity(TreeNode *node) {
    /*  return the total quantity of nodes

        @node: pointer to the current node being checked

        return 0 if the node is NULL,
        otherwise, return the sum of node counts
        from the left and right subtree and at the end plus 1
    */

    return (node == NULL) ? 0 : (1 + nodesQuantity(node->left) + nodesQuantity(node->right));
}

int maxNode(TreeNode *node) {
    /*  find the maximum node of binary tree

        @node: pointer to the node to find the maximum of

        return INT_MIN if the node is NULL,
        otherwise, return the maxium node of the greater subtree
    */
    
    int max, left_max, right_max;   // maximum of the left and right subtrees

    if(node == NULL) return INT_MIN;

    max = node->data;
    // find the maximum node of left and right subtrees
    left_max = maxNode(node->left);
    right_max = maxNode(node->right);

    // save the greater node between left and right subtrees to the `max` variable
    max = (left_max > max ? left_max : max);
    max = (right_max > max ? right_max : max);

    return max; // return the maximum node
}

int identical(TreeNode *node1, TreeNode *node2) {
    if(node1 == NULL && node2 == NULL) return 1;
    if(node1 != NULL && node2 != NULL) return( node1->data == node2->data && identical(node1->left, node2->left) && identical(node1->right, node2->right) );
    return 0;
}

bool isComplete(TreeNode *root, int capacity) {
    /*  if a tree -binary tree- is complete or not

        @root: pointer to the root node of the tree
        @capacity: the maximum capacity of the queue used for the level-order traversal

        a complete binary tree is one in which all levels are fully filled except possibly the last,
        and the nodes in the last level are as far left as possible. return true
        if the tree is complete; otherwise, return false.
    */

    if(root == NULL) return true;   // because an empty tree is considered complete

	Queue *q = initializeQueue(capacity);
	enqueue(q, root);

	bool flag = false;  // to indicate if a non-full node has been encountered

	while(!isQueueEmpty(q))
	{
		TreeNode *current = dequeue(q);

		if(current->left)	// check the left child
		{
			if(flag) {  // if encountered a non-full node, the tree isn't complete
				free(q->data);
				free(q);
				return false;
			}
			enqueue(q, current->left);
		} else flag = true; // mark to encountered a non-full node

		if(current->right)	// check the right child
		{
			if(flag) {
				free(q->data);
				free(q);
				return false;
			}
			enqueue(q, current->right);
		} else flag = true;
	}	// END WHILE

	/* deallocate(free) the queue memory */
	free(q->data);
	free(q);
	return true;
}

int findLevel(TreeNode *node, int data, int level) {
    /*  find the level of a node with the specified data

        @node: pointer to the current node being visited
        @data: the value to search for in the tree
        @level: the current level of the node being visited -starts at 1 for the root node-
    */

    int current;

    if(node == NULL) return 0;
    if(node->data == data) return level;    // return current level if the data matches

    // recursively search in the left and right subtree, increasing the level by 1
    current = findLevel(node->left, data, level+1);
    if(current != 0) return current;
    current = findLevel(node->right, data, level+1);

    return current;
}

bool ancestors(TreeNode *node, int data) {
    if(node == NULL) return false;  // return false for an empty tree or when the target node isn't found
    if(node->data == data) return true; // return true, if the target found

    // check recursively in the left and right subtree for the target node
    if(ancestors(node->left, data) || ancestors(node->right, data))
    {
        printf("\n %d ", node->data);   // print the current node as it is an ancestor
        return true;
    }

    return false;   // target node not found in either subtree
}

TreeNode *LCA(TreeNode *root, int x, bool x_flag, int y, bool y_flag) {
    if(root == NULL) return NULL;

    /*  check if root's data equal to the `x` or `y`, then update the flag of themself to true and return root node,
        because when we want to find the Lowest Common Ancestor of a node with root node, the ancestor is root :/
    */
    if(root->data == x) {
        x_flag = true;
        return root;
    }
    if(root->data == y) {
        y_flag = true;
        return root;
    }

    TreeNode *leftLCA, *rightLCA;   // initial left and right pointers for check the left and right child nodes
    // recursively search in the left and right subtree
    leftLCA = LCA(root->left, x, x_flag, y, y_flag);
    rightLCA = LCA(root->right, x, x_flag, y, y_flag);
    if(leftLCA && rightLCA) return root;

    // return leftLCA if it's exists, otherwise, return rightLCA
    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

TreeNode *LCAWitchDefault(TreeNode *root, int x, int y) {
    /*  this is a wrapper function for set default values of flag of x and flag of y 
        and maybe some another default settings
    */

    return LCA(root, x, false, y, false);
}

TreeNode *leftMost(TreeNode *root) {
	/*	this function find and return the most left node
		from a tree, start from root and find the last left node
	*/
	TreeNode *current = root;

	if(root == NULL) return NULL;

	while(current->left != NULL) current = current->left;

	return current;
}


void deleteTree(TreeNode **node) {
    /*  delete all nodes in the binary tree, delete the whole tree

        @node: pointer to the current node being deleted

        recursively deletes the left and right subtrees, then
        delete the current node itself and each deletion is printed
    */

    if(node == NULL || *node == NULL) return;

    deleteTree(&(*node)->left); // delete all nodes in the left subtree
    deleteTree(&(*node)->right);    // delete all nodes in the right subtree

    printf("\tDelete the node (%d)\n", (*node)->data); // print each node during deletion

    free(*node); // free memory of the current node
    *node = NULL;   // set the root node to the NULL
}
