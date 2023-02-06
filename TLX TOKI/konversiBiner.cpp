#include <stdio.h>

void conv(long long int num)
{
    if (num == 0) return;

    conv(num/2);
    printf("%lld", num % 2);
}

int main()
{
    long long int num;
    scanf("%lld", &num);
    conv(num);
}