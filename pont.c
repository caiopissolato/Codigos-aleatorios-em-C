#include <stdio.h>
#include <stdlib.h>

int main(){
    int n = 16;
    int *p = &n;
    int **v;
    printf("%d\n", *p);
    printf("%d\n", **v);

    return 1;
}