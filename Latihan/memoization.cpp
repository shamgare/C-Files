#include <stdio.h>

long long int func(int number)
{
    static long long int memo[100000] = { 0 };
    
    if (number <= 1) return number;

    if (memo[number] != 0) return memo[number];
    
    return memo[number] = func(number - 1) + func(number - 2);
}

int main()
{
    int n; scanf("%d", &n);

    printf("%lld\n", func(n));
}