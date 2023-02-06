#include <stdio.h>

int main()
{
    int kasus;
    scanf("%d", &kasus);
    for (int i = 0; i < kasus; i++) {
        long long int a, b;
        scanf("%lld %lld", &a, &b);
        
        long long int rotate = a*b;
        printf("%.2f\n", (double) rotate / 360);
    }
    return 0;
}