#include <stdio.h>

float calcula_area(float x, float y){
	float area;
	area = x * y;
	printf("Sua área é de: %.3f\n", area); 
	return area;
}

int main(){
	float base, altura;
	
	scanf("%f %f", &base, &altura);
	calcula_area(base, altura);
	return 1;
}
	
	
