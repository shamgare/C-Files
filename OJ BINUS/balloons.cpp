#include <stdio.h>

int main()
{
    int bal, pow;
    scanf("%d %d", &bal, &pow);

    int count = 0;
    for (int i = 0; i < bal; i++) {
        long long int str;
        scanf("%lld", &str);
        if (str < pow) count++;
    }
    printf("%d\n", count);
}