#include <stdio.h>

void quicksort_();
void quicksort_helper();
int particionar();
void desempate();


void swap(int *v, int esq, int dir){
    int aux = v[esq];
    v[esq] = v[dir];
    v[dir] = aux;
}

void quicksort_(int* v, int* vm, size_t size){
    quicksort_helper(v, vm, 0, size-1);
    return;
}

void quicksort_helper(int* v, int* vm, int esq, int dir){
    if (esq < dir)
    {
        size_t pos = particionar(v, vm, esq, dir, dir);
        quicksort_helper(v, vm, esq, pos-1);
        quicksort_helper(v, vm, pos+1, dir);
    }
    return;
}

int particionar(int* v, int* vm, int esq, int dir, int piv){
    swap(v, piv, dir);
    swap(vm, piv, dir);
    int pos = esq;

    for (int i = esq; i < dir; i++)
    {
        if (vm[i] > vm[dir])
        {
            swap(v, i, dir);
            swap(vm, i, dir);
            pos++;
        } else if (vm[i] == vm[dir]){
            desempate(v, vm, &pos, i, dir);
        }
    }

    swap(v, dir, pos);
    swap(vm, dir, pos);

    return pos;
}

void desempate(int* v, int* vm, int* pos, int i, int dir){
    int pari = vm[i]%2;
    int pardir = vm[dir]%2;

    if (pari == pardir)
    {
        if (pari == 0)
        {
            // Ambos pares
            if (v[i] < v[dir])
            {
                swap(v, i, dir);
                swap(vm, i, dir);
            }
        } else {
            // Ambos impares
            if (v[i] > v[dir])
            {
                swap(v, i, dir);
                swap(vm, i, dir);
            }
        }
    // Paridade diferente
    } else {
        if (pardir != 0)
        {
            swap(v, i, dir);
            swap(vm, i, dir);
        }
    }

    (*pos)+=1;
    return;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    int v[n];
    int vm[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
        vm[i] = v[i]%m;

        printf("vm - %d\n", v[i]%m);
    }

    quicksort_(v, vm, n);

    for (int i = 0; i < n; i++)
    {
        printf("[%d][%d]\n", v[i], vm[i]);
    }

    return 0;
}
