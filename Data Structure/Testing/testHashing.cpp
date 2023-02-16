#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define size 26

struct node {
    char name[200];
    struct node* next;
} *table[size];

int hash(const char* name) {
    if (name[0] >= 'a' && name[0] <= 'z') {
        return (name[0] - 'a') % size;
    }
    else if (name[0] >= 'A' && name[0] <= 'Z') {
        return (name[0] - 'A') % size;
    }
    return name[0] % size;
}

struct node* createNode(const char* name) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    strcpy(temp->name, name);
    temp->next = 0;
    return temp;
}

void insertNode(const char* name) {
    int key = hash(name);

    struct node* curr = table[key];
    struct node* neww = createNode(name);

    if (!table[key]) {
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

void view() {
    for (int i = 0; i < size; i++) {
        printf("%d.\n", i + 1);
        struct node* curr = table[i];
        while (curr) {
            printf("%s -> ", curr->name);
            curr = curr->next;
        }
        printf("\n");
    }
}

void search(const char* name) {
    int key = hash(name);
    struct node* curr = table[key];

    if (!curr) {
        printf("Not Found!\n");
    }
    else if (strcmp(name, curr->name) == 0) {
        printf("%s found!\n", curr->next->name);
    }
    else {
        while (curr->next && strcmp(name, curr->next->name) != 0) {
            curr = curr->next;
        }
        if (!curr->next) {
            printf("Not Found!\n");
            return;
        }
        printf("%s found!\n", curr->next->name);
    }
}

int main()
{
    insertNode("Shamgar");
    insertNode("Satmika");
    insertNode("Stephen");
    insertNode("Rodney");
    insertNode("Ferren");
    insertNode("Jacky");

    search("Joki");
    search("Shamgar");

    view();
}