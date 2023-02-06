#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int size = 26;

struct Node {
    int val;
    char name[200];
} *table[size];

int func(const char* name)
{
    // char a = name[0];
    // char b = name[strlen(name) - 1];

    // return (a + b) % size;
    
    char c = name[0];
    if (c >= 'A' && c <= 'Z') {
        return c - 'A';
    }
    else if (c >= 'a' && c <= 'z') {
        return c - 'a';
    }
    return c % size;
}

void insert(const char* name)
{
    struct Node* temp = (Node*)malloc(sizeof(Node));
    strcpy(temp->name, name);
    temp->val = 0;

    int key = func(name);

    if (!table[key]) {
        table[key] = temp;
    }
    else {
        int curr = key + 1;
        while (curr != key && table[curr]) {
            curr = (curr + 1) % size;
        }
        if (curr == key) {
            printf("Table FULL\n");
            return;
        }
        table[curr] = temp;
    }
}

void view()
{
    for (int i = 0; i < 30; i++) {
        if (table[i]) printf("%d. %s\n", i, table[i]->name);
        else printf("-\n");
    }
}

void deleteNode(const char* name)
{
    int key = func(name);
    int curr = key + 1;


    if (table[key] && strcmp(table[key]->name, name) == 0) {
        free(table[key]);
        table[key] = NULL;
        return;
    }

    
    while (curr != key && (!table[curr] || strcmp(table[curr]->name, name) != 0)) {
        curr = (curr + 1) % size;
    }
    
    if (curr == key) {
        printf("%s Not Found\n", name);
        printf("%d %d\n", curr, key);
        return;
    }

    free(table[curr]);
    table[curr] = NULL;
}

int main()
{
    insert("Ozaka");
    insert("Azaka");
    // insert("Sazaka");
    // insert("Mizaka");
    // insert("Kozaka");
    // insert("Lazaka");
    // insert("Lozaka");

    // for (int i = 0; i < 30; i++) {
    //     char name[200];
    //     sprintf(name, "budei");
    //     insert(name);
    // }

    // view();

    deleteNode("Ozaka");
    deleteNode("Azaka");
    deleteNode("Aaka");
    // deleteNode("Sazaka");
    // // deleteNode("Mizaka");
    // deleteNode("Kozaka");
    // deleteNode("Lazaka");
    // deleteNode("Lozaka");
    
    view();
}