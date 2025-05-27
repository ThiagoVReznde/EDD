#include "grader.h"

void list_reverse(list_t* l){
    if (list_size(l) <= 1)
    {
        return;
    }
    
    // variaveis pra fazer a mudança
    list_node_t* prev_node = NULL;
    list_node_t* curr_node = l->head;
    list_node_t* next_node = curr_node->next;

    // ja alterando a head para ser
    // a nova tail;
    l->head = l->tail;
    l->tail = curr_node;

    // rotina:
    // atual aponta para anterior
    // todos avançam 1
    // ate *curr == null
    while (curr_node != NULL)
    {
        curr_node->next = prev_node;

        prev_node = curr_node;
        curr_node = next_node;
        if(next_node != NULL)
            next_node = next_node->next;
    }
}
