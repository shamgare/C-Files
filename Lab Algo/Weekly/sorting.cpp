#include <stdio.h>

// bubble sort
// selection sort
// insertion sort
// kapan digunain?

//=======================================================================================================
void doBubbleSort(int *arr, int len)
{
    int temp;

    for (int i = 0; i < len - 1; i++) {         // 1. tandakan pembanding awal (loop)
        for (int j = i + 1; j < len; j++) {     // 2. tandakan pembanding ke2 (bagian kanan)
            if (arr[i] <= arr[j]) {}            // 3. proses penukaran (pembanding awal < pembanding ke2)
            else {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }

    for (int k = 0; k < 5; k++) {               // 4. print array yg sudah di sort
        printf("%d ", arr[k]);
    }
    puts("");
}
//=======================================================================================================

//=======================================================================================================
// pendukung insertion short
int sortedArr[5] = {};

void sort(int limit)
{
    int temp;
    // pasang logic sorting dulu (kecil ke besar)
    for (int i = 0; i < limit-1; i++) {
        if (sortedArr[i] <= sortedArr[limit]) {}
        else {
            temp = sortedArr[limit];
            sortedArr[limit] = sortedArr[i];
            sortedArr[i] = temp;
        }
    }
}

void doInsertionSort(int *arr, int len)
{
    int temp;

    for (int i = 0; i < len; i++) {
        // insert 1 data
        sortedArr[i] = arr[i];
        // setiap input data, lakukan sorting
        sort(i);
    }

    for (int k = 0; k < 5; k++) {
        printf("%d ", sortedArr[k]);
    }
    puts("");
}
//=======================================================================================================
void doSelectionSort(int *arr, int len)
{
    int temp;
    for (int i = 0; i < len; i++) {
        int indexMin = -1;
        for (int j = i; j < len; j++) {
            // tandain yg paling kecil
            if (j == i) indexMin = j;
            else if (arr[j] < arr[indexMin]) {
                indexMin = j;
            }
        }
        if (indexMin == i) {}
        else {
            temp = arr[i];
            arr[i] = arr[indexMin];
            arr[indexMin] = temp;
        }
    }

    for (int k = 0; k < 5; k++) {
        printf("%d ", arr[k]);
    }
    puts("");
}
//=======================================================================================================

int main()
{
    int arr[] = {5, 9, 2, 7, 3};
    int len = sizeof(arr) / sizeof(arr[0]);
 
    doBubbleSort(arr, len);
    doInsertionSort(arr, len);
    doSelectionSort(arr, len);

    return 0;
}