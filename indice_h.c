#include <stdio.h>
#include <string.h>

typedef struct Autor{
    char nome[31];
    int indice;
} Autor;

void merge_indices(Autor* v, Autor* v1, Autor* v2, size_t size){
    size_t size_v1 = size / 2;
    size_t size_v2 = size - size_v1;
    size_t i = 0, j = 0, k = 0;

    while (j < size_v1 && k < size_v2) {
        if (v1[j].indice > v2[k].indice)
            v[i++] = v1[j++];
            
        else if(v1[j].indice == v2[k].indice){
            int ordem = strcmp(v1[j].nome, v2[k].nome);
            
            if (ordem < 0){
                v[i++] = v1[j++];
            } else {
                v[i++] = v2[k++];
            }    
            
        } else {
            v[i++] = v2[k++];
        }
    }

    while (j < size_v1)
        v[i++] = v1[j++];
    while (k < size_v2)
        v[i++] = v2[k++];
}

void merge_sort_indices(Autor* v, size_t size){
    if(size <= 1)
        return;

    size_t mid = size / 2;
    Autor v1[mid];
    Autor v2[size - mid];

    for(size_t i = 0; i < mid; i++)
        v1[i] = v[i];
    for(size_t i = mid; i < size; i++)
        v2[i - mid] = v[i];

    merge_sort_indices(v1, mid);
    merge_sort_indices(v2, size - mid);
    merge_indices(v, v1, v2, size);
}

void merge(int* v, int* v1, int* v2, size_t size){
    size_t size_v1 = size / 2;
    size_t size_v2 = size - size_v1;
    size_t i = 0, j = 0, k = 0;

    while (j < size_v1 && k < size_v2) {
        if (v1[j] <= v2[k])
            v[i++] = v1[j++];
        else
            v[i++] = v2[k++];
    }

    while (j < size_v1)
        v[i++] = v1[j++];
    while (k < size_v2)
        v[i++] = v2[k++];
}

void merge_sort(int* v, size_t size){
    if(size <= 1)
        return;

    size_t mid = size / 2;
    int v1[mid];
    int v2[size - mid];

    for(size_t i = 0; i < mid; i++)
        v1[i] = v[i];
    for(size_t i = mid; i < size; i++)
        v2[i - mid] = v[i];

    merge_sort(v1, mid);
    merge_sort(v2, size - mid);
    merge(v, v1, v2, size);
}

int indice_h(int* v, size_t publicacoes){
    merge_sort(v, publicacoes);

    int i = 0;
    
    for(i = 0; i < publicacoes; i++)
        if (v[i] >= publicacoes-i)
        {
            return publicacoes-i;
        }
}

int main()
{
    int n;
    scanf("%d", &n);
    
    Autor autores[n];
    
    for (int i = 0; i < n; i++){
        int publicacoes;
        scanf("%s %d", autores[i].nome, &publicacoes);
        int arr[publicacoes];
        
        for (int k = 0; k < publicacoes; k++){
            scanf("%d", &arr[k]);
        }
        
        autores[i].indice = indice_h(arr, publicacoes);
    }
    
    merge_sort_indices(autores, n);
    
    for(int i = 0; i < n; i++)
        printf("%s %d\n", autores[i].nome, autores[i].indice);

    return 0;
}
