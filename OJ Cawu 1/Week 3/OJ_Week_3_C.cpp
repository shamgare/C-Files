#include <stdio.h>

int main()
{
	int i, j, k, x, kasus, harga[101] = {}, a, b;

	scanf("%d", &x);

	for (i = 0; i < x; i++)
	{
		scanf("%d", &harga[i]);
	}

	scanf("%d", &kasus);

	for (j = 0; j < kasus; j++) {
		scanf("%d %d", &a, &b);
		harga[a - 1] = b;
		printf("Case #%d: ", j + 1);
		for (k = 0; k < x; k++)
		{
			printf("%d", harga[k]);
			if (k + 1 != x)
			{
				printf(" ");
			}
		}
		printf("\n");
	}

	return 0;
}
