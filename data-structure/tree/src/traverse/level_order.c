#include <stdio.h>
#include <stdlib.h>

#include "../include/binary_tree.h"
#include "../include/queue.h"


void levelorder(TreeNode *root, int capacity) {
    if(!root) return;

    /*
        initialize a queue to store nodes for level-order traversal,
        the queue is created with the given capacity to hold the nodes
    */
    Queue *queue = init_queue(capacity);

    enqueue(queue, root);

    while(!is_queue_empty(queue)) // proccessing nodes until the queue is empty
    {
        TreeNode *current = dequeue(queue); // dequeue the front node from the queue and save it to `current`
        printf(" %d ", current->data);

        if(current->left) enqueue(queue, current->left);    // enqueue the left child if the current node has it
        if(current->right) enqueue(queue, current->right);  // enqueue the right child if the current node has it
    }

    free(queue->data);  // deallocate(free) the nodes
    free(queue);    // deallocate(free) the queue
}
