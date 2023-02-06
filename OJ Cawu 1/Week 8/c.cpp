#include <stdio.h>

int main()
{
    int kasus;
    scanf("%d", &kasus);

    for (int i = 0; i < kasus; i++) {
        long long int num;
        int arr[1005] = {};
        scanf("%lld", &num);

        printf("Case #%d:", i+1);
        
        int j;
        for (j = 0; num > 0; j++) {    
            arr[j] = num % 2;
            num = num / 2;
            // printf("%d ", num);   
        }
        int spasi = 1;
        for (j = j - 1; j >= 0; j--) {    
            if (spasi-- == 1) printf(" %d", arr[j]);
            else printf("%d", arr[j]);
        }    
        printf("\n");
    }
    return 0;
}