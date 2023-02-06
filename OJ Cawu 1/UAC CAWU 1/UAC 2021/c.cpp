#include <stdio.h>

int part(double* arr, int low, int high)
{
    int i = low - 1;
    int j = low;
    double pivot = arr[high];

    while (j < high) {
        if (arr[j] <= pivot) {
            i++;
            double temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
        j++;
    }
    arr[high] = arr[i+1];
    arr[i+1] = pivot;

    return i + 1;
}

void qs(double* arr, int low, int high)
{
    if (low < high) {
        int pos = part(arr, low, high);

        qs(arr, low, pos - 1);
        qs(arr, pos + 1, high);
    }
}

int main()
{
    int kasus; scanf("%d", &kasus);
    
    for (int i = 0; i < kasus; i++) {
        int num; scanf("%d", &num);

        double nums[num] = {};
        for (int j = 0; j < num; j++) {
            scanf("%lf", &nums[j]);
        }

        qs(nums, 0, num-1);

        double q1 = 0, q2 = 0, q3 = 0;

        int index1 = (num + 1) / 4;
        int index2 = 2 * (num + 1) / 4;
        int index3 = 3 * (num + 1) / 4;

        if (num % 2 == 1) {
            printf("Case #%d: %.2lf %.2lf %.2lf\n", i+1, nums[index1 - 1], nums[index2 - 1], nums[index3 - 1]);
        } else {
            double x = nums[index1 - 1] * 0.75 + nums[index1] * 0.25;
            double y = nums[index2 - 1] * 0.50 + nums[index2] * 0.50;
            double z = nums[index3 - 1] * 0.25 + nums[index3] * 0.75;
            printf("Case #%d: %.2lf %.2lf %.2lf\n", i+1, x, y, z);
        } 
    }
}
// 10.50, 2,75