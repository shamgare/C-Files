#include <stdio.h>

int part(int* arr, int low, int high)
{
    int i = low - 1;
    int j = low;
    int pivot = arr[high];

    while (j < high) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
        j++;
    }
    arr[high] = arr[i+1];
    arr[i+1] = pivot;

    return i+1;
}

void qs(int* arr, int low, int high)
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
        int year; scanf("%d", &year);
        int years[year];

        for (int j = 0; j < year; j++) {
            scanf("%d", &years[j]);
        }

        qs(years, 0, year - 1);

        int min = years[1] - years[0];
        for (int j = 0; j < year - 1; j++) {
            if (years[j+1] - years[j] <= min) min = years[j+1] - years[j];
        }

        printf("Case #%d: %d\n", i+1, min);
    }
}