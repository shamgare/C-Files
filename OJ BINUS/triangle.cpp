#include <stdio.h>

int main()
{
    int kasus;
    scanf("%d", &kasus);

    for (int i = 0; i < kasus; i++) {
        int size;
        scanf("%d", &size);
        printf("Case #%d:\n", i+1);
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                if (j + k + 1 < size) printf(" ");
                else if ((j + k + 1) % 2 == 1) printf("*");
                else printf("#");
            }
            printf("\n");
        }
    }
    return 0;
}