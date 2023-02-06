#include <stdio.h>
#include <string.h>

int main()
{
    int kasus;
    scanf("%d", &kasus);

    for (int i = 0; i<kasus; i++) {
        char a[10];

        scanf("%s", a);

        if (strlen(a) == 1) {
            printf("%c\n", a[0]);

        } else if (strlen(a) > 1) {
            printf("Case %d: ", i+1);

            for (int j = 0; j<strlen(a); j++) {

                if (a[j]-48 != 0) {
                    printf("%c", a[j]);

                    for (int k = strlen(a); k>j+1; k--) {
                        printf("0");
                    }

                } else {
                    continue;
                }

                if (j == strlen(a) - 1) {
                    printf("\n");
                } else {
                    printf(" ");
                }
            }
        }
    }
    return 0;
}