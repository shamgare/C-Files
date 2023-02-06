#include <stdio.h>

void func(int n)
{
    static char memo[2000] = { 0 };
    if (n == 0) { printf("a"); return; }
    if (n == 1) { printf("b"); return; }

    func(n - 1);
    func(n - 2);
}

int main()
{
    int k; scanf("%d", &k);
    func(k);
}