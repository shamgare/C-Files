#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nums[] = {2, 7, 4, 3};
    //            0  1  2  3
    int numsSize = 4;
    int target = 11;
    int* arr;
    arr = (int*) malloc(2 * (sizeof(int)));
    
    int x = 0;
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < numsSize; j++) {
            if (j != i) {
                if (nums[i] + nums[j] == target) {
                    arr[0] = j;
                    arr[1] = i;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < 2; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}