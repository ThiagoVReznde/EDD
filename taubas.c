/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
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

int not_so_binary_search(int* v, size_t size, int target, int m_linhas){
    int n_taubas = 0;
    int m_linhas_preenchidas = 0;
    
    int l = 0, r = size;

    // achar lower_bound
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (v[mid] < target) {
            l = mid + 1;
        }else {
            r = mid;
        }
    }
    int lower = l;
    
    // se tiver lower bound, procurar high bound
    // se tiver taubas do tamanho k ent nn precisa de duas
    if(lower < size){
        l = 0;
        r = size;

        while (l < r) {
            int mid = l + (r - l) / 2;
    
            if (v[mid] <= target)
            {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        
        n_taubas = l - lower;
        m_linhas_preenchidas = n_taubas;
    }
    
    
    if (m_linhas_preenchidas - m_linhas >= 0){
        return m_linhas;
    }
    
    l = 0;
    r = size-1;
    
    // calc somas
    // mudanca: tirei o =
    // mudanca>: leve alteracao na logica
    while (l < r && m_linhas_preenchidas < m_linhas)
    {
        int soma = v[l]+v[r];
        
        if (v[l] == target){
            l++;
            
        } else if (v[r] == target){
            r--;
            
        } else if (soma == target){
            
            m_linhas_preenchidas++;
            n_taubas += 2;
            r--;
            l++;
    
        } else if (soma > target){
            r--;
            
        } else l++;
    }


    if (m_linhas_preenchidas == m_linhas){
            return n_taubas;
    } else return -1;
}


int main(){
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    int arr[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
        
    
    merge_sort(arr, n);
    
    int a = not_so_binary_search(arr, n, k, m);

    printf("%d\n", a);

    return 0;
}
