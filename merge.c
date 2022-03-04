#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void merge(int *vetor, int ini, int meio, int fim){
    int *temp, p1, p2, n, i, j, k;
    int fim1 = 0, fim2 = 0;
    n = fim-ini+1;
    p1 = ini;
    p2 = meio+1;
    temp = (int *) malloc(n*sizeof(int));
    if(temp != NULL){
        for(i=0; i<n; i++){
            if(!fim1 && !fim2){
                if(vetor[p1] < vetor[p2]){
                    temp[i] = vetor[p1++];
                }else{
                    temp[i] = vetor[p2++];
                }
                if(p1>meio) fim1=1;
                if(p2>fim) fim2=1;
            }else{
                if(!fim1){
                    temp[i]=vetor[p1++];
                }else{
                    temp[i]=vetor[p2++];
                }
            }
        }
        for(j = 0, k = ini; j<n; j++, k++){
            vetor[k]=temp[j];
        }
    }
    free(temp);
}

void merge_sort(int *vetor, int ini, int fim){
    int meio;
    long long int flag = 0;
    if(ini < fim){
        flag++;
        meio = floor((ini+fim)/2);
        merge_sort(vetor, ini, meio);
        merge_sort(vetor, meio+1, fim);
        merge(vetor, ini, meio, fim);
    }
    printf("Trocas: %lli\n", flag);
}

int quick(int *vetor, int ini, int fim){
    int esq, dir, pivo, aux;
    long long int flag;
    esq = ini;
    dir = fim;
    pivo = vetor[ini];
    while(esq < dir){
        while(vetor[esq] <= pivo)
            esq++;
        while(vetor[dir] > pivo)
            dir--;
        if(esq < dir){
            flag++;
            aux = vetor[esq];
            vetor[esq] = vetor[dir];
            vetor[dir] = aux;
        }        
    }
    printf("Trocas: %lli\n", flag);
    vetor[ini] = vetor[dir];
    vetor[dir] = pivo;
    return dir;
}

void quick_sort(int *vetor, int ini, int fim){
    int pivo;
    if(fim > ini){
        pivo = quick(vetor, ini, fim);
        quick_sort(vetor, ini, pivo-1);
        quick_sort(vetor, pivo+1, fim);
    }
}

void le_arquivo1000(char *end, int *vet){
    FILE *file = fopen(end, "r");
    int i = 0, retorno_scanf;
    if(file == NULL){
        printf("ERRO ao abrir arquivo.\n");
        exit(1);
    }else{
        for(i = 0; i<1000; i++){
            if(retorno_scanf != EOF){
                retorno_scanf = fscanf(file, "%i", &vet[i]);
            }
        }
    }   
    fclose(file);     
}

int main(){
    int vet[16] = {15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int vet1[16] = {59, 73, 13, 12, 111, 110, 96, 81, 37, 61, 54, 24, 63, 27, 11, 1000};

    merge_sort(vet, 0, 16);
    quick_sort(vet1, 0, 16);

    for(int i = 0; i<16; i++){
        printf("%i\n", vet[i]); 
    }
    printf("\n");

    for(int i = 0; i<16; i++){
        printf("%i\n", vet1[i]);
    }

    return 1;

}