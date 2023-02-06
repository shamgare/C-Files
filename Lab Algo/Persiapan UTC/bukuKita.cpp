#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

int main()
{
	srand(time(0));
	char ttl[255][255] = {};
	int stk[255] = {};
	char cvr[255][255] = {};
	int prc[255] = {};
	char id[255][255] = {};
	int index = 0;
	int input = 0;
    char idc[10] = {};
	
	do {
		puts("Buku Kita");
		puts("=================");
		puts("1. Create new book");
		puts("2. View all books");
		puts("3. Restock books");
		puts("4. Sell book");
		puts("5. Exit");
		printf(">> ");
		scanf("%d", &input);
		getchar();
		
		if(input == 1) {
			do {
				printf("Input book title: ");
				scanf("%[^\n]", ttl[index]);
				getchar();
			} while (strlen(ttl[index]) < 2 || strlen(ttl[index]) > 10);
			do {
				printf("Input book stock: ");
				scanf("%d", &stk[index]);
				getchar();
				fflush(stdin);
			} while (stk[index] < 1 || stk[index] > 50);
			do {
				printf("Input book cover: ");
				scanf("%s", cvr[index]);
				getchar();
			} while (strcmp(cvr[index], "Hard") != 0 && strcmp(cvr[index], "Soft") != 0);
			do {
				printf("Input book price: ");
				scanf("%d", &prc[index]);
				getchar();
			} while (prc[index] < 1000 || prc[index] > 10000);
			
			sprintf(id[index], "%c%d%d%d", cvr[index][0], rand()%10, rand()%10, rand()%10);
			
			index++;
		} else if (input == 2) {
			if (index == 0) {
				printf("error\n");
				printf("Press any key to continue..."); getchar();
			} else {
				printf("List of books: \n");
				puts("====================================================================");
				puts("| No. | Title            | Stock     | Cover | Price        | ID   |");
				puts("====================================================================");
				for (int i = 0; i < index; i++) {
					printf("| %-3d | %-16s | %-9d | %-5s | Rp.%-9d | %s |\n", i+1, ttl[i], stk[i], cvr[i], prc[i], id[i]);
				}
				puts("====================================================================");
				printf("Book count: %d\n", index);
				printf("Press any key to continue..."); getchar();
			}
		} else if (input == 3) {
			char idc[255] = {};
			
			if (index == 0) {
				puts("error\n");
				printf("Press any key to continue..."); getchar();
			} else {
				printf("List of books: \n");
				puts("====================================================================");
				puts("| No. | Title            | Stock     | Cover | Price        | ID   |");
				puts("====================================================================");
				for (int i = 0; i < index; i++) {
					printf("| %-3d | %-16s | %-9d | %-5s | Rp.%-9d | %s |\n", i+1, ttl[i], stk[i], cvr[i], prc[i], id[i]);
				}
				puts("====================================================================");
				printf("Book count: %d\n", index);
				
				int x = 0;
				do {
					x = 0;
					printf("Input book ID: ");
					scanf("%s", idc);
					getchar();
					for (int i = 0; i < index; i++) {
						if (strcmp(id[i], idc) == 0) {
							if (stk[i] == 50) {
								printf("Error\n");
								getchar();
								continue;
							} else {
								do {
									printf("Input book stock: ");
									scanf("%d", &stk[i]);
									getchar();
									x++;
								} while (stk[i] < 1 || stk[i] > 50);
							}
						}
					}
				} while (x == 0);	
			}
		} else if (input == 4) {
			if (index == 0) {
				puts("error\n");
				printf("Press any key to continue..."); getchar();
			} else {
				printf("List of books: \n");
				puts("====================================================================");
				puts("| No. | Title            | Stock     | Cover | Price        | ID   |");
				puts("====================================================================");
				for (int i = 0; i < index; i++) {
					printf("| %-3d | %-16s | %-9d | %-5s | Rp.%-9d | %s |\n", i+1, ttl[i], stk[i], cvr[i], prc[i], id[i]);
				}
				puts("====================================================================");
				printf("Book count: %d\n", index);
				
				int y = 0;
				int quan;
				do {
					y = 0;
					quan = 0;
					printf("Input book ID: ");
					scanf("%s", idc);
					getchar();
					for (int i = 0; i < index; i++) {
						if (strcmp(id[i], idc) == 0) {
							if (stk[i] == 0) {
								printf("Error\n");
								getchar();
								y++;
								continue;
							} else {
								do {
									printf("Input quantity: ");
									scanf("%d", &quan);
									getchar();
									y++;
								} while (quan < 1 || quan > stk[i]);
								stk[i] = stk[i] - quan;
							}
						}
					}
				} while (y == 0);	
			}
		} else if (input == 5) {
			printf("Thanks!");
		} else {
			puts("Input a valid number.");
			getchar();			
		}
	} while (input != 5);
	
	return 0;
}

