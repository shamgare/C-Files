#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

int main()
{
	int input;
	int index;
	char fla[255][255] = {};
	int stk[255] = {};
	char typ[255][255] = {};
	int prc[255] = {};
	char id[255][255] = {};
	char idc[255] = {};
	char idsell[255] = {};
	
	do {
		puts("Ice Cream Stand");
		puts("===============");
		puts("1. Create");
		puts("2. View");
		puts("3. Restock");
		puts("4. Sell");
		puts("5. Exit");
		printf(">> "); scanf("%d", &input); getchar();
		
		if (input == 1) {
			do {
				printf("Input flavor: ");
				scanf("%[^\n]", fla[index]);
				getchar();
			} while (strlen(fla[index]) < 3 || strlen(fla[index]) > 20);
			
			do {
				printf("Input stock: ");
				scanf("%d", &stk[index]);
				getchar();
				fflush(stdin);
			} while (stk[index] < 1 || stk[index] > 100);
			
			do {
				printf("Input type: ");
				scanf("%s", typ[index]);
				getchar();
			} while (strcmp(typ[index], "Cone") != 0 && strcmp(typ[index], "Stick") != 0);
			
			do {
				printf("Input price: ");
				scanf("%d", &prc[index]);
				getchar();
				fflush(stdin);
			} while (prc[index] < 1000 || prc[index] > 20000);
			
			sprintf(id[index],"%c%c%d%d%d", typ[index][0], typ[index][1] - 32, rand()%10, rand()%10, rand()%10);
			printf("Ice Cream ID: %s\n", id[index]);
			index++;
			printf("Creation successful!\n");
			printf("Current ice cream: %d\n", index);
			printf("Press enter to continue...."); getchar();
			
		} else if (input == 2) {
			if (input == 0) {
				printf("No ice creams yet...\n");
				printf("Press enter to continue..."); getchar();
			} else {
				puts("===========================================================");
				puts("| ID    | Flavour          | Type    | Stock  | Price     |");
				puts("===========================================================");
				for (int i = 0; i< index; i++) {
					printf("| %-5s | %-16s | %-7s | %-6d | Rp.%-6d |\n", id[i], fla[i], typ[i], stk[i], prc[i]);
				}
				puts("===========================================================");
				printf("Press enter to continue..."); getchar();
			}
		} else if (input == 3) {
			if (input == 0) {
				printf("No ice creams yet...\n");
				printf("Press enter to continue..."); getchar();
			} else {
				puts("===========================================================");
				puts("| ID    | Flavour          | Type    | Stock  | Price     |");
				puts("===========================================================");
				for (int i = 0; i< index; i++) {
					printf("| %-5s | %-16s | %-7s | %-6d | Rp.%-6d |\n", id[i], fla[i], typ[i], stk[i], prc[i]);
				}
				puts("===========================================================");
				
				int x;
				do {
					x = 0;
					printf("Input ID: ");
					scanf("%s", idc);
					getchar();
					for (int i = 0; i < index; i++) {
						if (strcmp(id[i], idc) == 0) {
							if (stk[i] == 100) {
								printf("Stock is full.\n");
								getchar();
								x++;
								continue;
							} else {
								do {
									printf("Input stock: ");
									scanf("%d", &stk[i]);
									getchar();
									fflush(stdin);
									x++;
								} while (stk[i] < 1 || stk[i] > 100);
							}
						}
					}
				} while (x == 0);
			}
		} else if (input == 4) {
			if (input == 0) {
				printf("No ice creams yet...\n");
				printf("Press enter to continue..."); getchar();
			} else {
				puts("===========================================================");
				puts("| ID    | Flavour          | Type    | Stock  | Price     |");
				puts("===========================================================");
				for (int i = 0; i< index; i++) {
					printf("| %-5s | %-16s | %-7s | %-6d | Rp.%-6d |\n", id[i], fla[i], typ[i], stk[i], prc[i]);
				}
				puts("===========================================================");
				
				int y;
				int quan;
				do {
					y = 0;
					quan = 0;
					printf("Input ID: ");
					scanf("%s", idsell);
					getchar();
					for (int i = 0; i < index; i++) {
						if (strcmp(id[i], idsell) == 0) {
							if (stk[i] == 0) {
								printf("Stock is empty.\n");
								getchar();
								y++;
								continue;
							} else {
								do {
									printf("Input quantity: ");
									scanf("%d", &quan);
									getchar();
									fflush(stdin);
									y++;
								} while (quan < 1 || quan > stk[i]);
								stk[i] = stk[i] - quan;
								printf("Successful Sell!\n");
								printf("Press enter to continue....");
								getchar();
							}
						}
					}
				} while (y == 0);
			}
		} else if (input == 5) {
			printf("thanks!\n");
			getchar();
		} else {
			printf("pls input a valid number\n");
			getchar();
			continue;
		}
	} while (input != 5);
	return 0;
}
