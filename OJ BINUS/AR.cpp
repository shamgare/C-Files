#include <stdio.h>

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {

                if (j + k + 1 < n) printf(" ");
                else printf("*");

            }
            printf("\n");
        }
    }
    return 0;
}

// jk jk jk jk
// 00 01 02   03
// 10 11   12 13
// 20   21 22 23
//   30 31 32 33