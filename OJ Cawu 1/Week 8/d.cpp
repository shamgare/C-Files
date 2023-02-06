#include <stdio.h>

int main()
{
    int k;
    scanf("%d", &k);

    for (int i = 0; i < k; i++) {
        int num;
        scanf("%d", &num);

        int arr[num][num] = {};
        int sum[num] = {};
        for (int j = 0; j < num; j++) {
            for (int k = 0; k < num; k++) {
                scanf("%d", &arr[j][k]);
            }
        }
        for (int j = 0; j < num; j++) {
            for (int k = 0; k < num; k++) {
                sum[k] += arr[j][k];
            }
        }
        printf("Case #%d:", i+1);
        int spasi = 1;
        for (int j = 0; j < num; j++) {
            if (spasi == 1) printf(" %d", sum[j]);
            else printf("%d", &sum[j]);
        }
        printf("\n");
    }

}