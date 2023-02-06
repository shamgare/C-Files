#include <stdio.h>

int main()
{
    int k; scanf("%d", &k); getchar();
    for (int i = 0; i < k; i++) {
        int a, b; scanf("%d %d", &a, &b);
        int sum = 0, j = 1, hasil = 0;
        while (a > 0 || b > 0) {
            hasil = ((a % 10) + (b % 10)) % 10;
            sum += hasil*j;
            a /= 10;
            b /= 10;
            j *= 10;
        }
        printf("Case #%d: %d\n", i+1, sum);
    }
    return 0;
}