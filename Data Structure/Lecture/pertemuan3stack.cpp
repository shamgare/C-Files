#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// stack

typedef struct data {
    char name[20];
    int age;
    struct data* next;
} data;

data* head = 0;

void push(char* name, int age)
{
    data* temp = (data*)malloc(sizeof(data));
    temp->age = age;
    strcpy(temp->name, name);
    temp->next = 0;

    if (head == 0) {
        head = temp;
    }
    else {
        temp->next = head;
        head = temp;
    }
}

void popHead()
{
    if (head == 0) {
        printf("stack is empty\n");
    }
    else {
        data* del = head;
        head = head->next;
        free(del);
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
    char a[] = "albert";
    char b[] = "beni";
    char c[] = "chandra";
    
    push(a, 32);
    push(b, 40);
    push(c, 21);
    
    // display();
    
    popHead();

    display();
    
    return 0;
}
