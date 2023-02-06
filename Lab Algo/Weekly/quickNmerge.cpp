#include <stdio.h>
#include <stdlib.h>

void merge(int* arr, int leftIndex, int midIndex, int rightIndex)
{
    int leftSize = midIndex - leftIndex + 1;
    int rightSize = rightIndex - midIndex;
    int arrKiri[leftSize];
    int arrKanan[rightSize];
    int l = 0;
    int r = 0;
    int mergeIndex = leftIndex;

    for (int i = 0; i < leftSize; i++) {
        arrKiri[i] = arr[i + leftIndex];
    }
    for (int i = 0; i < rightSize; i++) {
        arrKanan[i] = arr[i + midIndex + 1];
    }

    while (l < leftSize && r < rightSize) {
        if (arrKiri[l] < arrKanan[r]) {
            arr[mergeIndex] = arrKiri[l];
            l++;
        } else {
            arr[mergeIndex] = arrKanan[r];
            r++;
        }
        mergeIndex++;
    }

    while (l < leftSize) {
        arr[mergeIndex] = arrKiri[l];
        l++;
        mergeIndex++;
    }
    
    while (r < rightSize) {
        arr[mergeIndex] = arrKanan[r];
        r++;
        mergeIndex++;
    }
}

void mergeSort(int* arr, int leftIndex, int rightIndex)
{
    if (leftIndex == rightIndex) return;
    
    int midIndex = (rightIndex + leftIndex) / 2;

    // array kiri
    mergeSort(arr, leftIndex, midIndex);
    // array kanan
    mergeSort(arr, midIndex + 1, rightIndex);

    merge(arr, leftIndex, midIndex, rightIndex);
}









int partition(int* arr, int low, int high) 
{
    int pivot = arr[high];
    int i = low - 1;
    int j = low;
    
    while (j < high) {
        if (pivot >= arr[j]) {
            i++;
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
        j++;
    }

    arr[high] = arr[i+1];
    arr[i+1] = pivot;

    return (i+1);
}

void quickSort(int* arr, int low, int high)
{
    // i dan j dimana i = low -1, j = low
    if (low == -1 || high == -1) return;
    if (low == high) return;

    int pos = partition(arr, low, high);
    
    quickSort(arr, low, pos-1);
    quickSort(arr, pos, high);
}








int main()
{
    // int arr[] = {9, 7, 6, 8, 5};
    // int arrSize = sizeof(arr) / sizeof(arr[0]);

    int* arr;
    int n;
    scanf("%d", &n);
    arr = (int*) calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // mergeSort(arr, 0, arrSize - 1);
    // quickSort(arr, 0, arrSize - 1);
    quickSort(arr, 0, n - 1);
    
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    puts("");

    return 0;
}

/*
QUICK SORT (>=)
1. Pivot (elemen paling akhir) di cek dengan tiap elemen yg ada sebelum dia
Selama j < index pivot
2. Jika elemen lebih kecil dari pivot (memenuhi syarat IF), tuker arr[i] dan arr[j] (masukin ke index pertama[0], dan seterusnya)
3. Jika elemen lebih besar dari pivot (TIDAK memenuhi syarat IF), j++
Setelah itu tuker elemen pivot dengan elemen yang udah ditandain menggunakan index i+1
Terakhir, return i+1 untuk menjadi pos untuk quicksort selanjutnya
*pos = tempat terjadi perubahan(?)
- Array kiri (low dan pos-1)
- Array kanan (pos dan high)
*/
