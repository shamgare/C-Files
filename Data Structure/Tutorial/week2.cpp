#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* next;
} node;

node* head = 0;
node* tail = 0;

node* newNode(int val)
{
    node* temp = (node*)malloc(sizeof(node));
    
    temp->val = val;
    temp->next = NULL;

    return temp;
}

void insertTail(int val)
{
    node* temp = newNode(val);
    
    if (tail == 0) {
        head = tail = temp;
    }
    else {
        tail->next = temp;
        tail = temp;
    }
}

void insertHead(int val)
{
    node* temp = newNode(val);

    if (head == 0) {
        head = tail = temp;
    }
    else {
        temp->next = head;
        head = temp;
    }
}

void print()
{
    node* curr = head;
    while (curr != 0) {
        printf("%d -> ", curr->val);
        curr = curr->next;
    }
}

void insertMid(int val)
{
    node* curr = head;
    node* temp = newNode(val);
    
    // insert ascending
    // while (curr->next->val < val) {
    //     curr = curr->next;
    // }
    // temp->next = curr->next;
    // curr->next = temp;

    // insert descending
    while (curr->next->val > val) {
        curr = curr->next;
    }
    temp->next = curr->next;
    curr->next = temp;
}

void insertDataAsc(int val)
{
    // if ll empty
    if (head == 0) {
        insertHead(val);
    }
    // if new val < head
    else if (val < head->val) {
        insertHead(val);
    }
    // if new val > tail
    else if (val > tail->val) {
        insertTail(val);
    }
    // else
    else {
        insertMid(val);
    }
}

void insertDataDsc(int val)
{
    // if ll empty
    if (head == 0) {
        insertHead(val);
    }
    // if new val < head
    else if (val > head->val) {
        insertHead(val);
    }
    // if new val > tail
    else if (val < tail->val) {
        insertTail(val);
    }
    // else
    else {
        insertMid(val);
    }
}

int main(int argc, char const* argv[])
{
    // asc
    // insertDataAsc(40);
    // insertDataAsc(3);
    // insertDataAsc(30);
    // insertDataAsc(80);
    // insertDataAsc(35);

    // dsc
    insertDataDsc(40);
    insertDataDsc(3);
    insertDataDsc(30);
    insertDataDsc(80);
    insertDataDsc(35);
    

    print();
    
    return 0;
}
