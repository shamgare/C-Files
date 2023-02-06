#include <stdio.h>
#include <string.h>

int main()
{
    char string[255] = {};
    int arr[255] = {};
    scanf("%[^\n]", string);

    for (int i = 0; i < strlen(string); i++) {
        if (string[i] >= 65 && string[i] <= 90) {
            string[i] = string[i] + 32;
        }
        arr[string[i]]++;
    }

    for (int i = 0; i < strlen(string); i++) {
        if (arr[string[i]] == 1) string[i] = '(';
        else {
            string[i] = ')';
        }
    }
    printf("%s\n", string);

    return 0;
}