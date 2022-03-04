#include <stdio.h>
#define max 10

void heap(int *vet, int raiz, int fundo);

void heap_sort(int *vet, int n) {
	int i, tmp;

	for (i = (n / 2); i >= 0; i--) {
		heap(vet, i, n - 1);
	}

	for (i = n-1; i >= 1; i--) {
		tmp = vet[0];
		vet[0] = vet[i];
		vet[i] = tmp;
		heap(vet, 0, i-1);
	}
}

void heap(int *vet, int raiz, int fundo) {
	int pronto, filhoMax, tmp;

	pronto = 0;
	while ((raiz*2 <= fundo) && (!pronto)) {
		if (raiz*2 == fundo) {
			filhoMax = raiz * 2;
		}
		else if (vet[raiz * 2] > vet[raiz * 2 + 1]) {
			filhoMax = raiz * 2;
		}
		else {
			filhoMax = raiz * 2 + 1;
		}

	if (vet[raiz] < vet[filhoMax]) {
		tmp = vet[raiz];
		vet[raiz] = vet[filhoMax];
		vet[filhoMax] = tmp;
		raiz = filhoMax;
    }
	else {
      pronto = 1;
	}
  }
}

int main() {
	int vetor[max] = {5,2,7,8,10,6,9,3,24,16};
	int i;
	heap_sort(vetor,max);
	for (i = 0; i < max; i++) {
		printf("%d ", vetor[i]);
	}
    printf("\n");
	return 1;
}