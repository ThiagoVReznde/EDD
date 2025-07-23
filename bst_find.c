#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>


bool bst_find_helper(bst_node_t* node, int data){
    if (node == NULL)
        return false;

    if (data == node->data) 
        return true;

    if (data < node->data) 
        return bst_find_helper(node->left, data);

    else
        return bst_find_helper(node->right, data);    
    
}

bool bst_find(bst_t *t, int data){
    return bst_find_helper(t->root, data);
}
