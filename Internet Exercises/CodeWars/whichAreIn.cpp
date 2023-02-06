#include <stdio.h>
#include <string.h>

void func(char arr1[][200], char arr2[][200], int size1, int size2)
{
    char arr[size1][200] = {};
    int k = 0;
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (strstr(arr1[i], arr2[j]) != NULL) {
                strcpy(arr[k], arr1[i]); k++;
            }
        }
    }

    for (int i = 0; i < size1; i++) {
        printf("%s ", arr[i]);
    }
}

int main()
{
    char arr1[3][200] = { "fsu", "dua", "saron" };
    char arr2[5][200] = { "wsfsu", "duadd", "woksaron", "baju", "wjwj" };

    func(arr1, arr2, 3, 5);
}