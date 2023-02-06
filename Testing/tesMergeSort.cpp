#include <stdio.h>

void merge(int* arr, int low, int mid, int high)
{
    int temp[high + 1];
    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high) {
        if (arr[i] >= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= high) {
        temp[k++] = arr[j++];
    }

    for (int x = low; x < high + 1; x++) {
        arr[x] = temp[x];
    }
}

void mergeSort(int* arr, int low, int high)
{
    if (low == high) return;
    int mid = (low + high) / 2;
    
    //rekursi
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);

    merge(arr, low, mid, high);
}

int main()
{
    int arr[] = {4, 5, 2, 3, 1, 3};
    int len = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, len - 1);

    for (int i = 0; i < len; i++) printf("%d ", arr[i]);
}