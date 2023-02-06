#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// hash table
const int SIZE = 26;

struct Node {
    char name[101];
    int age;
} *table[SIZE];

struct Node* createNode(const char* name, int age) {
    Node* temp = (Node*)malloc(sizeof(Node));
    strcpy(temp->name, name);
    temp->age = age;
    return temp;
}

int hashFunc(const char* name)
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

void insertNode(const char* name, int age)
{
    int key = hashFunc(name);
    
    if (!table[key]) {
        table[key] = createNode(name, age);
        return;
    }

    int curr = key + 1;
    
    while (key != curr && table[curr]) {
        curr = (curr + 1) % SIZE;
    }

    if (curr == key) {
        printf("Table Full\n");
        return;
    }
    
    table[curr] = createNode(name, age);
}

void deleteNode(const char* name)
{
    int key = hashFunc(name);

    if (table[key] && strcmp(table[key]->name, name) == 0) {
        free(table[key]);
        table[key] = NULL;
        return;
    }

    int curr = key + 1;
    
    while (curr != key && (!table[curr] || strcmp(table[curr]->name, name) != 0)) {
        curr = (curr + 1) % SIZE;
    }

    // printf("%d %d\n", curr, key);
    if (key == curr) {
        printf("%s Not Found!\n", name);
        return;
    }

    free(table[curr]);
    
    table[curr] = NULL;
}

void view()
{
    for (int i = 0; i < SIZE; i++) {
        Node* curr = table[i];
        if (curr) {
            printf("%d. %s - %d\n", i, curr->name, curr->age);
        }
        else {
            printf("-\n");
        }
    }
}

int main()
{
    insertNode("budi", 90);
    insertNode("clara", 90);
    insertNode("abel", 90);
    insertNode("abdul", 90);

    deleteNode("clara");
    deleteNode("budi");
    deleteNode("abdul");
    deleteNode("abel");
    deleteNode("abdula");
    
    view();
    return 0;
}