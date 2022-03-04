#include <stdio.h>
int main()
{
    int idade,aux=0;
    double media, i=0;
    while(1)
    {
        scanf("%d", &idade);
        if(idade<0)
            break;
        else
        {
            aux+=idade;
            i++;
        }
    }
    media=aux/i;
    printf("%.2lf\n",media);
    return 1;
}