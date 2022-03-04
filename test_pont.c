#include <stdio.h>

int main(){
	int x, *xptr;
	x = 16;
	xptr = &x;

	printf("Endereço: %p\nValor: %i\nEndereço&: %p\n", xptr, *xptr, &x);
	
	

	return 1;
}
