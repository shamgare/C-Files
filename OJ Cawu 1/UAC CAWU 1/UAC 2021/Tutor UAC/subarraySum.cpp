#include <stdio.h>

int arr[40000];
long long int sum = 0;

void func(int n, int index)
{
    if (n < 0) return;
    
    func(n - 1, index);

    for (int i = index; i <= n; i++) sum += arr[i];
}

int main()
{
    int size; scanf("%d", &size);

    for (int i = 0; i < size; i++) scanf("%d", &arr[i]);
    
    for (int i = 0; i < size; i++) func(size - 1, i);

    printf("%lld\n", sum);
}
