#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* next;
} node;

node* head = NULL;

node* newNode(int val)
{
    node* temp = (node*)malloc(sizeof(node));
    
    temp->val = val;
    temp->next = NULL;

    return temp;
}

void insert(int val)
{
    // node* temp = newNode(val);

    // atau
    
    node* temp = (node*)malloc(sizeof(node));
    temp->val = val;
    temp->next = NULL;

    // if inserting first data
    if (head == NULL) {
        head = temp;
    }
    // if inserting second / more data
    else {
        temp->next = head;
        head = temp;
    }
}

void print()
{
    node* curr = head;
    while (curr != NULL) {
        printf("%d\n", curr->val);
        curr = curr->next;
    }
}

void deleteNode(int val)
{
    node* curr = head;

    if (curr->val == val) {
        head = curr->next;
        free(curr);
    }
    else {
        while (curr->next->val != val) {
            curr = curr->next;
            if (curr->next == NULL) break;
        }
        
        node* del;

        if (curr->next != NULL) {
            del = curr->next;
            curr->next = del->next;

            free(del);
        }
    }
}

int main(int argc, char const* argv[])
{
    int kasus, x; scanf("%d", &kasus);
    
    for (int i = 0; i < kasus; i++) { scanf("%d", &x); insert(x); }
    
    deleteNode(5);
    deleteNode(15);
    deleteNode(35);

    print();
    
    // free(head);
}
