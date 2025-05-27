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
}

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
}

void list_insert(list_t* l, int data, size_t i){
    if (i == list_size(l)-1)
    {
        list_append(l, data);
    } else if (i == 0)
    {
        list_prepend(l, data);
    } else{
        size_t k;
        list_node_t* aux = l->head;

        // Encontra o elemento antes de i
        for (k = 0; k < i-1; k++)
            aux = aux->next;

        // Cria new node
        list_node_t* new_node = malloc(sizeof(list_node_t));
        new_node->data = data;

        // aponta new node para i
        new_node->next = aux->next;

        // aponta i-1 para new node
        aux->next = new_node;
    }

    l->size++;
}