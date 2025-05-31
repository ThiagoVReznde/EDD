#include "grader.h"

void list_remove_head(list_t* l){
    if(list_empty(l)){
        return;
    }
    // Acessa "Head" a ser removido
    list_node_t *aux = l->head;

    // Se tiver 1 elemento, tem de atualizar a cauda para null
    if (list_size(l) == 1){
        l->tail = NULL;
    }

    // Atualiza Head na lista para ser o proximo termo
    l->head = l->head->next;

    // Remove dados do "Head" anterior
    free(aux);

    // Diminui tamanho da lista
    l->size--;
    // Nota!
    // nop, nao funciona como imaginei
    // Cauda null = Nao tem cauda
    // nao ter a mudança ainda teria um ponteiro apontando
    // para uma cauda que deixou de existir
}

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

void list_remove(list_t* l, size_t i){
    if(list_empty(l) || list_size(l)-1 < i){
        return;
    }
    
    if(i == 0){
        list_remove_head(l);
    } else if (i == list_size(l)-1)
    {
        list_remove_tail(l);
    } else {
        int k;
        list_node_t *aux = l->head;

        for (k = 0; k < i-1; k++)
            aux = aux->next;

        list_node_t *node_to_be_removed = aux->next;

        aux->next = node_to_be_removed->next;

        free(node_to_be_removed);
        l->size--;
    }
}