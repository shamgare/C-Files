#include <stdio.h>
// soal belah ketupat

int main()
{
    int t;
    float a, b, c, d, sum;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        sum = 0;
        scanf("%f %f %f %f", &a, &b, &c, &d);

        a /= 1;
        b /= 2;
        c /= 3;
        d /= 4;

        sum = a + b*2 + c*2 + d;
        printf("%.2f\n", sum*2);
    }
}