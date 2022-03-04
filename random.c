#include <stdio.h>
#include <stdlib.h>
int main(){
    int n, c;
    for(int i = 0; i < 13; i++){
        n = rand()%100;
        c = (char)(rand()%26);
        printf("%i %c ", n, c);
    }
    printf("\n");
    return 1;
}