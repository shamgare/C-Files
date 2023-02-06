#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>

int dupe(char* str)
{
    int count = 0;
    int i = 0;
    int arr[38] = {};
    while (str[i] != '\0') {
        if (str[i] >= 97 && str[i] <= 122) {
            arr[str[i] - 97]++;
        }
        if (str[i] >= 65 && str[i] <= 90) {
            arr[str[i] - 65]++;
        }
        if (str[i] >= 48 && str[i] <= 57) {
            arr[str[i] - 48 + 26]++;
        }
        i++;
    }

    for (int i = 0; i < 36; i++) {
        if (arr[i] > 1) count++;
    }

    return count;
}

size_t dupe2(const char* str)
{
    size_t count = 0; int cache[36] = {};
    while (*str) { if (isdigit(*str)) cache[*str - '0']++; if (tolower(*str)) cache[*str - 'a' + 10]++; str++; }
    for (int i = 0; i < 36; i++) { if (cache[i] > 1) count++; } 
    return count;
}

int main()
{
    char* str; scanf("%s", str);

    // printf("%d\n", dupe(str));
    printf("%d\n", dupe2(str));
}