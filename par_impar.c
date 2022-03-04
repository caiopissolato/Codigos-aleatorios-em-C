#include <stdio.h>

int main(){
    void par_ou_impar(int i){
        if(i % 2 == 0){
            printf("PAR!\n");
        }else{
            printf("IMPAR!\n");
        }
    }
    par_ou_impar(16);
    par_ou_impar(24);
    par_ou_impar(1);
    par_ou_impar(0);
    par_ou_impar(7);
    return 1;
}