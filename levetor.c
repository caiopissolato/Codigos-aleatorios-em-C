#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int n;
	printf("Insira a quantidade de dados do vetor: ");
	scanf("%i", &n);
	int vet[n];

	srand(time(NULL));
	
	for(int i = 0; i<n; i++){
		//printf("Posição [%i] do vetor: ", i);
		vet[i] = rand()%100;
	}

	void imprimeVetor(int num, int *vetor){
		printf("Elementos dentro do vetor: \n");
		for(int i = 0; i<n; i++){
			printf("[%i] ", vetor[i]);
		}
	}

	int l, c;
	printf("Insira a quantidade de linhas: ");
	scanf("%i", &l);
	printf("Insira a quantidade de colunas: ");
	scanf("%i", &c);
	int mat[l][c];
	
	for(int i = 0; i<l; i++){
		for(int j = 0; j<c; j++){
			//printf("Posição [%i][%i] da matriz: ", i, j);
			mat[i][j] = rand()%1000;
		}		
	}

	void imprimeMatriz(int linha, int coluna, int matriz[linha][coluna]){
		printf("Elementos dentro da matriz: \n");		
		for(int i = 0; i<linha; i++){
			for(int j = 0; j<coluna; j++){
				printf("[\t%i\t]", matriz[i][j]);
				if((j + 1) == coluna){
					printf("\n");		
				}
			}
		}
	}

	imprimeVetor(n, vet);
	printf("\n");
	imprimeMatriz(l, c, mat);
	printf("\n");
	
	return 1;
}	
