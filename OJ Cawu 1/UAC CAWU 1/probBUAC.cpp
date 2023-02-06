#include <stdio.h>
#include <limits.h>

void func(int pos, int part, int *arr, int size, long long limit)
{
	long long count = 0;
	int curr = -1, i;
	for (i = pos; i >= 0; i--) {
		if (count + arr[i] > limit || i == part - 2) {
			func(i, part - 1, arr, size, limit); curr = i; break;
		}
		count += arr[i];
	}
	if (curr >= 0) printf("; ");
	for (i = curr + 1; i <= pos; i++) {
		printf("%d%s", arr[i], i == size - 1 ? "" : " ");
	}
}

long long search(int* arr, int size, int part)
{
	long long low = 1, limit = LLONG_MAX, right = LLONG_MAX;
	
	while (low < right) {
		long long high = low + (right - low) / 2, sum = 0;
		int status = -1, idx = 0, curr = 1;
		while (idx < size) {
			if (arr[idx] > high) status = 0;
			if (sum + arr[idx] > high) {
				curr++; sum = 0;
			}
			if (sum <= high) {
				sum += arr[idx]; idx++;
			}
		}
		if (curr <= part) status = 1;
		if (status == -1) status = 0;
		if (status) {
			limit = (limit < high) ? limit : high; right = high;
		}
		else low = high + 1;
	}
	return limit;
}

int main()
{
    int input, i, j; scanf("%d", &input); getchar();
    for (i = 1; i <= input; i++) {
        int kota, staff; scanf("%d %d", &kota, &staff); getchar();
        int arr[505];
        for (j = 0; j < kota; j++) scanf("%lld", &arr[j]);
        long long limit = search(arr, kota, staff);
		func(kota - 1, staff, arr, kota, limit);
		puts("");
    }
}