#include <stdio.h>

int main()
{
    int kasus;
    scanf("%d", &kasus);

    for (int i = 0; i < kasus; i++) {
        int piring, kapasitas, porsi;
        scanf("%d %d %d", &piring, &kapasitas, &porsi);

        int arr[piring] = {};
        int porsi2[piring] = {};
        int max = -1;
        for (int j = 0; j < piring; j++) {
            scanf("%d", &arr[j]);
            porsi2[j] = porsi * arr[j];
            if (porsi2[j] >= max && porsi2[j] <= kapasitas) {
                max = porsi2[j];
            }
        }
        printf("Case #%d: %d\n", i+1, max);   
    }
    return 0;
}