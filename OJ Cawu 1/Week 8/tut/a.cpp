#include <stdio.h>

int main()
{
    int num;
    scanf("%d", &num);

    int arr[num][num];
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    int spasi = 1;
    for (int i = 0; i < num; i++) {
        spasi = 1;
        for (int j = 0; j < num; j++) {
            if (spasi-- == 1) printf("%d", arr[j][i]);
            else printf(" %d", arr[j][i]);
        }
        printf("\n");
    }
}