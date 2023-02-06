#include <stdio.h>

int func(int n, int x, int y)
{
    if (n == 0) return x;
    if (n == 1) return y;
    
    return func(n - 1, x, y) - func(n - 2, x, y);
}

int main()
{
    int kasus; scanf("%d", &kasus);

    for (int i = 0; i < kasus; i++) {
        int n, x, y;
        scanf("%d %d %d", &n, &x, &y);
        printf("%d\n", func(n, x, y));
    }
}