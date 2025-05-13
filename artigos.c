#include <stdio.h>

void merge(int* v, int* v1, int* v2, size_t size){
    size_t size_v1 = size/2;
    size_t size_v2 = size - size_v1;
    int i, j, k;

    for (i = 0, j = 0, k = 0; j < size_v1 && k < size_v2; i++)
    {
        if (v1[j] <= v2[k])
        {
            v[i] = v1[j++];
        } else{
            v[i] = v2[k++];
        }
    }

    while (j < size_v1)
        v[i++] = v1[j++];

    while (k < size_v2)
        v[i++] = v2[k++];
}

void merge_sort(int* v, size_t size){
    if (size > 1)
    {
        size_t mid = size / 2;

        int v1[mid];
        int v2[size-mid];

        for (int i = 0; i < mid; i++)
        {
            v1[i] = v[i];
        }
        for (int i = mid; i < size; i++)
        {
            v2[i-mid] = v[i];
        }
     
        merge_sort(v1, mid);
        merge_sort(v2, size-mid);

        merge(v, v1, v2, size);
    }
}

int NomeCriativo(int* v, int n, int m){
    merge_sort(v, m);
    if(n == m){
        return v[n-1];
    }
    
    v[0] = v[0] + v[1];
    for (int i = 1; i < m-1; i++){
        v[i] = v[i+1];
    }
    
    return NomeCriativo(v, n, m-1);
}

int main()
{
    int n_alunos, n_artigos;
    scanf("%d %d", &n_artigos, &n_alunos);
    
    int arr[n_artigos];
    for (int i = 0; i < n_artigos; i++)
        scanf("%d", &arr[i]);
    
    if(n_alunos <= n_artigos){
        int roberto = NomeCriativo(arr, n_alunos, n_artigos);
        printf("%d\n", roberto);
    } else printf("-1\n");
    
    return 0;
}
