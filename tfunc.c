#include <stdio.h>
int sub(int a, int b){
	int s;
	s = a - b;
	if(s < 0){
		printf("Resultado: %i\nValor negativo.\n", s);
		return s;
	}else{
		printf("Resultado: %i\nValor positivo.\n", s);
		return s;
	}
}
int main(){
	int x, y;
	scanf("%i %i", &x, &y);
	sub(x,y);
	return 1;
}
