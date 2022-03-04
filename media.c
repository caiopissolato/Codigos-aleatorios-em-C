#include <stdio.h>

int main(){
    int m, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, c;
    printf("1: ");
    scanf("%i", &_0);
    printf("\n");
    printf("2: ");
    scanf("%i", &_1);
    printf("\n");
    printf("3: ");
    scanf("%i", &_2);
    printf("\n");
    printf("4: ");
    scanf("%i", &_3);
    printf("\n");
    printf("5: ");
    scanf("%i", &_4);
    printf("\n");
    printf("6: ");
    scanf("%i", &_5);
    printf("\n");
    printf("7: ");
    scanf("%i", &_6);
    printf("\n");
    printf("8: ");
    scanf("%i", &_7);
    printf("\n");
    printf("9: ");
    scanf("%i", &_8);
    printf("\n");
    printf("10: ");
    scanf("%i", &_9);
    printf("\n");
    m = _0 + _1 + _2 + _3 + _4 + _5 + _6 + _7 + _8 + _9/10;
    if(_0 >= m){
        c = c + 1;
    }if(_1 >= m){
         c = c + 1;
    }if(_2 >= m){
         c = c + 1;
    }if(_3 >= m){
         c = c + 1;
    }if(_4 >= m){
        c = c + 1;
    }if(_5 >= m){
        c = c + 1;
    }if(_6 >= m){
        c = c + 1;
    }if(_7 >= m){
        c = c + 1;
    }if(_8 >= m){
        c = c + 1;
    }if(_9 >= m){
        c = c + 1;
    }
    printf("Media: %.2f\n", (float)m);
    printf("Acima da media: %i\n", c);
    printf("Abaixo da media: %i\n", 10-c);
    return 1;
}