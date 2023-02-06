#include <stdio.h>

int flag;
int count;

int func(int num)
{
    if (num <= 1) return flag;

    // printf("%d\n", num);
    if (num % 2 == 1) { num *= 3; num++;
    } else num /= 2; 
    
    count++;
    
    if (count % 2 == 1) flag = 1; else flag = 0;

    func(num);
}

int main()
{
    int kasus; scanf("%d", &kasus);

    int num;
    for (int i = 0; i < kasus; i++) {
        scanf("%d", &num);

        count = 0;
        func(num);

        if (flag) printf("Jojo\n");
        else printf("Lili\n");
    }
}