#include <stdio.h>

int main(){
    int v;
    scanf("%i", &v);
    if(v % 2 == 0){
        printf("PAR.\n");
    }else{
        printf("IMPAR.\n");
    }
    return 1;
}