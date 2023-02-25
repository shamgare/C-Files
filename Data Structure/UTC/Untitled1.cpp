#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
	char name[200];
	struct node* left, * right;
} node;

node* root = 0;

node* createNode(char* name) {
	node* temp = (node*)malloc(sizeof(node));
	strcpy(temp->name, name);
}
int main()
{
	root = insertNode(root, createNode("Aaron"));
}
