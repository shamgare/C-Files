#include <stdio.h>

int func(int a)
{
    if (a % 2 == 1) return 1;
    if (a == 0) return 0;

    return func(a - 1) + func(a - 2);
}

int main()
{
    int num; scanf("%d", &num); printf("%d\n", func(num));
}