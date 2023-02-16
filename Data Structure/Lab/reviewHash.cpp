#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 26

struct Food {
    char name[100];
    int price;
    struct Food* next, * prev;
};

struct Table {
    struct Food* head, * tail;
} *table[SIZE];

int hashFunc(const char* name) {
    if (name[0] >= 'A' && name[0] <= 'Z') {
        return (name[0] - 65) % SIZE;
    }
    else if (name[0] >= 'a' && name[0] <= 'z') {
        return (name[0] - 97) % SIZE;
    }
    return name[0] % SIZE;
}

Food* createFood(const char* name, int price) {
    Food* temp = (Food*)malloc(sizeof(Food));
    strcpy(temp->name, name);
    temp->price = price;
    temp->next = temp->prev = 0;
    return temp;
}

void initializeTable() {
    for (int i = 0; i < SIZE; i++) {
        // pesen memori
        table[i] = (Table*)malloc(sizeof(Table));
        table[i]->head = table[i]->tail = 0;
    }
    return;
}

void pushHead(int key, Food* newFood) {
    if (!table[key]->head) {
        table[key]->head = table[key]->tail = newFood;
    }
    else {
        newFood->next = table[key]->head;
        table[key]->head->prev = newFood;
        table[key]->head = newFood;
    }
    return;
}

void pushTail(int key, Food* newFood) {
    if (!table[key]->head) {
        table[key]->head = table[key]->tail = newFood;
    }
    else {
        newFood->prev = table[key]->tail;
        table[key]->tail->next = newFood;
        table[key]->tail = newFood;
    }
    return;
}

void pushMid(int key, Food* newFood) {
    struct Food* curr = table[key]->head;

    while (curr && strcmp(newFood->name, curr->next->name) >= 0) {
        curr = curr->next;
    }

    newFood->next = curr->next;
    newFood->prev = curr;
    curr->next->prev = newFood;
    curr->next = newFood;
    return;
}

void insertFood(const char* name, int price) {
    int key = hashFunc(name);
    Food* newFood = createFood(name, price);

    if (!table[key]->head || strcmp(name, table[key]->head->name) < 0) {
        pushHead(key, newFood);
    }
    else if (strcmp(name, table[key]->tail->name) >= 0) {
        pushTail(key, newFood);
    }
    else {
        pushMid(key, newFood);
    }
}

void popHead(int key) {
    if (!table[key]->head) {
        return;
    }
    else if (table[key]->head == table[key]->tail) {
        free(table[key]->head); table[key]->head = table[key]->tail = 0;
    }
    else {
        Food* newHead = table[key]->head->next;
        newHead->prev = 0;
        free(table[key]->head);
        table[key]->head = newHead;
    }
}

void popTail(int key) {
    if (!table[key]->head) {
        return;
    }
    else if (table[key]->head == table[key]->tail) {
        free(table[key]->head); table[key]->head = table[key]->tail = 0;
    }
    else {
        Food* newTail = table[key]->tail->prev;
        newTail->next = 0;
        free(table[key]->tail);
        table[key]->tail = newTail;
    }
}

void popMid(int key, const char* name) {
    Food* curr = table[key]->head;
    while (curr && strcmp(name, curr->name) != 0) {
        curr = curr->next;
    }
    if (!curr) return;

    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    free(curr);
    return;
}

void deleteFood(const char* name) {
    int key = hashFunc(name);

    if (!table[key]->head) {
        return;
    }
    else if (strcmp(name, table[key]->head->name) == 0) {
        popHead(key);
    }
    else if (strcmp(name, table[key]->tail->name) == 0) {
        popTail(key);
    }
    else {
        popMid(key, name);
    }
}

void view() {
    for (int i = 0; i < SIZE; i++) {
        printf("%d\n", i + 1);
        struct Food* curr = table[i]->head;
        while (curr) {
            printf("\t%s %d\n", curr->name, curr->price);
            curr = curr->next;
        }
    }
}

int main()
{
    initializeTable();

    insertFood("Sate Padang", 29000);
    insertFood("Sop Jagung", 22000);
    insertFood("Sop Asparagus", 23000);
    insertFood("Sate Ayam", 2000);

    deleteFood("Sate Padang");
    view();
}