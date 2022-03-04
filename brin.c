#include <stdio.h>

int main(){
    int num[4][4], c = 1, k = 1;
    for(int i = 0; i <= 3; i++){
        for(int j = 0; j <= 3; j++){
            printf("Valor [%i]: \n", c);
            scanf("%i", &num[i][j]);
            c++;  
        }
    }
    for(int v = 0; v < 4; v++){
        for(int u = 0; u < 4; u++){
            printf("\t[\t%i\t]", num[v][u]);
            if((k == 4) || (k == 8) || (k == 12) || (k == 16)){
                printf("\n");
            }
        k++;
        }
    }
    return 1;
}