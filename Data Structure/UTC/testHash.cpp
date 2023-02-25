#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define size 26
typedef struct node {
	char name[30];
	struct node* next;
} node;

node *table[size] = 0;

node* createNode(char* name) {
	node* temp = (node*)malloc(sizeof(node));
	strcpy(temp->name, name);
	temp->next = 0;
	return temp;
}

int hash(char* name) {
	return name[0] % size;
}

void insertNode(char* name) {
	int key = hash(name);
	
	node* neww = createNode(name);
	node* curr = table[key];
	
	if (!table[key]) {
		table[key] = neww;
	} else if (strcmp(neww->name, curr->name) < 0) {
		neww->next = curr;
		table[key] = neww;
	} else {
		while (curr->next && strcmp(neww->name, curr->next->name) > 0) {
			curr = curr->next;
		}
		neww->next = curr->next;
		curr->next = neww;
	}
}

void deleteNode(char* name) {
	int key = hash(name);
	
	node* curr = table[key];
	
	if (!table[key]) {
		printf("No Data.\n");
	} else if (strcmp(name, curr->name) == 0 && !curr->next) {
		free(table[key]); table[key] = 0;
	} else if (strcmp(name, curr->name) == 0 && curr->next) {
		table[key] = curr->next;
		free(curr); curr = 0;
	} else {
		while (curr->next && strcmp(name, curr->name) != 0) {
			curr = curr->next;
		}
		if (!curr->next) {
			printf("No Data.\n");
		} else {
			node* del = curr->next;
			node* b = curr->next->next;
			
			curr->next = b;
			free(del); del = 0;
		}
	}
}

int main()
{
	
}
