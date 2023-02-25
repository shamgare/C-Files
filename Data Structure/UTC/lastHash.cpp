#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#define size 26

typedef struct node {
    char name[200];
    struct node* next;
} node;

node* table[size];

int hash(char* name) {
    return ((name[0] + name[strlen(name) - 1]) % size);
}

node* createNode(char* name) {
    node* temp = (node*)malloc(sizeof(node));
    strcpy(temp->name, name);
    temp->next = 0;
    return temp;
}

void insertNode(char* name) {
    int key = hash(name);
    node* curr = table[key];
    node* neww = createNode(name);

    if (!curr) {
        table[key] = neww;
    }
    else if (strcmp(name, curr->name) < 0) {
        neww->next = curr;
        table[key] = neww;
    }
    else {
        while (curr->next && strcmp(name, curr->name) >= 0) {
            curr = curr->next;
        }
        neww->next = curr->next;
        curr->next = neww;
    }
}

void deleteNode(char* name) {
    int key = hash(name);
    node* curr = table[key];

    if (!curr) {
        printf("Not Found!\n");
    }
    else if (strcmp(name, curr->name) == 0 && !curr->next) {
        free(table[key]); table[key] = 0;
    }
    else if (strcmp(name, curr->name) == 0) {
        table[key] = curr->next;
        free(curr); curr = 0;
    }
    else {
        while (curr->next && strcmp(name, curr->next->name) != 0) {
            curr = curr->next;
        }
        if (!curr->next) {
            printf("Not Found!\n");
        }
        else {
            node* del = curr->next;
            curr->next = del->next;
            free(del); del = 0;
        }
    }
}

node* searchName(char* name) {
    for (int i = 0; i < size; i++) {
        if (table[i]) {
            node* curr = table[i];
            while (curr) {
                if (strcmp(name, curr->name) == 0) return curr;
                curr = curr->next;
            }
        }
    }
    return 0;
}

int main()
{

}