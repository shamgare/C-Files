#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void a(), b(), c();
int count = 0;

int main()
{
    a();
    //b();
    //c();
    return 0;
}

char* fibo1(int index, char* x, char* y)
{
    if (index == 0) return x;
    else if (index == 1) return y;

    return strcat(fibo1(index-1, x, y), fibo1(index-2, x, y));
}

void a()
{
    int kasus;
    scanf("%d", &kasus);
    getchar();

    for (int i = 0; i < kasus; i++) {
        char str[20][20000] = {};
        int index = 0;
        
        scanf("%d", &index);
        getchar();
        scanf("%c %c", &str[0], &str[1]);
        getchar();

        for (int j = 2; j <= index; j++) {
            sprintf(str[j], "%s%s", str[j-1], str[j-2]);
        }

        printf("Case #%d: %s\n", i+1, str[index]);
    }
}












// int fibo2(int index, int a, int b)
// {
//     if (index == 0) {
//         count++;
//         return a;
//     }
//     if (index == 1) {
//         count++;
//         return b;
//     }

//     return fibo2()
// }

int fibo(int a)
{
    if (a == 0 || a == 1) {
        count++;
        return a;
    }
    count++;
    return fibo(a-2) + fibo(a-1);
}

void b()
{
    int kasus;
    int index;
    scanf("%d", &kasus);

    for (int i = 0; i < kasus; i++) {
        scanf("%d", &index);
        fibo(index);
        int c = count;
        printf("Case #%d: %d\n", i+1, c);
    }
}



void c()
{
    int kasus;
    int index;
    scanf("%d", &kasus);
    for (int i = 0; i < kasus; i++) {
        scanf("%d", &index);

        int arr[1005] = {};
        int count[1005] = {};
        int max = -1;
        for (int j = 0; j < index; j++) {
            scanf("%d", &arr[j]);
            if (arr[j] >= max) {
                max = arr[j];
                count[arr[j]]++;
            }
        }

        printf("Case #%d: %d\n", i+1, count[max]);
    }
}