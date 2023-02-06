#include <stdio.h>

int partition(int* arr, int low, int high)
{
    int i = low - 1;
    int j = low;
    int pivot = arr[high];

    while (j < high) {
        if (arr[j] <= pivot) {
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

void quickSort(int* arr, int low, int high)
{
    if (low < high) {
        long long int pos = partition(arr, low, high);
        quickSort(arr, low, pos-1);
        quickSort(arr, pos, high);
    }
}

int binary(int* arr, int left, int right, int find)
{
    int index = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        // printf("%d %d %d\n", left, mid, right);
        if (arr[mid] == find) {
            index = mid + 1;
            right = mid - 1;
        } else if (arr[mid] < find) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return index;
}

int main()
{
    int size, find; scanf("%d %d", &size, &find);
    int arr[size];
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    // quickSort(arr, 0, size-1);
    int num;
    for (int i = 0; i < find; i++) {
        scanf("%d", &num);
        printf("%d\n", binary(arr, 0, size-1, num));
    }
}