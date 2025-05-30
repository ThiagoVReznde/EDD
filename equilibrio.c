#include <stdio.h>

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

int processamento(int* v, size_t size){
    int i = 0;
    int k;

    while (i < size){
        for(k = i+1; k < size; k++){
            if(v[i] == 0 || v[k] == 0)
                return 1;
            
            if(v[i]%v[k] != 0 && v[k]%v[i] != 0)
                return 0;
            
        }
        
        i++;
    }
    
    return 1;
}

int main() {
    int n;
    
    scanf("%d", &n);
    int arr[n];
    
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    
    merge_sort(arr, n);
    
    if (processamento(arr, n)){
        printf("Sim\n");
    } else printf("Nao\n");

    return 0;
}
