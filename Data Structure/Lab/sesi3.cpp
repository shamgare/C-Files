#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// double link list

typedef struct node {
    char name[100];
    int age;
    struct node* next;
    struct node* prev;
} node;

node* head = 0;
node* tail = 0;

void pushHead(char* name, int age)
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

void pushTail(char* name, int age)
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

void pushValue(char* name, int age)
{
    node* temp = (node*)malloc(sizeof(node));
    strcpy(temp->name, name);
    temp->age = age;
    temp->prev = temp->next = 0;
    
    if (!head || strcmp(temp->name, head->name) < 0) {
        pushHead(name, age);
    }
    else if (strcmp(temp->name, tail->name) >= 0) {
        pushTail(name, age);
    }
    else {
        node* curr = head;
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
        while (curr->next != 0 && strcmp(curr->name, name) != 0) {
            curr = curr->next;
        }
        
        if (curr->next == NULL) {
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

    while (curr != 0) {
        printf("%s %d\n", curr->name, curr->age);
        curr = curr->next;
    }
}

int main()
{
    char a[] = "Michael"; int age1 = 20;
    char b[] = "Darwin"; int age2 = 30;
    char c[] = "Franklin"; int age3 = 25;
    char d[] = "Erwin"; int age4 = 22;

    pushValue(a, age1);
    pushValue(b, age2);
    pushValue(c, age3);
    pushValue(d, age4);
    
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
