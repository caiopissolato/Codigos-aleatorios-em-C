#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void embaralhar(int *vet, int n){
    
	for (int i = 0; i < n; i++){
		int r = rand() % n;
        
		int temp = vet[i];
		vet[i] = vet[r];
		vet[r] = temp;
	}
}
void embaralha_vetor(int *vet, int n){
    int aux[1000000], i;
    for(i = 0; i<1000000; i++){
        aux[i] = i;
    }
    embaralhar(aux, 1000000);
    for(i = 0; i<n; i++){
        vet[i] = aux[i];
    }
}
int main(){
    srand(time(NULL));
    int vet[10];
    int vet1[10];
    
    for(int i = 0; i<10; i++){
        vet[i] = i;
    }

    for(int i = 0; i<10; i++){
        vet1[i] = i;
    }

    
    

    embaralhar(vet1, 10);
    for(int i = 0; i<10; i++){
        printf("%i\n", vet1[i]);
    }

    embaralha_vetor(vet, 10);
    for(int i = 0; i<10; i++){
        printf("%i\n", vet[i]);
    }
    printf("\n");
    embaralha_vetor(vet, 10);
    for(int i = 0; i<10; i++){
        printf("%i\n", vet[i]);
    }






    return 1;
}