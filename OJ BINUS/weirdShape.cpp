#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int size;
        scanf("%d", &size);
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                if (j + k + 1 == size || j == k || j == 0 || k == 0 || j == size-1 || k == size-1) printf("*");
                else printf(" ");
            }
            printf("\n");
        }
    }
}