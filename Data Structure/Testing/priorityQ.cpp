#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node* next;
};

node* head = 0;
node* tail = 0;

void push(int val) {
    node* temp = (node*)malloc(sizeof(node));
    temp->val = val;
    temp->next = 0;

    if (head == 0 || head->val > val) {
        temp->next = head;
        head = tail = temp;
    }
    else {
        node* curr = head;

        while (curr->next && curr->next->val < val) {
            curr = curr->next;
        }

        temp->next = curr->next;
        curr->next = temp;
    }
}

void view()
{
    node* curr = head;
    while (curr) {
        printf("%d -> ", curr->val);
        curr = curr->next;
    }
}

int main()
{
    push(7);
    push(15);
    push(10);
    push(47);
    push(56);
    push(62);
    push(30);
    push(28);

    view();
}