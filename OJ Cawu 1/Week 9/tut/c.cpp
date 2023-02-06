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
        int pos = partition(arr, low, high);
        quickSort(arr, low, pos-1);
        quickSort(arr, pos, high);
    }
}

void binary(int* arr, int low, int high, int cari)
{
    bool isFound = false;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == cari) {
            isFound = true;
            printf("%d\n", mid + 1);
            break;
        } else if (arr[mid] < cari) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    if (!isFound) {
        printf("-1\n");
    }
}

int main()
{
    int siswa; scanf("%d", &siswa);
    int urutan[siswa];
    for (int i = 0; i < siswa; i++) {
        scanf("%d", &urutan[i]);
    }

    quickSort(urutan, 0, siswa-1);

    int cari; scanf("%d", &cari);
    for (int i = 0; i < cari; i++) {
        int tinggi; scanf("%d", &tinggi);
        binary(urutan, 0, siswa-1, tinggi);
    }
}