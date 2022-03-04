#include <stdio.h>
#include <stdlib.h>
int main()
{
    float v,x;
    scanf("%f", &v);
    if(v <= 2000.0) {
        printf("Isento\n");
    }
    else if(v <= 3000.0 ){
        x = (v - 2000.0)*0.08;
        printf("R$ %.2f\n", x);
    }
    else if( v <= 4500.0){
        x = (v - 3000.0)*0.18 + (1000*0.08);
        printf("R$ %.2f\n", x);
    }
    else {
        x = (v - 4500)*0.28 + (1500*0.18) + (1000*0.08);
        printf("R$ %.2f\n", x);
    }
    return 1;
}