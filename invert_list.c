#include "grader.h"

// Nota:
// Eu estava copiando os ponteiros e, portanto,
// removendo os elementos da lista
// Essa aboradagem nn funciona
// ++ essa abordagem eh 100000x mais simples
void list_reverse(list_t* l){
    if(list_size(l) <= 1){
        return;
    }

    size_t Tamanho_Lista = list_size(l); //evitar fazer diversas chamadas
    int arr[Tamanho_Lista];
    list_node_t* aux = l->head;

    // itera os elementos da lista
    // & salva na array
    for (int i = 0; i < Tamanho_Lista; i++){
        arr[i] = aux->data;
        aux = aux->next;
    }
    aux = l->head;

    // salva na lista
    // size_t por algum motivo "burla" a condicao de parada
    // como fazer entao? procurar depois
    for (int i = Tamanho_Lista-1; i >= 0; i--)
    {
        aux->data = arr[i];
        aux = aux->next;
    }
}
