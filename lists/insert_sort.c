#include "grader.h"

void list_prepend(list_t* l, int data){
    list_node_t* new_head = malloc(sizeof(list_node_t));
    new_head->data = data;
    new_head->next = l->head;

    l->head = new_head;
    if(list_empty(l)){
        l->tail = new_head;
    }
    l->size++; 
}

void list_append(list_t* l, int data){
    list_node_t* new_tail = malloc(sizeof(list_node_t));
    new_tail->data = data; // se nao passar o dado ele nao eh salvo neh???
    new_tail->next = NULL; 

    if(list_empty(l)){
        l->head = new_tail;
    } else{
        l->tail->next = new_tail;
    }

    l->tail = new_tail;
    l->size++; 
}

void list_insertionsort_insert(list_t* l, int data){
    list_node_t* aux = l->head;
    size_t i;
    
    for (i = 0; aux->data < data && aux->next != NULL; i++)
        aux = aux->next;
    
    if(list_empty(l) || i == 0){
        list_prepend(l, data);
    } else if(i == list_size(l)-1){ // i para no ultimo termo; nn em size
        list_append(l, data);
    } else{
        list_node_t* new_node = malloc(sizeof(list_node_t));
        new_node->data = data; // se nao passar o dado ele nao eh salvo neh        
         
        new_node->next = aux->next;
        aux->next = new_node;

        l->size++; 
    }
}
