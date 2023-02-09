#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// double link list

struct node {
    char name[100];
    int age;
    struct node* next;
    struct node* prev;
};

node* head = 0;
node* tail = 0;

void pushHead(const char* name, int age)
{
    node* temp = (node*)malloc(sizeof(node));
    strcpy(temp->name, name);
    temp->age = age;
    temp->prev = temp->next = 0;

    if (head == 0) {
        head = tail = temp;
    }
    else {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void pushTail(const char* name, int age)
{
    node* temp = (node*)malloc(sizeof(node));
    strcpy(temp->name, name);
    temp->age = age;
    temp->prev = temp->next = 0;

    if (head == 0) {
        head = tail = temp;
    }
    else {
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
}

void pushValue(node** head, node** tail, const char* name, int age)
{
    node* temp = (node*)malloc(sizeof(node));
    strcpy(temp->name, name);
    temp->age = age;
    temp->prev = temp->next = 0;
    
    if (!(*head) || strcmp(temp->name, (*head)->name) < 0) {
        pushHead(name, age);
    }
    else if (strcmp(temp->name, (*tail)->name) >= 0) {
        pushTail(name, age);
    }
    else {
        node* curr = *head;
        while (strcmp(temp->name, curr->next->name) >= 0) {
            curr = curr->next;
        }
        temp->next = curr->next;
        curr->next->prev = temp;
        curr->next = temp;
        temp->prev = curr;
    }
}

void popHead()
{
    if (!head) {
        return;
    }
    else if (head == tail) {
        free(head);
        head = tail = 0;
    }
    else {
        head = head->next;
        free(head->prev);
        head->prev = 0;
    }
}

void popTail()
{
    if (!tail) {
        return;
    }
    else if (head == tail) {
        free(tail);
        head = tail = 0;
    }
    else {
        tail = tail->prev;
        free(tail->next);
        tail->next = 0;
    }
}

void popValue(const char* name)
{
    if (!head) return;
    
    if (strcmp(name, head->name) == 0) {
        popHead();
    }
    else if (strcmp(name, tail->name) == 0) {
        popTail();
    }
    else {
        node* curr = head;
        while (curr->next && strcmp(curr->name, name) != 0) {
            curr = curr->next;
        }
        
        if (!curr->next) {
            printf("Not Found\n");
            return;
        }
        else {
            curr->next->prev = curr->prev;
            curr->prev->next = curr->next;
            free(curr);
            curr = 0;
        }
    }
}

void view()
{
    node* curr = head;

    while (curr) {
        printf("%s %d\n", curr->name, curr->age);
        curr = curr->next;
    }
}

int main()
{
    node* head = 0;
    node* tail = 0;

    pushValue(&head, &tail, "Michael", 20);
    pushValue(&head, &tail, "Darwin", 30);
    pushValue(&head, &tail, "Franklin", 32);
    pushValue(&head, &tail, "Erwin", 20);
    
    popValue("Darwin");

    view();
}

/*

void pushHead(node** head, node** tail, char* name, int age)
{
    node* temp = (node*)malloc(sizeof(node));
    strcpy(temp->name, name);
    temp->age = age;
    temp->prev = temp->next = 0;

    if (*head == 0) {
        *head = *tail = 0;
    } else {
        (*head)->prev = temp;
        temp->next = *head;
        *head = temp;
    }
}

int main()
{
    node* head = 0;
    node* tail = 0;

    pushValue(&head, &tail, name, age)
}

void pushValue(node** head, node** tail, char* name, int age)
{
    node* temp = (node*)malloc(sizeof(node));
    strcpy(temp->name, name);
    temp->age = age;
    temp->prev = temp->next = 0;

    if (!*head || strcmp(temp->name, (*head)->name) < 0) {
        pushHead(head, tail, name, age);
    } else if (strcmp(temp->name, (*tail)->name) >= 0) {
        pushTail(head, tail, name, age);
    } else {
        node* curr = *head;
        while(strcmp(temp->name, curr->next->name) >= 0) {
            curr = curr->next;
        }
        temp->next = curr->next;
        curr->next->prev = temp;
        curr->next = temp;
        temp->prev = curr;
    }
}

*/
