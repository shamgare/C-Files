#include <stdio.h>
#include <string.h>

bool check(char* str, int len)
{
    int arr[26] = {};

    for (int i = 0; i < len; i++) {
        if (str[i] >= 65 && str[i] <= 90) {
            str[i] += 32;
        }
        if (str[i] >= 97 && str[i] <= 122) {
            arr[str[i] - 97] = 1;
        }
        // printf("%d ", arr[str[i] - 97]);
    }
    int flag = 1;
    for (int i = 0; i < 26; i++) {
        if(arr[i] == 1) flag = 0;
        else flag = 1;
        if (flag == 1) return false;
    }
    return true;
}

int main()
{
    char str[255] = {};
    scanf("%[^\n]", str);

    printf("%d\n", check(str, strlen(str)));

    // printf("%d\n", bol);
}