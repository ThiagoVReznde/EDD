#include <stdio.h>
#include <stdlib.h>

int ilumina(int* v_casas, int* v_postes, int n_casas, int n_postes, int raio){
    int i = 0, k = 0;
    
    while(i < n_postes && k < n_casas){
        int soma = v_postes[i] + raio;
        int sub = v_postes[i] - raio;

        if (soma < v_casas[k])
        {
            i++;
        } else if (sub > v_casas[k])
        {
            return 0;
        } else k++;
    }
    
    if (k == n_casas)
    {
        return 1;
    } else return 0;
    
}

int bsort(int* v_casas, int* v_postes, int n_casas, int n_postes){
    int resposta;
    int r = 1000000000;
    int l = 0;

    while(l <= r){
        int raio = l + (r-l)/2;

        if (ilumina(v_casas, v_postes, n_casas, n_postes, raio))
        {
            resposta = raio;
            r = raio - 1;
        } else {
            l = raio + 1;
        }
    }

    
    return resposta;
}

int main(){
    int n_casas, n_postes;
    scanf("%d", &n_casas);
    int arr_casas[n_casas];

    for (int i = 0; i < n_casas; i++)
    {
        scanf("%d", &arr_casas[i]);
    }
    
    scanf("%d", &n_postes);
    int arr_postes[n_postes];

    for (int i = 0; i < n_postes; i++)
    {
        scanf("%d", &arr_postes[i]);
    }

    printf("%d\n", bsort(arr_casas, arr_postes, n_casas, n_postes));
    
    return 0;
}
