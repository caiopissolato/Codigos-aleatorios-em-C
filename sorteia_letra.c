#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    srand(time(NULL));
/*
    typedef struct letra{
        char l;
    }Letra;

    Letra lets[26] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
    int le = rand() % 26;
    printf("%c\n", lets[le].l);
*/

    char letras[26] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    char le = rand() % 26;
    printf("%c\n", letras[le]);

    return 1;
}