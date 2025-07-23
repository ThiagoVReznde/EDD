#include <stdio.h>
#include <stdlib.h>

// 1753270159:33c29ef98232d82fed169c62d4971aa5

/*
typedef struct bst_node_t {
    int data;
    struct bst_node_t *left;
    struct bst_node_t *right;
    } bst_node_t;

typedef struct bst_t {
    bst_node_t *root;
    size_t size;
    } bst_t;
*/

bst_node_t* bst_new_node(int data){
    bst_node_t* new_node;
    new_node = malloc(sizeof(bst_node_t));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

bst_node_t *bst_insert_helper(bst_node_t *node, int data) {
    // se for nulo, cria o novo node
    if (node == NULL)
        return bst_new_node(data);

    // define node->left/right como o novo node
    if (data < node->data) {
        node->left = bst_insert_helper(node->left, data);
    } else {
        node->right = bst_insert_helper(node->right, data);
    }

    // retorna node p/ node->left/right
    // volta p/ root
    return node;
}

void bst_insert(bst_t *t, int data){
    t->root = bst_insert_helper(t->root, data);
    t->size++;
}

