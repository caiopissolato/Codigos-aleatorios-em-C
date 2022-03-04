#include <stdio.h>

int main(){
    int i;
    int x = 0;
    double a = 0;
    double cont;
    for(i = 1; i < 7; i++){
        scanf("%lf", &cont);
        if(cont >= 0){
            x++;
            a = a + cont;
        }
    }
    double m = a/x;
    printf("%d valores positivos\n", x);
    printf("%.1lf\n", m);
    return 1;
}