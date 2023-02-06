#include <stdio.h>
#include <string.h>

int main()
{
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int a, b;
        char temp;
        char ap[5] = {};
        scanf("%d%c%d%c%s", &a, &temp, &b, &temp, ap);

        if (strcmp(ap, "am") == 0) {
            if (a > 12) a -= 12;
            else if (a == 12) a -= 12;
        } else {
            if (a < 12) a += 12;
        }

        printf("Case #%d: %02d:%02d\n", i+1, a, b);
    }
    return 0;
}