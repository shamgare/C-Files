#include <stdio.h>

int arr[40000];
int check = 0;

void func(int n, int index)
{
    if (n < 0) return;
    
    func(n - 1, index);

    check = 0;
    for (int i = index; i <= n; i++) {
        printf("%d ", arr[i]); check++;
    }
    if (check > 0) printf("\n");
}

int main()
{
    int size; scanf("%d", &size);

    for (int i = 0; i < size; i++) scanf("%d", &arr[i]);
    
    for (int i = 0; i < size; i++) func(size - 1, i);
}




