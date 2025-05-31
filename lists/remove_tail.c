#include "grader.h"

void list_remove_tail(list_t* l){
    if(list_empty(l)){
        return;
    }

    if(list_size(l) == 1){
        l->head = NULL;
        l->tail = NULL;
    } else{
        list_node_t *aux = l->head;
        
        while(aux->next != l->tail)
            aux = aux->next;
        
        aux->next = NULL;
        free(l->tail);

        l->tail = aux;
    }

    l->size--;
}