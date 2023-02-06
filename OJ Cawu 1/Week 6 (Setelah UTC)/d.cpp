#include <stdio.h>

int main()
{
    long long int angka, a, b;
    scanf("%lld", &angka);
    a = angka / 2;
    b = a + 1;
    printf("%lld = %lld + %lld\n", angka, a, b);
    return 0;
}