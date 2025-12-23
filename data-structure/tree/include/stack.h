#ifndef STACK_H
#define STACK_H

#include "traverse.h"   // use for get the TreeNode structure


typedef struct linked_list_node {
    /* the structure for a node in the linked list stack */

    TreeNode *tree_node;    // pointer to a tree node (data stored in the stack)
    struct linked_list_node *next;  // pointer to the next node in the stack
} StackNode;


StackNode *init_stack_node(TreeNode *tree_node);
bool is_empty(StackNode *top);
void push(StackNode **top, TreeNode *node);
TreeNode *pop(StackNode **top);


#endif  // STACK_H
