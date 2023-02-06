#include <stdio.h>

int sum = 0;

int fib(int n)
{
    if (n <= 2) return 1;

    return fib(n - 2) + fib(n - 1);
}

int main()
{
    int n; scanf("%d", &n);

    printf("%d\n", fib(n));
}