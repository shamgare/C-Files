#include <stdio.h>

int main()
{
    int kasus;
    scanf("%d", &kasus);

    int l, t;
    for (int i = 0; i < kasus; i++) {
        scanf("%d %d", &t, &l);
        printf("Case #%d:\n", i+1);
        for (int j = 0; j < t; j++) {
            for (int k = 0; k < l; k++) {
                if (j == 0 || k == 0 || j == t-1 || k == l-1) printf("#");
                // else if (j == t/2 || k == l/2) printf("#");
                else printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}