#include <stdio.h>
#include <string.h>

int main()
{
    int kasus;
    scanf("%d", &kasus);
    
    for (int i = 0; i < kasus; i++) {
        char str[100050];
        char alpha[123] = {};
        int sum = 0;
        scanf("%s", str);

        for (int k = 0; k<strlen(str); k++) {
            if (alpha[str[k]] == 0) {
                alpha[str[k]]++;
                sum++;
            }
        }

        printf("Case #%d: ", i+1);

        if (sum % 2 == 0) {
            printf("Breakable\n");
        } else {
            printf("Unbreakable\n");
        }
    }
    return 0;
}