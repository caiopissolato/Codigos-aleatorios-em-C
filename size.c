#include <stdio.h>
#include <stdlib.h>
int main(){

    long c = 10;
    int i = 0, x;
    long num;
    printf("Num: ");
    scanf("%li", &num);
    /*for(i = 0; c > 0; ++i){
        c = num%10;
        num = num/10;
        x = num;
        if(x == 0)
        //printf("%i\n",i);
    }*/

    long atol (const char *num); 
    printf("Aqui: %li", num);
    return 0;
}