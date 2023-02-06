#include <stdio.h>

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    for (int i = 0; i < 100; i++) {
        if (a == c && b == c && i == 0) {
            printf("%d\n", i);
            break;
        }

        a += 1;
        b -= 1;

        if (a == c && b == c) {
            printf("%d\n", i+1);
            break;
        } else if (b < c || a > c) {
            printf("-1\n");
            break;
        }
    }
    return 0;
}