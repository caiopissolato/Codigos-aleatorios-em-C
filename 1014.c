#include <stdio.h>

int main(){
    int X;
    float Y;

    scanf("%i", &X);
    scanf("%f", &Y);

    float MEDIA = X/Y;
    printf("%.3f km/l\n", MEDIA);
    return 0;
}