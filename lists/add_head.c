#include "grader.h"

void list_prepend(list_t* l,int data){ 
    // Cria head_novo
    // Salva os dados de new_head
    list_node_t* new_head = malloc(sizeof(list_node_t));
    new_head->data = data;
    new_head->next = l->head;

    // Aponta l_head para new_head
    l->head = new_head;
    
    // se nn tiver elementos,tail = head
    if (list_empty(l))
    {
        l->tail = new_head;
    }
    
    l->size++;
}