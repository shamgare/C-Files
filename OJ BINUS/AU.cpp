#include <stdio.h>

int main()
{
    int kasus;
    scanf("%d", &kasus);

    for (int i = 0; i < kasus; i++) {
        int num;
        scanf("%d", &num);

        printf("Case #%d: ", i+1);
        for (int j = 0; j < num; j++) {
            printf("%c", j+97);
        }
        puts("");
    }
}