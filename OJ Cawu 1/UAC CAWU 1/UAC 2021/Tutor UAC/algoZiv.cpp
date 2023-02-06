#include <stdio.h>

int arr[5000] = {}, n;
long long int sum = 0;

void print(int i, int cnt)
{
	for (int j = i; j <= i + cnt && j < n;j++)
	{
        printf("%d ", arr[j]);
        // sum += arr[j];
    }
	printf("\n");

	if (cnt + i >= n - 1)
	{
		return;
	}
	else
	{
		return print(i, cnt + 1);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n;i++)
	{
		scanf("%d", &arr[i]);
	}
	
	for (int i = 0; i < n;i++)
	{
		print(i, 0);
    }
    printf("%lld\n", sum);
}