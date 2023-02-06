#include <stdio.h>

int main()
{
    int a[110][110];
    int n;
    scanf("%d", &n);

    for (int i = 0; i< n; i++) 
    {
        for (int j = 0; j< n; j++) 
        {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 1; i < n-1; i++) {
        for (int j = 1; j < n-1; j++) {
            printf("%d", a[i][j]);
            if (j != n-2) printf(" ");
        }
        printf("\n");
    }
    return 0;
}