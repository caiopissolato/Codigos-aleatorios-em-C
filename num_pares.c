#include <stdio.h>

int main(){
    int c = 0, n = 0;
    for(int i = 1;i < 6; i++){
        scanf("%i", &n);
            if(n%2==0){
                c = c + 1;
            }
        }
    printf("%i numeros pares.\n", c);    
    return 1;
}