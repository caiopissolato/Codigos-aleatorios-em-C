#include <stdio.h>

int main(){
	int x, *ptr_x;
	x = 16;	
	ptr_x = &x;
	
	printf("Endereço: %p\nValor: %i\n", ptr_x, *ptr_x);
	
	return 1;
}
