#include <stdio.h>

int main(){
    int i, n;
    int a = 1, b = 2, c = 3;
    scanf("%i", &n);
    for(i = 1;i <= n; i++){
        printf("%i %i %i PUM\n", a, b, c);
        a=a+4;
        b=b+4;
        c=c+4;
    }
    return 1;
}