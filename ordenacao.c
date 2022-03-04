#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ordenacao.h"

void bubble_sort (int vetor[], int n){
    int i, j, aux;
    for(i = 0; i<n; i++){
        for(j = 0; j<n; j++){
            if(vetor[j]>vetor[j+1]){
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }
    }
}

void insert_sort(int vetor[], int n){
    int i, j, valor;
    for(i = 1; i < n; i++){
        valor = vetor[i];
        for(j = i - 1; j >= 0 && vetor[j] > valor; j--){
            vetor[j+1] = vetor[j];
        }
        vetor[j+1] = valor;
    }
}

void selection_sort(int vetor[], int n){
    int i, j, menor, troca;
    for(i = 0; i < n-1; i++){
        menor = i;
        for(j = i+1; j < n; j++){
            if(vetor[j] < vetor[menor]){
                menor = j;
            }
        }
        if(i != menor){
            troca = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = troca;
        }
    }
}

void shell_sort(int vetor[], int n){
    int i = (n - 1) / 2;
    int chave, k, aux;

    while (i != 0){
        do{
            chave = 1;
            for (k = 0; k < n - i; ++k){
                if (vetor[k] > vetor[k + i]){
                    aux = vetor[k];
                    vetor[k] = vetor[k + i];
                    vetor[k + i] = aux;
                    chave = 0;
                }
            }
        }    
        while (chave == 0);
        i = i / 2;
    }
}

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
    if(ini < fim){
        meio = floor((ini+fim)/2);
        merge_sort(vetor, ini, meio);
        merge_sort(vetor, meio+1, fim);
        merge(vetor, ini, meio, fim);
    }
}

int quick(int *vetor, int ini, int fim){
    int esq, dir, pivo, aux;
    esq = ini;
    dir = fim;
    pivo = vetor[ini];
    while(esq < dir){
        while(vetor[esq] <= pivo)
            esq++;
        while(vetor[dir] > pivo)
            dir--;
        if(esq < dir){
            aux = vetor[esq];
            vetor[esq] = vetor[dir];
            vetor[dir] = aux;
        }        
    }
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

void heap(int *vet, int raiz, int fundo){
	int pronto, filhoMax, tmp;

	pronto = 0;
	while((raiz*2 <= fundo) && (!pronto)){
		if(raiz*2 == fundo){
			filhoMax = raiz * 2;
		}else if(vet[raiz * 2] > vet[raiz * 2 + 1]){
			filhoMax = raiz * 2;
		}else{
			filhoMax = raiz * 2 + 1;
		}

	if(vet[raiz] < vet[filhoMax]){
		tmp = vet[raiz];
		vet[raiz] = vet[filhoMax];
		vet[filhoMax] = tmp;
		raiz = filhoMax;
    }else{
      pronto = 1;
	}
  }
}

void heap_sort(int *vet, int n){
	int i, tmp;

	for (i = (n / 2); i >= 0; i--){
		heap(vet, i, n - 1);
	}

	for (i = n-1; i >= 1; i--){
		tmp = vet[0];
		vet[0] = vet[i];
		vet[i] = tmp;
		heap(vet, 0, i-1);
	}
}