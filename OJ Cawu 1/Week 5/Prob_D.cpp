#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int jersey[n][n], count = 0;
    int frek[110] = {};
    int a;

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            scanf("%d", &a);
            frek[a]++;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (frek[i] < n) count++;
    }
    
    printf("%d\n", count);
    return 0;
}