#include "grader.h"

// Ir para head
// Passar liberar head
// Salvar segundo termo como head

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