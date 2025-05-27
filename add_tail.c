#include "grader.h"

void list_append(list_t* l,int data){
    list_node_t* new_tail = malloc(sizeof(list_node_t));
    new_tail->data = data;
    new_tail->next = NULL;

    if(list_empty(l)){
        // Nao tem tail definida
        l->head = new_tail;
    } else{
        // Tem tail definida
        // Precisa apontar old_tail para new_tail
        l->tail->next = new_tail;
    }

    l->tail = new_tail;
    l->size++;
}