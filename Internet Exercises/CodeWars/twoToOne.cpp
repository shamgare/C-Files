#include <stdio.h>
#include <string.h>

void longest(const char* str1, const char* str2)
{
    int cache[26] = {};
    char result[26] = {};
    char alpha[] = {"abcdefghijklmnopqrstuvwxyz"};

    while (*str1) {
        cache[*str1 - 'a']++;
    }
    while (*str2) {
        cache[*str2 - 'a']++;
    }
    int index = 0;

    for (int i = 0; i < 26; i++) {
        if (cache[i] > 0) {result[index] = alpha[i]; index++; }
    }

    printf("%s\n", result);
}

char* longest2(char* str1, char* str2)
{
    int cache[26] = {};
    char* result;
    char abcde[] = {"abcdefghijklmnopqrstuvwxyz"};

    for (int i = 0; i < strlen(str1); i++) {
        cache[str1[i] - 'a']++;
    }
    for (int i = 0; i < strlen(str2); i++) {
        cache[str2[i] - 'a']++;
    }

    int index = 0;

    for (int i = 0; i < 26; i++) {
        if (cache[i] > 0) {
            result[index] = abcde[i];
            index++;
        }
    }

    return result;
}

int main()
{
    char str1[300] = {}, str2[300] = {};
    char abcde[] = {"abcdefghijklmnopqrstuvwxyz"};
    int counter[26] = {};
    char result[26] = {};

    scanf("%s %s", str1, str2);
    for (int i = 0; i < strlen(str1); i++) {
        counter[str1[i] - 'a']++;
    }
    for (int i = 0; i < strlen(str2); i++) {
        counter[str2[i] - 'a']++;
    }

    int index = 0;
    for (int i = 0; i < 26; i++) {
        if (counter[i] > 0) result[index++] = abcde[i];
    }
    
    printf("%s\n", result);
}