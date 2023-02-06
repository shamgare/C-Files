#include <stdio.h>
#include <string.h>

int main()
{
    int kasus; scanf("%d", &kasus); getchar();

    for (int i = 0; i < kasus; i++) {
        char str[101] = {};
        scanf("%s", str);

        if (strlen(str) % 2 == 1) {
            printf("NO\n");
        } else {
            int index = (0 + strlen(str)) / 2;
            int temp = index;
            
            for (int j = 0; j < index; j++) {
                if (str[j] != str[temp]) {
                    printf("NO\n");
                    break;
                }
                if (j == index - 1) printf("YES\n");
                temp++;
            }
        }
    }
}