#include <stdio.h>

int main(){
    float media, total, v;
    v = 0.2+0.2+0.2+0.2+0.2+0.2+0.2+0.8+0.8;
    media = ((0.2 * 10)+(0.2 * 6.6)+(0.2 * 10)+(0.2 * 9)+(0.2 * 0)+(0.2 * 0)+(0.2 * 0)+(0.8 * 3.5)+(0.8 * 7.3));
    total = media/v;
    printf("Media final: %.2f\n", total);
   
    return 1;
}