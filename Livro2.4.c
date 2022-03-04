#include <stdio.h>

int main(){
	/*Programa para calcular o produto de três numeros inteiros*/
	int x, y, z, resultado;
	printf("Digite 3 números inteiros: \n");
	scanf("%i%i%i", &x, &y, &z);
	resultado = x * y * z;
	printf("O resultado é %i\n", resultado);
	return 1;
}
