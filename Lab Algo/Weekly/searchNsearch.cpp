#include <stdio.h>

void doLinearSearch(int* arr, int len)
{
    int find = 40;  //angka yang dicari

    int count = 0;
    bool isFound = false;

    for (int i = 0; i < len; i++) {     //loop untuk cek dari awal sampe akhir
        if (arr[i] == find) {   // cek kesamaan data
            isFound = true;
            printf("Number Found on Index [%d].\n", i);
            break;  //kalo 1 data doang
        }
        // count++;
    }

    if (count == len) {
        printf("Number not found.\n");
    } else if (!isFound) {
        printf("Number not found.\n");
    }

}

// =============================================================================

void doBinarySearch(int* arr, int left, int right)
{
    int find = 31;
    // 31 - 49 tidak bisa
    bool isFound = false;

    while (left <= right) {
        // check data sama atau ngga

        // int mid = (left + right) / 2;
        int mid = left + (right - left) * (find - arr[left]) / (arr[right] - arr[left]);
        
        // printf("%d %d %d\n", left, right, mid);
        if (arr[mid] == find) {
            isFound = true;
            printf("Number found at index [%d].\n", mid);
            break;
        } else if (arr[mid] < find) {
            left = mid + 1;
        } else if (arr[mid] > find) {
            right = mid - 1;
        }
    }

    if (!isFound) {
        printf("Number not found.\n");
        return;
    } else if (left > right) {
        printf("Number not found.\n");
        return;
    }
}

int main()
{
    int arr[] = {10, 20, 20, 30, 60, 60};
    int len = sizeof(arr) / sizeof(int);

    // doLinearSearch(arr, len);
    doBinarySearch(arr, 0, len - 1);

    return 0;
}


// INTERPOLATION
// + - * - / - 
// left right left || find || (array) left right left