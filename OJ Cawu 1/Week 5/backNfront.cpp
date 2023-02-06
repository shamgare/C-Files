#include <stdio.h>
#include <string.h>

int main()
{
    int i = 0;
    do {
        int a;
        scanf("%d", &a);
        char str[a+1];
        scanf("%s", str);
        printf("%c%c\n", str[strlen(str)-1], str[0]);
        i++;
    } while (i!=3);
    
    return 0;
}