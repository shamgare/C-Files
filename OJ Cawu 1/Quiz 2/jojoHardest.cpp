#include <stdio.h>

int arr[400010];
int size;
long long int limit;
long long int arr2[400010];

long long int func()
{
	long long int max = 0, sum = 0;
	int i = size, j = size, k = 0;
	
	while (i >= 0) {
		if (sum == limit) {
			return sum;
		} else if (sum < limit) {
			i--;
			k++;
			// printf("%d %d %d\n", sum, arr[i], k);
			sum += (arr[i] * k);
		} else {
			k--;
			// printf("%d %d %d\n", sum, arr2[i], arr2[j]);
			sum -= (arr2[i] - arr2[j]);
			j--;
		}
		
		if (sum > max && sum <= limit) max = sum; // 6 14
	}
	
	return max;
}

int main()
{
	scanf("%d", &size);
	
	for (int i = 0; i < size; i++) scanf("%d", &arr[i]);
	
	long long int sum = 0;
	for (int i = size - 1; i >= 0; i--) {
		sum += arr[i]; arr2[i] = sum;
		// printf("%d\n", arr2[i]);
	}

	scanf("%lld", &limit);
	
	printf("%lld\n", func());
	
	return 0;
}

/*

hand trace
size = 5
limit = 10

arr = 6 1 3 4 6
arr2 = 20 14 13 10 6



*/