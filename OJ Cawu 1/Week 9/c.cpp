#include <stdio.h>

long long int binary(long long int* arr, long long int find, int left, int right)
{
    long long int index = -1;

    while (left <= right) {
        int mid = (left + right) / 2;
        
        if (arr[mid] <= find) {
            index = mid + 1;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return index;
}

int main()
{
    int size; scanf("%d", &size);

    long long int arr[size] = {};
    long long int num;
    for (int i = 0; i < size; i++) {
        scanf("%lld", &num);
        if (!i) arr[i] = num;
        else arr[i] = num + arr[i-1];
    }
    
    int uji; scanf("%d", &uji);
    long long int temp;

    for (int i = 0; i < uji; i++) {
        scanf("%lld", &temp);
        printf("Case #%d: %lld\n", i+1, binary(arr, temp, 0, size - 1));
    }
} 

/*
0
0 1
0 1 2
0 1 2 3 
0 1 2 3 4

1 2 v
1 2 3 v 
1 2 3 4 v
2 3 v
2 3 4 v
3 4 v

3 2 7 6

arr = 0 3 5 12 18
8  2
20 4
12 3

4
3 2 7 6 3
8
20
12
*/