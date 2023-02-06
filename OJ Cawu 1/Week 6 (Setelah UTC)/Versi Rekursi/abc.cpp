#include <stdio.h>

int fibonacci(int a, int b, int c)
{
    if (c == 0) {
        return a;
    } else if (c == 1) {
        return b;
    }
    return fibonacci(a, b, c-1) + fibonacci(a, b, c-2);
}

long long int fibonacci2(long long int c, long long int a, long long int b)
{
    if (c == 0) {
        return a;
    } else if (c == 1) {
        return b;
    }
    return fibonacci2(c-1, a, b) - fibonacci2(c-2, a, b);
}

int aToB(int a, int b)
{
    if (a == b) {
        return 1;
    } else if (a == 1) {
        return 0;
    } else if (a % 2 == 0) {
        a = a/2;
    } else if (a % 2 == 1) {
        a = a*3 + 1;
    }
    return aToB(a, b);
}

int main()
{
    // int a, b, c;
    // int hasil;
    // scanf("%d %d", &a, &b);
    // scanf("%d", &c);
    // hasil = fibonacci(a, b, c);
    // printf("%d\n", hasil);
    //================================
    // long long int a, b, c;
    // long long int hasil;
    // scanf("%lld %lld %lld", &c, &a, &b);
    // hasil = fibonacci2(c, a, b);
    // printf("%lld\n", hasil);
    //================================
    int a, b;
    int hasil;
    int kasus;
    scanf("%d", &kasus);
    for (int i = 0; i < kasus; i++) {
        scanf("%d %d", &a, &b);
        if (aToB(a,b) == 1) {
            printf("Case #%d: YES\n", i+1);
        } else {
            printf("Case #%d: NO\n", i+1);
        }
    }
}