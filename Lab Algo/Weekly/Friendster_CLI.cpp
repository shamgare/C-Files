#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char user[5][100] = {"christ0208", "jordywa", "haku", "elior", "cleo"};
char name[5][100] = {"Christopher", "Jordy", "Haku", "Eleanor", "Cleo Deus"};
char mail[5][100] = {"chris@gmail.com", "jordy@gmail.com", "haku@gmail.com", "el@gmail.com", "cleo@gmail.com"};
int friendList[5];
int friendCount = 0;

int main()
{
	// system("cls");
	
	printf("Friendster CLI\n");
	printf("==============\n");

	int a;
	do {
		printf("1. Add New Friend\n");
		printf("2. Unfriend\n");
		printf("3. Exit\n");
		printf(">> "); scanf("%d", &a); getchar();
		
		if(a == 1) {
			char find[255];
			printf("Enter a keyword to search a friend [must not be empty]: ");
			scanf("%[^\n]", find); getchar();

			int resultCount = 0;
			int resultIndex[5];

			for (int i=0;i<5;i++) {
				if (strcmpi(user[i], find) == 0 || strstr(strlwr(name[i]), strlwr(find)) != NULL) {
					resultIndex[resultCount] = i;
					resultCount++;
					printf("%d. | %s | %s | %s |\n", resultCount, user[i], name[i], mail[i]);
				}
			}

			if (resultCount==1) {
				char x[4];
				printf("Do you want to add this user? [yes/no]: ");
				scanf("%s", x); getchar();
				if (strcmp("yes", x) == 0) {
					friendList[friendCount] = resultIndex[0];
					friendCount++;
				}
			}
			
			if(resultCount > 1) {
				int choice = 0;
				printf("Pick a number to add as your friend: ");
				scanf("%d", &choice); getchar();

				if (choice != 0) {
					friendList[friendCount] = resultIndex[choice-1];
					friendCount++;
				}
				
			}
		}

		if (a==2) {
			int choice = 0;
			for(int i = 0; i<friendCount; i++) {
				int index = friendList[i];
				printf("%d. | %s | %s | %s |\n", i+1, user[index], name[index], mail[index]);
			}

			printf("Pick a number to remove a friend [press 0 to exit]: ");
			scanf("%d", &choice); getchar();

			if (choice != 0) {
				for(int i = choice-1; i<friendCount-1;i++) {
					friendList[i] = friendList[i+1];
				}
				friendCount--;
			}
		}

		if (a==3) {
			printf("Thank you for using this app :D\n");
		}

	} while (a != 3);
	
	return 0;
}
