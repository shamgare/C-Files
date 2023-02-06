#include <stdio.h>

int main()
{
    int kasus;
    scanf("%d", &kasus);

    for (int i = 0; i < kasus; i++) {
        float a;
        scanf("%f", &a);
        printf("%.2f %.2f %.2f\n", a*4/5, a*9/5 + 32, a + 273);
    }
}