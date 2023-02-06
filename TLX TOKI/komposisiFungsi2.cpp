#include <stdio.h>
#include <stdlib.h>

int a, b, k, x;

int komp(int x, int k)
{
    if (k == 0) return x;
    return abs(a * komp(x, k-1) + b);
}

int main()
{
    scanf("%d %d %d %d", &a, &b, &k, &x);
    printf("%d\n", komp(x, k));
}

/*
1 * 1 + 1 = 2
2 2 2 2
*/