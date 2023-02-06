#include <stdio.h>

int recurr(int m, int n)
{
    if (m == 0 || n == 0) return 1;

    return recurr(m - 1, n- 1) + recurr(m - 1, n) + recurr(m, n - 1);
}

int main()
{
    int num1, num2; scanf("%d %d", &num1, &num2);

    printf("%d\n", recurr(num1, num2));
}