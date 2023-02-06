#include <stdio.h>

int partition(int* arr, int low, int high)
{
    int i = low - 1;
    int j = low;
    int pivot = arr[high];

    while (j < high) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
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
        int pos = partition(arr, low, high);

        quickSort(arr, pos+1, high);
        quickSort(arr, low, pos-1);
    }
}

int main()
{
    int size;
    scanf("%d", &size);

    int arr[size];
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    quickSort(arr, 0, size - 1);

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

void bubble(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i+1; j < size; j++) {
            if (arr[i] <= arr[j]) {int temp = arr[j]; arr[j] = arr[i]; arr[i] = temp;}
        }
    }
}