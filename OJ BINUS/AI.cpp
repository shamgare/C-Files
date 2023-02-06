#include <stdio.h>

int main()
{
    int kasus;
    int besarArray;
    

    scanf("%d", &kasus);
    for (int i = 0; i < kasus; i++) {
        int arr[255] = {};
        int sum = 0;

        scanf("%d", &besarArray);
        for (int j = 0; j < besarArray; j++) {
            scanf("%d", &arr[j]);
        }

        int leftsum = 0;
        int count = 0;
        for (int j = 0; j < besarArray; j++) {
            leftsum += arr[j];
            int rightsum = 0;
            for (int k = j+1; k < besarArray; k++) {
                rightsum += arr[k];
            }
            if (leftsum == rightsum) {
                count = 1;
                break;
            }
        }

        if (count == 1) {
            printf("Yes.\n");
        } else {
            printf("No.\n");
        }
    }
    return 0;
}