#include <stdio.h>
#include <stdlib.h>

typedef struct list_node_t
{
    char name[31];
    int id;
    int time;
    int time_taken;
    struct list_node_t* next;
} list_node_t;


typedef struct list_t{
    list_node_t* head;
    list_node_t* tail;
    size_t size;
} list_t;

size_t list_size(list_t* l){ return l->size; }

void list_init(list_t* l){
    l->head = NULL;
    l->tail = NULL;
    l->size = 0;
}

void list_append(list_t* l, list_node_t data){
    list_node_t* new_node = malloc(sizeof(list_node_t));

    (*new_node) = data;
    
    if (list_size(l) == 0)
    {
        l->head = new_node;
    } else{
        l->tail->next = new_node;
    }

    l->tail = new_node;
    l->tail->next = l->head;
    l->size++;
}

void list_pop(list_t* l, int i){
    list_node_t* aux = l->head;

    if (list_size(l) == 1)
    {
        l->head = NULL;
        l->tail = NULL;
        free(aux);
    } else if (i == list_size(l)-1)
    {
        list_node_t* node = l->tail;

        while (aux->next != l->tail)
            aux = aux->next;

        aux->next = l->head;
        l->tail = aux;
        
        free(node);
    } else
    {
        list_node_t* node;

        for (size_t k = 0; k < i-1; k++)
            aux = aux->next;

        node = aux->next;
        aux->next = node->next;

        free(node);
    }
    
    l->size--;
}

int main(){
    int n, q;
    scanf("%d %d", &n, &q);

    list_t* l = malloc(sizeof(list_t));;
    list_init(l);

    for (size_t i = 0; i < n; i++)
    {
        list_node_t data;
        scanf("%s", data.name);
        scanf("%d", &data.id);
        scanf("%d", &data.time);
        data.time_taken = 0;
        data.next = NULL;

        list_append(l, data);
    }
    list_node_t* aux = l->head;
    printf("---------\n");
    for (size_t i = 0; i < n; i++)
    {
        printf("%s ", aux->name);
        printf("%d ", aux->id);
        printf("%d ", aux->time);

        list_node_t* node_removed;
        node_removed = aux;
        aux = aux->next;
        list_pop(l, node_removed);
    }
    printf("a\n");
    
}
