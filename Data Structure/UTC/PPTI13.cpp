#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define size 100

typedef struct node {
	char name[25];
	char type[10];
	char habitat[25];
	double price;
	struct node* next;
} node;

node* table[size];

node* createNode(char* name, char* type, char* habitat, double price) {
	node* temp = (node*)malloc(sizeof(node));
	strcpy(temp->name, name);
	strcpy(temp->type, type);
	strcpy(temp->habitat, habitat);
	temp->price = price;
	temp->next = 0;
	return temp;
}

int hash(char* name) {
	int sum = 0;
	for (int i = 0; i < strlen(name); i++) {
		sum += name[i];
	}
	return sum % size;
}

int view() {
	int j = 1;
	puts("=============================================================================================");
	puts("| No. | Shelf Idx | Type      | Name                | Habitat                 | $ Price ($) |");
	puts("=============================================================================================");
	for (int i = 0; i < size; i++) {
		if (table[i]) {
			node* curr = table[i];
			while (curr) {
				printf("| %02d. | Shelf %-3d | %-9s | %-19s | %-23s | $ %-9.2lf |\n", j++, i, curr->type, curr->name, curr->habitat, curr->price);
				curr = curr->next;
			}
		}
	}
	if (j == 1) {
		printf("No Data Yet!\n");
		puts("=============================================================================================");
		return 1;
	}
	puts("=============================================================================================");
	return 0;
}

void buyMenu() {
	char type[10];
	do {
		printf("Input creature type: ");
		scanf("%s", type); getchar();
	} while (strcmp(type, "Reptile") != 0 &&
		strcmp(type, "Fish") != 0 && strcmp(type, "Moss") != 0);

	char name[25];
	do {
		printf("Input creature name: ");
		scanf("%s", name); getchar();
	} while (strlen(name) < 5 || strlen(name) > 20);

	char habitat[25];
	do {
		printf("Input creature habitat: ");
		scanf("%[^\n]", habitat); getchar();
	} while (strcmp(" Terra", strrchr(habitat, ' ') ? strrchr(habitat, ' ') : "no") != 0);

	double price;
	do {
		printf("Input creature price: ");
		scanf("%lf", &price); getchar();
	} while (price < 1 || price > 10000);

	int key = hash(name);

	node* curr = table[key];
	node* neww = createNode(name, type, habitat, price);

	if (!curr) {
		table[key] = neww;
	}
	else if (strcmp(neww->name, curr->name) < 0) {
		neww->next = curr;
		table[key] = neww;
	}
	else {
		while (curr->next && strcmp(neww->name, curr->next->name) > 0) {
			curr = curr->next;
		}
		neww->next = curr->next;
		curr->next = neww;
	}

	puts("Successfully Added!");
	printf("Press enter to continue..."); getchar();
}

void sellMenu() {
	if (view() == 1) {
		printf("Press enter to continue..."); getchar();
		return;
	}

	char name[25];
	do {
		printf("Input creature name to sell: ");
		scanf("%s", name); getchar();
	} while (strlen(name) < 5 || strlen(name) > 20);

	int key = hash(name);
	node* curr = table[key];

	if (!curr) {
		printf("There are no Terrarium named %s in the list!\n", name);
	}
	else if (strcmp(curr->name, name) == 0 && !curr->next) {
		printf("%s has been sold!\n", name);
		free(table[key]); table[key] = 0;
	}
	else if (strcmp(curr->name, name) == 0) {
		table[key] = curr->next;
		printf("%s has been sold!\n", name);
		free(curr); curr = 0;
	}
	else {
		while (curr->next && strcmp(name, curr->next->name) != 0) {
			curr = curr->next;
		}
		if (!curr->next) {
			printf("There are no Terrarium named %s in the list!\n", name);
		}
		else {
			node* del = curr->next;
			curr->next = del->next;
			printf("%s has been sold!\n", name);
			free(del); del = 0;
		}
	}

	printf("Press enter to continue..."); getchar();
}

void updateMenu() {
	if (view() == 1) {
		printf("Press enter to continue..."); getchar();
		return;
	}

	char name[25];
	do {
		printf("Input creature name to sell: ");
		scanf("%s", name); getchar();
	} while (strlen(name) < 5 || strlen(name) > 20);

	int key = hash(name);
	node* curr = table[key];
	node* change;

	if (!curr) {
		printf("There are no Terrarium named %s in the list!\n", name);
		printf("Press enter to continue..."); getchar();
		return;
	}
	else if (strcmp(curr->name, name) == 0) {
		change = curr;
	}
	else {
		while (curr->next && strcmp(name, curr->next->name) != 0) {
			curr = curr->next;
		}
		if (!curr->next) {
			printf("There are no Terrarium named %s in the list!\n", name);
			printf("Press enter to continue..."); getchar();
			return;
		}
		else {
			change = curr->next;
		}
	}

	double price;
	do {
		printf("Input creature price: ");
		scanf("%lf", &price); getchar();
	} while (price < 1 || price > 10000);

	change->price = price;

	printf("%s price has been updated!\n", change->name);
	printf("Press enter to continue..."); getchar();
}

int main()
{
	int input = 0;
	do {
		puts("================================");
		puts("| Blitz Terrarium              |");
		puts("================================");
		puts("| 1. Buy New Terrarium         |");
		puts("| 2. Sell Terrarium            |");
		puts("| 3. Update Terrarium Price    |");
		puts("| 4. Exit                      |");
		puts("================================");
		printf("Choose: "); scanf("%d", &input); fflush(stdin);

		if (input == 1) {
			buyMenu();
		}
		else if (input == 2) {
			sellMenu();
		}
		else if (input == 3) {
			updateMenu();
		}
		else if (input == 4) {
			puts("Bye Bye!");
		}
		else {
			printf("Please input a valid number!\n");
			printf("Press enter to continue..."); getchar();
		}
	} while (input != 4);
}
