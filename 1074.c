#include <stdio.h>

int main(){
    int i, n;
    int c = 0;
    scanf("%i", &n);
        for(i = 1; i <= n; i++){
            scanf("%i", &c);
            if(c == 0){
                printf("NULL\n");
            }else if((c%2 == 0)&&(c > 0)){
                printf("EVEN POSITIVE\n");
            }else if((c%2 == 0)&&(c < 0)){
                printf("EVEN NEGATIVE\n");
            }else if((c%1 == 0)&&(c > 0)){
                printf("ODD POSITIVE\n");
            }else if((c%1 == 0)&&(c < 0)){
                printf("ODD NEGATIVE\n");
            }
        }   
    return 1;
}