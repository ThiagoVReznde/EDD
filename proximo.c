/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
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

int bsort(int* v, int size, int target){
    int l = 0, r = size;

    while (l < r)
    {
        int mid = l + (r - l) / 2;

        if (v[mid] == target)
        {
            return mid;
        } else if (v[mid] < target)
        {
            l = mid + 1;
        } else r = mid;
    }
}

int lower_bound(int* v, int size, int target) {
    int l = 0, r = size;

    while (l < r) {
        int mid = l + (r - l) / 2;
        if (v[mid] < target) {
            l = mid + 1;
        }else {
            r = mid;
        }
    }

    return l;
}

int upper_bound(int* v, int size, int target) {
    int l = 0, r = size;

    while (l < r) {
        int mid = l + (r - l) / 2;

        if (v[mid] <= target)
        {
            l = mid + 1;
        } else {
            r = mid;
        }
    }

    return l;
}

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    
    int arr[n];
    
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    
    merge_sort(arr, n);
    
    for (int i = 0; i < q; i++){
        int pergunta;
        scanf("%d", &pergunta);
        // eh da sequencia...
        // att: se eh da sequencia, n precisa confirmar se eh da sequencia
        // **restricao do problema
        
        int l = lower_bound(arr, n, pergunta);
        
        if(l == n){
            printf("-1\n");
            
        } else if(l > 0){
            int r = upper_bound(arr, n, pergunta);
            l--;
            
            if (arr[l]-pergunta <= arr[r]-pergunta && arr[l] != pergunta){
                printf("%d\n", arr[l]);
                
            } else printf("%d\n", arr[r]);
        
        } else {
            int r = upper_bound(arr, n, pergunta);
            
            printf("%d\n", arr[r]);
        }
    }

    return 0;
}
