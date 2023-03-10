#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// queue

typedef struct data {
    char name[20];
    int age;
    struct data* next;
} data;

data* head = 0;
data* tail = 0;

void pushTail(const char* name, int age)
{
    data* temp = (data*)malloc(sizeof(data));
    temp->age = age;
    strcpy(temp->name, name);
    temp->next = 0;

    if (tail == 0) {
        head = tail = temp;
    }
    else {
        tail->next = temp;
        tail = temp;
    }
}

void popHead()
{
    if (head == 0) {
        printf("empty");
    }
    else {
        data* curr = head;
        head = head->next;
        free(curr);
    }
}

void display()
{
    data* curr = head;

    while (curr != 0) {
        printf("%s %d\n", curr->name, curr->age);
        curr = curr->next;
    }
}

int main()
{
    pushTail("jul", 30);
    pushTail("julius", 25);
    pushTail("julian", 22);

    popHead();

    display();

    return 0;
}