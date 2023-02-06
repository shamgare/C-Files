#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data {
    char name[20];
    char nim[5];
    float gpa;
    struct data* next;
} data;

data* head = 0;
data* tail = 0;

void push(char* name, char* nim, float gpa)
{
    // priority GPA
    data* temp = (data*)malloc(sizeof(data));
    temp->gpa = gpa;
    strcpy(temp->name, name);
    strcpy(temp->nim, nim);
    temp->next = 0;

    // if LL empty
    if (head == 0) {
        head = tail = temp;
    }
    // if new > head priority
    else if (gpa > head->gpa) {
        temp->next = head;
        head = temp;
    }
    // if new <= head priority
    else if (gpa <= tail->gpa) {
        tail->next = temp;
        tail = temp;
    }
    // if new = middle priority
    else {
        data* curr = head;

        // while (curr->next->gpa >= gpa) {
        //     curr = curr->next;
        // }
        // temp->next = curr->next;
        // curr->next = temp;
        
        while (strcmp(curr->next->nim, nim) > 0) {
            curr = curr->next;
        }
        temp->next = curr->next;
        curr->next = temp;
    }
}

void pop()
{
    if (head != 0) {
        data* del = head;
        head = head->next;
        free(del);
    }
    else {
        printf("bruh\n");
    }
}

void print()
{
    data* curr = head;

    while (curr != 0) {
        printf("%s %s %.2f\n", curr->name, curr->nim, curr->gpa);
        curr = curr->next;
    }
}

int main()
{
    char a[] = "budi"; char nimA[] = "1111";
    char b[] = "wati"; char nimB[] = "1112";
    char c[] = "timo"; char nimC[] = "1113";
    char d[] = "tyre"; char nimD[] = "1114";
    char e[] = "bobb"; char nimE[] = "1115";

    push(d, nimD, 3.0);
    push(b, nimB, 2.5);
    push(c, nimC, 3.5);
    push(a, nimA, 4.0);
    push(e, nimE, 3.2);

    print();

}