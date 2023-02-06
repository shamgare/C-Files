#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LL long long int

//PROBLEM 2
// void sortValue(LL *array, LL low, LL high)
// {
//     if (low < high)
//     {
//         LL middle = low + (high - low) / 2, i, j, k;
//         sortValue(array, low, middle); sortValue(array, middle + 1, high);
//         LL leftSize = middle - low + 1, rightSize = high - middle, leftArray[leftSize], rightArray[rightSize];
//         for (i = 0; i < leftSize; i++) leftArray[i] = array[low + i];
//         for (j = 0; j < rightSize; j++) rightArray[j] = array[middle + 1 + j];
//         i = 0, j = 0, k = low;
//         while (i < leftSize && j < rightSize)
//         {
//             if (leftArray[i] <= rightArray[j]) { array[k] = leftArray[i]; i++; }
//             else { array[k] = rightArray[j]; j++; } k++;
//         }
//         while (i < leftSize) { array[k] = leftArray[i]; i++; k++; }        
//         while (j < rightSize) { array[k] = rightArray[j]; j++; k++; }
//     }
// }
// LL searchValue(LL *array, LL size, LL start, LL target, LL pivot)
// {
//     LL left = start, right = size - 1;
//     while (left <= right)
//     {
//         LL middle = (right + left) / 2, temp = target - pivot;
//         if (temp <= 0) return 0;
//         if (array[middle] == temp && array[middle] > pivot) return 1;
//         if (array[middle] > temp) right = middle - 1;
//         else left = middle + 1;
//     }
//     return 0;
// }
// int main()
// {
//     int input, i; scanf("%d", &input); getchar();
//     for (i = 1; i <= input; i++)
//     {
//         LL number; scanf("%lld", &number); getchar();
//         LL values[number], j, last = 0, count = 0;
//         for (j = 0; j < number; j++) scanf("%lld", &values[j]);
//         LL target; scanf("%lld", &target); getchar();
//         sortValue(values, 0, number - 1);
//         for (j = 0; j < number; j++)
//         {
//             if (values[j] == last) continue;
//             if (target - values[j] <= 0) break;
//             count += searchValue(values, number, j, target, values[j]);
//             last = values[j];
//         }
//         printf("Case #%d: %lld\n", i, count);
//     }
// }

//PROBLEM 3
int main() {
    int people;
    scanf("%d", &people);
    int total[people];
    int tim1[people/2 + 1] = {};
    int tim2[people/2 + 1] = {};
    int c1 = 0, c2 = 0, t1 = 0, t2 = 0;
    for (int i = 0; i < people; i++) {
        scanf("%d", & total[i]);
    }
    for (int i = people - 1; i >= 0; i--) {
        int g1 = t1 + total[i] - t2;
        int g2 = t2 + total[i] - t1;
        if (g1 <= g2) {
            t1 += total[i];
            tim1[c1] = total[i];
            c1++;
        } else {
            t2 += total[i];
            tim2[c2] = total[i];
            c2++;
        }
    }
    for (int i = 0 ; i < c1; i++) {
        printf("%d ", tim1[i]);
    }
    printf("= %d\n", t1);
    for (int i = 0 ; i < c2; i++) {
        printf("%d ", tim2[i]);
    }
    printf("= %d\n", t2);
}

//PROBLEM TUTOR 01
// void subArrays(int *array, int start, int end, int size)
// {
//     if (end == size) return;
//     else if (start > end) subArrays(array, 0, end + 1, size);
//     else
//     {
//         for (int i = start; i <= end; i++) printf("%d%s", array[i], i == end ? "\n" : " ");
//         subArrays(array, start + 1, end, size);
//     }
//     return;
// }
// int main()
// {
//     int input, i; scanf("%d", &input); getchar();
//     int values[input];
//     for (i = 0; i < input; i++) scanf("%d", &values[i]);
//     subArrays(values, 0, 0, input);
//     return 0;
// }

//PROBLEM TUTOR 02
// int main()
// {
//     LL input, i; scanf("%lld", &input); getchar();
//     LL values[input], result = 0;
//     for (i = 0; i < input; i++) scanf("%lld", &values[i]);
//     for (i = 0; i < input; i++) result += (values[i] * (i + 1) * (input - i));
//     printf("%lld\n", result);
//     return 0;
// }