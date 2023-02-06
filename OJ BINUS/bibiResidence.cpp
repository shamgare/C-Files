#include <stdio.h>

int main()
{
    int kasus;
    scanf("%d", &kasus);
    for (int i = 0; i < kasus; i++) {
        int house;
        scanf("%d", &house);
        int num[house];
        for (int j = 0; j < house; j++) {
            scanf("%d", &num[j]);
        }
        int temp = 1000;
        int diff;
        for (int j = 0; j < house - 1; j++) {
            diff = num[j] - num[j+1];
            if (diff < 0) diff *= -1;
            if (diff < temp) {
                temp = diff;
            }
        }
        printf("%d\n", temp);
    }
}