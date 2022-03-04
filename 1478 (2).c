#include <stdio.h>

int main() {
    int n, l, c;
    scanf("%d", &n);
    while (n != 0) {
        while ((n < 0) || (n > 100)) {
        printf("Ordem da matriz inválida. Reinforme: ");
        scanf("%d", &n);
        }
        for (l=1; l<=n; l++) {
            for (c=l; c>1; c--)
                printf(" %3d", c);
                for (c=1; c<=n-l+1; c++)
                    printf(" %3d", c);
                    printf("\n");
                }
                printf("\n");
                scanf("%d", &n);
    }
return 1;
}