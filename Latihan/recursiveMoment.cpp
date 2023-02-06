#include <stdio.h>

int fac(unsigned int a), fibo(int a), func(int a);

int main()
{
    unsigned int a;
    scanf("%d", &a);

    fac(a);
    printf("FACTORIAL: %d\n", fac(a));

    fibo(a);
    printf("FIBONACCI: %d\n", fibo(a));

    // func(a);
}

int fac(unsigned int a)
{
    if (a <= 1) return 1;
    return a * fac(a-1);
}

int fibo(int a)
{
    if (a == 0 || a == 1) return a;
    return fibo(a-2) + fibo(a-1);
}