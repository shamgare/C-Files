#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

int main()
{
	int input;
	char cake[255][255] = {};
	char fla[255][255] = {};
	int quan[255] = {};
	char desc[255][255] = {};
	int index = 0;
	do {
		puts("Cake Shop");
		puts("==============");
		if (index == 0) {
			printf(">> No cake found! :(\n");
		} else {
			puts("==========================================================================================");
			puts("| No. | Cake                | Flavour       | Quantity | Description                     |");
			puts("==========================================================================================");
			for (int i = 0; i < index; i++) {
				printf("| %-3d | %-19s | %-13s | %-8d | %-31s |\n", i+1, cake[i], fla[i], quan[i], desc[i]);
			}
			puts("==========================================================================================");
		}
		printf("\n");
		puts("1. Add cake");
		puts("2. Update cake");
		puts("3. Delete cake");
		puts("4. Exit");
		printf(">> ");
		scanf("%d", &input);
		getchar();
		
		if (input == 1) {
			int x;
			do {
				x = 0;
				printf("Input cake name: ");
				scanf("%[^\n]", cake[index]);
				getchar();
				
				int i = strlen(cake[index]) - 1;
				char kue[]="ekac";
				char kue2[]="cake";
//				if (cake[index][i] != 'e') x++;
//				if (cake[index][i-1] != 'k') x++;
//				if (cake[index][i-2] != 'a') x++;
//				if (cake[index][i-3] != 'c') x++;

//				for(int j=i;j>=i-3;j--)
//				{
//					if(cake[index][j] != kue[i-j])
//					x++;
//				}

				for(int j=i;j>=i-3;j--)
				{
					if(cake[index][j] != kue2[3+(j-i)])
					x++;
				}
			} while (strlen(cake[index]) == 0 || x != 0);
			
			do {
				printf("Input flavour: ");
				scanf("%[^\n]", fla[index]);
				getchar();
			} while (strcmp(fla[index], "Chocolate") != 0 && strcmp(fla[index], "Red Velvet") != 0);
			
			do {
				printf("Input quantity: ");
				scanf("%d", &quan[index]);
				getchar();
				fflush(stdin);
			} while (quan[index] < 1 || quan[index] > 10);
			
			char deskripsi[] = "This cake is";
			int y = 0;
			do {
				y = 0;
				printf("Input description: ");
				scanf("%[^\n]", desc[index]);
				getchar();
				
				for (int i = 0; i<12; i++) {
					if (desc[index][i] != deskripsi[i]) y++;
				}
			} while (y != 0);
			index++;
			
		} else if (input == 2) {
			int num;
			if (index == 0) {
				printf("Please add a cake first!\n");
				getchar();
				continue;
			} else {
				do {
					printf("Input a number: ");
					scanf("%d", &num);
					getchar();
				} while (num < 1 || num > index);
				
				int x;
				do {
					x = 0;
					printf("Input cake name: ");
					scanf("%[^\n]", cake[num-1]);
					getchar();
					
					int i = strlen(cake[num-1]) - 1;
					char kue2[]="cake";
					
					for(int j=i;j>=i-3;j--)
					{
						if(cake[num-1][j] != kue2[3+(j-i)])
						x++;
					}
				} while (strlen(cake[num-1]) == 0 || x != 0 || strlen(cake[num-1]) > 10);
				
				do {
					printf("Input flavour: ");
					scanf("%[^\n]", fla[num-1]);
					getchar();
				} while (strcmp(fla[num-1], "Chocolate") != 0 && strcmp(fla[num-1], "Red Velvet") != 0);
				
				do {
					printf("Input quantity: ");
					scanf("%d", &quan[num-1]);
					getchar();
				} while (quan[num-1] < 1 || quan[num-1] > 10);
				
				int y;
				char deskripsi[] = "This cake is";
				
				do {
					y = 0;
					printf("Input description: ");
					scanf("%[^\n]", desc[num-1]);
					getchar();
					
					for (int i = 0; i<12; i++) {
						if (desc[num-1][i] != deskripsi[i]) y++;
					}
				} while (y != 0);
			}
		} else if (input == 3) {
			int choice;
			if (index == 0) {
				printf("Please add a cake first!\n");
				getchar();
				continue;
			} else {
				do {
					printf("Input a number: ");
					scanf("%d", &choice);
					getchar();
				} while (choice < 1 || choice > index);
				
				for (int i = choice-1; i < index-1; i++) {
					strcpy(cake[i], cake[i+1]);
					strcpy(fla[i], fla[i+1]);
					strcpy(desc[i], desc[i+1]);
				}
				for (int j = choice-1; j < index; j++) {
					quan[j] = quan[j+1];
				}
				index--;
			}
		} else if (input == 4) {
			printf("Thanks!\n");
			getchar();
		} else {
			printf("Please input a valid number!\n");
			getchar();
			continue;
		}
	} while (input != 4);
}
