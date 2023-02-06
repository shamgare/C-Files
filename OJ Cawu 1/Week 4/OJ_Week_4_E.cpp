#include <stdio.h>
#include <string.h>

int main()
{
	int kasus, i, x, y, a;
	scanf("%d", &kasus);

	for (i = 0; i < kasus; i++)
	{
		char str[550];
		scanf("%s", str);
		getchar();
		x = 0;
		y = strlen(str) - 1;

		while (y > x)
		{
			if (str[x] != str[y])
			{
				a = 0;
				break;
			}
			else
			{
				a = 1;
			}
			x++;
			y--;
		}

		if (a == 0)
		{
			printf("Case #%d: Nah, it's not a palindrome\n", i + 1);
		}
		else
		{
			printf("Case #%d: Yay, it's a palindrome\n", i + 1);
		}
	}
	return 0;
}
