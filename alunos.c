#include <stdio.h>

// Sem time limit = Talvez de certo!

int check(int* v, int n_artigos, int k_alunos, int mid){
    int contador = 1;
    int soma = 0;

    for (int i = 0; i < n_artigos; i++)
    {
        soma += v[i];
        if (soma > mid)
        {
            contador++;
            soma = v[i];
        }
    }

    if (contador > k_alunos)
    {
        return 0;

    } else return 1;
}

int achar_maior_possivel(int* v, int n_artigos, int k_alunos, int maior, int soma){
    if (n_artigos == k_alunos)
    {
        return maior;
    } else if (n_artigos < k_alunos)
    {
        return -1;
    }

    int l = maior;
    int r = soma;
    int resposta;
    
    // mudança: adicionei o =
    // diferente das taubas, faz sentido ter o =
    while (l <= r)
    {
        int mid = r - (r - l) / 2;

        if (check(v, n_artigos, k_alunos, mid))
        {
            resposta = mid;
            r = mid-1;

        } else l = mid+1;
    }

    return resposta;
}

int main(){
    int n_artigos, k_alunos;
    scanf("%d %d", &n_artigos, &k_alunos);

    int maior = 0;
    int soma = 0;
    int arr[n_artigos];
    for (int i = 0; i < n_artigos; i++)
    {
        scanf("%d", &arr[i]);
        soma += arr[i];

        if (maior < arr[i])
        {
            maior = arr[i];
        }
    }
    
    int resposta = achar_maior_possivel(arr, n_artigos, k_alunos, maior, soma);
    printf("%d\n", resposta);

    return 0;
}
