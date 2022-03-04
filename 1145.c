#include <stdio.h>

int main(){
    int X, Y, i;
    scanf("%i %i", &X, &Y);
    int c = X;
    for(i = 1; i <= Y; i++){
        printf("%i ", i);
            if(i == X){
                printf("\n");
                X = X + c;
            }
        }
    return 1;
}