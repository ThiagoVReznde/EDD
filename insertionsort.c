#include "grader.h"

void list_insertionsort_insert(list_t* l,int data){
    size_t i = 0;
    list_node_t* aux = l->head;

    // encontra o elemento antes
    while (aux->next->data < data)
        aux = aux->next;
    
    if (i == list_size(l)-1)
    {
        list_append(l, data);
    } else if (i == 0)
    {
        list_prepend(l, data);
    } else{
        // Cria new node
        list_node_t* new_node = malloc(sizeof(list_node_t));
        new_node->data = data;

        // aponta new node para i
        new_node->next = aux->next;

        // aponta i-1 para new node
        aux->next = new_node;
    }
}