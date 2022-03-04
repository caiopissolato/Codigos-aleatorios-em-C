#include <stdio.h>
#define TAMANHO 10

int main(){
	float numeros[10] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};
	float *nPtr;
	nPtr = &numeros;
	
	printf("%p\n\n", nPtr);
	nPtr = numeros;
	printf("%p\n\n", nPtr);
	
	for(int i = 0; i<10; i++){
		printf("%.1f ", numeros[i]);
	}
	
	printf("\n");
	return 1;
}
