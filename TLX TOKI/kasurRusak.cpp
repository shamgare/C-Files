#include <stdio.h>
#include <string.h>

bool palin(char* str, int left, int right)
{
    if (right == left || left > right) return true;
    if (str[left] != str[right]) return false;

    return palin(str, left+1, right-1);
}

int main()
{
    char str[255] = {};
    scanf("%s", str);
    int len = strlen(str);

    if (palin(str, 0, len - 1) == 1) printf("YA\n");
    else printf("BUKAN\n");
    
    return 0;
}