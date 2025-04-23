#include <stdio.h>

typedef struct Info_Pilotos{
    char Nome[31];
    int tempo_mm;
} Info_Pilotos;

void Leitura(Info_Pilotos* v, size_t n){
    for (int i = 0; i < n; i++)
    {
        int tempo_s, tempo_mm;
        scanf("%s", v[i].Nome);
        v[i].tempo_mm = 0;
        for (int j = 0; j < 3; j++)
        {
            scanf("%d.%d", &tempo_s, &tempo_mm);
            v[i].tempo_mm = (tempo_mm) + (tempo_s*1000) + v[i].tempo_mm;
        }
    }
}

void Bubblesort(Info_Pilotos* v, size_t n){
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (v[i].tempo_mm > v[j].tempo_mm)
            {
                Info_Pilotos swap = v[i];
                v[i] = v[j];
                v[j] = swap;
            }
        }
    }
}

void print(Info_Pilotos* v, size_t n){
    for (int i = 0; i < n; i++)
    {
        int minutos = (v[i].tempo_mm/1000)/60;
        int segundos = ((v[i].tempo_mm/1000)-60);
        printf("%d. %s - %d:%.2d.%d\n", i+1, v[i].Nome, minutos, segundos, v[i].tempo_mm%1000);
    }
    
}

void main(){
    int n;
    scanf("%d", &n);

    Info_Pilotos v[n];

    Leitura(v, n);
    Bubblesort(v, n);
    print(v, n);
        
    return;
}