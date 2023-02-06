#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count = 0;

int fibo(int a)
{
    if (a == 0 || a == 1) {
        count++;
        return a;
    }
    count++;
    return fibo(a-2) + fibo(a-1);
}

int main()
{
    int kasus;
    int num;
    scanf("%d", &kasus);

    for (int i = 0; i < kasus; i++) {
        count = 0;
        scanf("%d", &num);
        fibo(num);
        int c = count;
        printf("Case #%d: %d\n", i+1, c);
    }
}