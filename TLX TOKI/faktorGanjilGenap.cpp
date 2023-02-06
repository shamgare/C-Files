#include <stdio.h>

int fktrl(int num)
{
    if (num == 1 || num == 0) return 1;
    if (num % 2 == 0) return fktrl(num-1) * num/2;
    return num * fktrl(num-1);
}
int main()
{
    int num; scanf("%d", &num);
    printf("%d\n", fktrl(num));
}

//3 5 2 3 1 1