#include <stdio.h>

int soma(int a, int b){
	int s;
	s = a + b;
	printf("S = %i\n", s);
	return s;
}

int main(){

	int x, y;
	scanf("%i %i", &x, &y);
	soma(x, y);
	
	return 1;
}
		
