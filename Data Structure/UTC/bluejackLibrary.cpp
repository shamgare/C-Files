#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define size 1007

typedef struct node {
	char title[55];
	char name[30];
	char isbn[15];
	int page;
	char id[40];
	struct node* next;
} node;

node* table[size];
int bookCount = 0;

node* createNode(char* title, char* name, char* isbn, int page, char* id) {
	node* temp = (node*)malloc(sizeof(node));
	strcpy(temp->id, id);
	strcpy(temp->name, name);
	strcpy(temp->title, title);
	strcpy(temp->isbn, isbn);
	temp->page = page;
	temp->next = 0;
	return temp;
}

int isNumeric(char* name) {
	int len = strlen(name);
	for (int i = 0; i < len; i++) {
		if (name[i] < '0' || name[i] > '9') return -1;
	}
	return 1;
}

int isAlphabet(char* name) {
	int len = strlen(name);
	for (int i = 0; i < len; i++) {
		if (!(name[i] >= 'a' && name[i] <= 'z') && !(name[i] >= 'A' && name[i] <= 'Z')) return -1;
	}
	return 1;
}

int hash(char* id) {
	int sum = 0;
	for (int i = 0; i < strlen(id); i++) {
		sum += id[i];
	}
	return sum % size;
}

int searchTitle(char* title) {
	for (int i = 0; i < size; i++) {
		if (table[i]) {
			node* curr = table[i];
			while (curr) {
				if (strcmp(title, curr->title) == 0) return i;
				curr = curr->next;
			}
		}
	}
	return -1;
}

node* searchId(char* id) {
	for (int i = 0; i < size; i++) {
		if (table[i]) {
			node* curr = table[i];
			while (curr) {
				if (strcmp(id, curr->id) == 0) return curr;
				curr = curr->next;
			}
		}
	}
	return 0;
}

void viewMenu() {
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (!table[i]) count++;
	}
	if (count == size) {
		printf("There is no book(s) !\n");
	}
	else {
		puts("================================================================================================================================");
		puts("| Book ID                  | Book Title                             | Book Author             | ISBN             | Page Number |");
		puts("================================================================================================================================");

		for (int i = 0; i < size; i++) {
			if (table[i]) {
				node* curr = table[i];
				while (curr) {
					printf("| %-24s | %-38s | %-23s | %-16s | %-11d |\n", curr->id, curr->title, curr->name, curr->isbn, curr->page);
					puts("================================================================================================================================");
					curr = curr->next;
				}
			}
		}
	}
}

void insertMenu() {
	char title[55];
	do {
		printf("Enter title [5-50 chars][unique]: ");
		scanf("%[^\n]", title); getchar();
	} while (searchTitle(title) != -1 || strlen(title) < 5 || strlen(title) > 50);

	char name[30];
	do {
		printf("Enter name [25 chars][Mr. | Mrs. ]: ");
		scanf("%[^\n]", name); getchar();
	} while (strncmp(name, "Mr. ", 4) != 0 && strncmp(name, "Mrs. ", 5) != 0 || strlen(name) > 25);

	char isbn[15];
	do {
		printf("Enter ISBN [10-13 digits]: ");
		scanf("%s", isbn); getchar();
	} while (isNumeric(isbn) == -1 || strlen(isbn) < 10 || strlen(isbn) > 13);

	int page;
	do {
		printf("Enter page number [>= 16]: ");
		scanf("%d", &page); getchar();
	} while (page < 16);

	char id[40];
	sprintf(id, "B%05d-%s-%c%c", ++bookCount, isbn, toupper(title[0]), toupper(name[0]));

	int key = hash(id);
	node* curr = table[key];
	node* neww = createNode(title, name, isbn, page, id);

	if (!table[key]) {
		table[key] = neww;
	}
	else {
		while (curr->next) {
			curr = curr->next;
		}
		curr->next = neww;
	}

	printf("Insert Success!\n");
}

void removeMenu() {
	viewMenu();

	char id[40];
	printf("Input book ID to remove: ");
	scanf("%s", id); getchar();

	node* del = searchId(id);

	if (!del) {
		printf("Book Not Found!\n");
		return;
	}
	else {
		printf("Book ID: %s\n", del->id);
		printf("Book Title: %s\n", del->title);
		printf("Book Author: %s\n", del->name);
		printf("Book ISBN: %s\n", del->isbn);
		printf("Page Number: %d\n", del->page);

		char yn;
		do {
			printf("Are you sure [y|n]?: ");
			scanf("%c", &yn); getchar();
		} while (yn != 'y' && yn != 'n');

		if (yn == 'y') {
			int key = hash(del->id);
			node* curr = table[key];

			if (strcmp(curr->id, del->id) == 0) {
				table[key] = curr->next;
				free(del); del = 0;
			}
			else {
				while (curr->next != del) {
					curr = curr->next;
				}
				curr->next = del->next;
				free(del); del = 0;
			}

			printf("Delete Successful!\n");
		}
		else {
			printf("Canceled Delete!\n");
		}
	}
}

int main()
{
	int input = 0;
	do {
		puts("Bluejack Library");
		puts("======================");
		puts("1. View Book");
		puts("2. Insert Book");
		puts("3. Remove Book");
		puts("4. Exit");
		printf(">> "); scanf("%d", &input); fflush(stdin);

		switch (input) {
		case 1:
			viewMenu();
			puts("");
			printf("Press enter to continue..."); getchar();
			break;
		case 2:
			insertMenu();
			printf("Press enter to continue..."); getchar();
			break;
		case 3:
			removeMenu();
			printf("Press enter to continue..."); getchar();
			break;
		case 4:
			printf("Bye Bye!\n");
			break;
		default:
			printf("Please enter a valid number!\n");
			printf("Press enter to continue..."); getchar();
			break;
		}
	} while (input != 4);
}
