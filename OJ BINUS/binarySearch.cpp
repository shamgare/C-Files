#include <stdio.h>

int binary(double* arr, int left, int right, double check)
{
    int index = -1;
    while (left <= right) {
        int mid = (left + right) / 2;

        // printf("%lf %lf\n", arr[mid] * (arr[mid] + 1) * (2 * arr[mid] + 1) / 6, check);

        if (arr[mid] * (arr[mid] + 1) * (2 * arr[mid] + 1) / 6 >= check) {
            index = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return index;
}

int main()
{
    int kasus; scanf("%d", &kasus);
    for (int i = 0; i < kasus; i++) {
        double num = 0; scanf("%lf", &num);

        double arr[(int)num];
        for (int j = 0; j <= num; j++) {
            arr[j] = j;
        }

        printf("Case #%d: %d\n", i+1, binary(arr, 0, num, num));
    }
}

// 1 5 14 30 55 91
// 1 2 3  4  5  6
// 1 4 9  16 25 36