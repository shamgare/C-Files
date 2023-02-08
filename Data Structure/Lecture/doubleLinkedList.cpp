#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* next;
    struct node* prev;
} node;

node* head = 0;
node* tail = 0;

void insertTail(int val)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->val = val;
    temp->next = temp->prev = 0;

    // 1st data
    if (head == NULL) {
        head = tail = temp;
    }
    // 2nd data
    else {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
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
    if (head) {
        node* curr = head;

        //if 1 node
        if (head == tail && head->val == val) {
            free(head);
            head = tail = 0;
        }
        //if delete head
        else if (head->val == val) {
            head = head->next;
            free(head->prev);
            head->prev = 0;
        }
        //if delete tail
        else if (tail->val == val) {
            tail = tail->prev;
            free(tail->next);
            tail->next = 0;
        }
        //if delete else
        else {
            while (curr->next != 0 && curr->next->val != val) {
                curr = curr->next;
            }

            if (curr->next != NULL) {
                node* a = curr;
                node* del = curr->next;
                node* b = curr->next->next;

                a->next = b;
                b->prev = a;
                free(del);
            }
        }
    }
}

int main(int argc, char const* argv[])
{
    insertTail(40);
    insertTail(50);
    insertTail(60);
    insertTail(70);

    deleteNode(60);
    // deleteNode(50);
    // deleteNode(60);
    // deleteNode(60);
    // deleteNode(70);
    // deleteNode(40);

    print();
    
    return 0;
}
