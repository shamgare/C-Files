#include <stdio.h>

int main()
{
    int kasus;
    int num;
    scanf("%d", &kasus);
    for (int i = 0; i < kasus; i++) {
        scanf("%d", &num);
        getchar();

        char str1[num] = {};
        char str2[num] = {};
        scanf("%s", str1);
        scanf("%s", str2);

        int count = 0;
        for (int j = 0; j < num; j++) {
            if (str1[j] != str2[j]) {
                count++;
            }
        }
        
        printf("Case #%d: %d\n", i+1, (num-count)*100/num);
        // printf("Case #%d: %d\n", i+1, (num-count)/num * 100);
    }
}