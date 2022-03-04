#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

int main(void)
{

    struct timeval utime;
    double tInicio;
    double tFim;
    int i;

    gettimeofday(&utime, NULL);

    tInicio = utime.tv_sec + ( utime.tv_usec / 1000000.0 );

    /*for ( i = 0; i < 100; i++)
        printf("Mostra algo na tela!!!\n");
*/
    gettimeofday(&utime, NULL);

    tFim = utime.tv_sec + ( utime.tv_usec / 1000000.0 );

    printf("%.4lf - Tempo percorrido\n", tFim - tInicio);

  return 0;

}