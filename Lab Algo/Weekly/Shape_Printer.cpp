#include <stdio.h>

int main()
{
	int n, i, j;
	printf("Shape Printer\n");
	printf("=============\n");
	printf("1. Rectangle\n");
	printf("2. Right Triangle (90 degree)\n");
	printf("3. Equilateral Triangle\n");
	printf("4. Exit\n");

	do
	{
		printf(">> ");
		scanf("%d", &n);
		switch (n)
		{
			int a, b;
		case 1:
			do
			{
				printf("Input rectangle width [must be more than 0]:");
				scanf("%d", &a);
			} while (a < 0);
			do
			{
				printf("Input rectangle height [must be more than 0]:");
				scanf("%d", &b);
			} while (b < 0);

			printf("Result:\n");
			for (i = 0; i < b; i++)
			{
				for (j = 0; j < a; j++)
				{
					printf("*");
				}
				printf("\n");
			}
			break;
		case 2:
			do
			{
				printf("Input triangle size [must be more than 0]:");
				scanf("%d", &a);
			} while (a < 0);

			printf("Result:\n");
			for (i = 1; i <= a; i++)
			{
				for (j = a; j > 0; j--)
				{
					if (j > i)
					{
						printf(" ");
					}
					else
					{
						printf("*");
					}
				}
				printf("\n");
			}
			break;
		case 3:
			do
			{
				printf("Input Equilateral triangle size [must be more than 0 and an odd number]:");
				scanf("%d", &a);
			} while ((a < 0) || (a % 2 == 0 && a > 0));

			printf("Result:\n");
			for (i = 1; i <= (a + 1) / 2; i++)
			{
				/* Print leading spaces */
				for (j = i; j <= (a + 1) / 2 - 1; j++)
				{
					printf(" ");
				}
				/* Print star */
				for (j = 1; j <= 2 * i - 1; j++)
				{ // 2 kali i - 1
					printf("*");
				}
				/* Move to next line */
				printf("\n");
			}
			break;
		case 4:
			printf("Thank you for using this app!\n");
			break;
		default:
			printf("You must input a valid number!\n");
			break;
		}
	} while (n != 4);
	return 0;
}
