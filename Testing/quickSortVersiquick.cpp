#include <stdio.h>
#include <stdlib.h>


int sort(const void * b, const void * a) { 
    return (*(int*)a - *(int*)b); 
}

int main()
{
    int arr[] = { 5, 4, 1, 3, 2 };
    int size = sizeof(arr) / sizeof(arr[0]);

    qsort(arr, size, sizeof(int), sort);

    for (int i = 0; i < size; i++) {
        printf("%d\n", arr[i]);
    }
    
    return 0;
}