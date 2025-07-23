#include <stdbool.h>

typedef struct tree_node_t {
    int data;
    struct tree_node_t *left;
    struct tree_node_t *right;
} tree_node_t;

typedef struct tree_t {
    tree_node_t *root;
    size_t size;
} tree_t;

bool is_bst_helper(tree_node_t* node){
    if (node == NULL)
        return true;
    
    if (node->left->data <= node->data && node->right->data >= node->data)
        return (is_bst_helper(node->left) && is_bst_helper(node->right)) ? true : false;
    else 
        return false;
}

bool is_bst(tree_t *t){
    return is_bst_helper(t->root);
}
