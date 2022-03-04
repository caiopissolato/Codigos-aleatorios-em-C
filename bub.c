#include <stdio.h>

void imprimeVetor(int num, int *vetor){
	//printf("Elementos dentro do vetor: \n");
	for(int i = 0; i<num; i++){
		printf("[%i] ", vetor[i]);
	}
}

void bubble_sort (int vetor[], int n) {
    int i, j, aux;
    long long int flag = 0;
    for(i = 0; i<n; i++){
        for(j = 0; j<n; j++){
            if(vetor[j]>vetor[j+1]){
                flag++;
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
            imprimeVetor(n, vetor);
            printf("\n");
        }
    }
//   printf("Trocas: %lli\n", flag);
}

void shell_sort(int vetor[], int n){
    int i = (n - 1) / 2;
    int chave, k, aux;
    long long int flag = 0;

    while (i != 0){
        do{
            chave = 1;
            for (k = 0; k < n - i; ++k){
                if (vetor[k] > vetor[k + i]){
                    flag++;
                    aux = vetor[k];
                    vetor[k] = vetor[k + i];
                    vetor[k + i] = aux;
                    chave = 0;
                }
            imprimeVetor(n, vetor);
            printf("\n");    
            }
        }    
        while (chave == 0);
        i = i / 2;
    }
}

void insert_sort(int vetor[], int n){
    int i, j, valor;
    long long int flag = 0;
    for(i = 1; i < n; i++){
        valor = vetor[i];
        for(j = i - 1; j >= 0 && vetor[j] > valor; j--){
            flag++;
            vetor[j+1] = vetor[j];
        }
        vetor[j+1] = valor;
        imprimeVetor(n, vetor);
        printf("\n");  
    }
   // printf("Trocas: %lli\n", flag);
}

int main(){
    int vet[7] = {2, 3, 1, 5, 7, 4, 6};
    int vet1[7] = {7, 4, 1, 5, 2, 3, 6};

    bubble_sort(vet, 7);
    bubble_sort(vet1, 7);

    printf("SHELL\n");

    int vets[7] = {2, 3, 1, 5, 7, 4, 6};
    int vet1sh[7] = {7, 4, 1, 5, 2, 3, 6};

    shell_sort(vets, 7);
    shell_sort(vet1sh, 7);

    int vetis[7] = {2, 3, 1, 5, 7, 4, 6};
    int vet1ins[7] = {7, 4, 1, 5, 2, 3, 6};
    int vetyou[7] = {23, 4, 67, -8, 90, 54, 21};

    printf("INSERT\n");

    insert_sort(vetis, 7);
    insert_sort(vet1ins, 7);
    insert_sort(vetyou, 7);

    return 1;
}