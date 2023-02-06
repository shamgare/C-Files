#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int SIZE = 26;

struct Node {
	char name[101];
	int age;
	Node *next, *prev;
};

struct Row {
	Node *head, *tail;
} *table[SIZE];

struct Row *createRow()
{
	Row *row = (Row*)malloc(sizeof(Row));
	row->head = row->tail = NULL;
	return row;
}

struct Node *createNode(const char *name, int age)
{
	Node *node = (Node*)malloc(sizeof(Node));
	strcpy(node->name, name);
	node->age = age;
	node->next = node->prev = NULL;
	return node;
}

int hash(const char *name)
{
	char c = name[0];
	if (c >= 'A' && c <= 'Z') {
		return c - 'A';
	}
	else if (c >= 'a' && c <= 'z') {
		return c - 'a';
	}
	return c % SIZE;
}

void view()
{
	for (int i = 0; i < SIZE; i++) {
		Row *row = table[i];
		if (row) {
			Node *curr = row->head;
			while(curr)
			{
				printf("%d. %s - %d --> ", i, curr->name, curr->age);
				curr = curr->next;
			}
			printf("\n");
		
		}
		else {
			printf("-\n");
		}
	}
}

void deleteNode(const char *name)
{
    int key = hash(name);
    
    if (!table[key]) {
        printf("Not Found\n");
        return;
    }
    if (strcmp(table[key]->head->name, name) == 0) {
        if (table[key]->head == table[key]->tail) {
            free(table[key]->head);
            table[key]->head = table[key]->tail = NULL;
            free(table[key]);
            table[key] = NULL;
        }
        else {
            Node *temp = table[key]->head;
            table[key]->head = table[key]->head->next;
            table[key]->head->prev = NULL;
            free(temp);
            temp = NULL;
        }
    }
    else if (strcmp(table[key]->tail->name, name) == 0) {
        Node *temp = table[key]->tail;
        table[key]->tail = table[key]->tail->prev;
        table[key]->tail->next = NULL;
        free(temp);
        temp = NULL;
    }
    else {
        Node *curr = table[key]->head;
        while (strcmp(curr->name, name) != 0 && curr != table[key]->tail) {
            curr = curr->next;
        }
        if (curr == table[key]->tail) {
            printf("Data not found\n");
            return;
        }
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        free(curr);
        curr = NULL;
    }
}

void insertNode(const char *name, int age)
{
	int key = hash(name);
	
	if(!table[key])
	{
		// laci tak ada, data tidak ada
		table[key] = createRow();
		table[key]->head = table[key]->tail = createNode(name, age);
		return;
	}

	// push tail
	Node *node = createNode(name,age);
	table[key]->tail->next = node;
	node->prev = table[key]->tail;
	table[key]->tail = node;
}

int main()
{
	insertNode("budi", 20);
	insertNode("clara", 18);
	insertNode("abel", 15);
	insertNode("abdul", 15);
	insertNode("albert", 15);
	insertNode("andre", 15);
	insertNode("bjox", 15);
	
	deleteNode("clara");
	deleteNode("abdul");
	deleteNode("budi");
	deleteNode("abel");
	deleteNode("budiman");

	view();
}