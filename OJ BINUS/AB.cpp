#include <stdio.h>

int main()
{
    int toys;
    scanf("%d", &toys);

    for (int i = 0; i < toys; i++) {
        int n, a, b, c, d;
        scanf("%d %d %d %d %d", &n, &a, &b, &c, &d);

        int counter = 0;
        for (int j = 1; j <= n; j++) {
            if (j % a == 0 || j % b == 0 || j % c == 0 || j % d == 0) {
                counter++;
            }
        }
        printf("%d\n", counter);
    }
    return 0;
}