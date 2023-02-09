#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = 0;
struct Node* tail = 0;

Node* createNode(int val) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->val = val;
    temp->next = temp->prev = 0;
    return temp;
}

void push(int val) {
    Node* temp = createNode(val);
    
    if (head == 0) {
        head = tail = temp;
    }
    else {
        
    }
}

void display() {
    Node* curr = head;
    while (curr) {
        printf("%d -> ", curr->val);
        curr = curr->next;
    }
}

int main()
{
    int num, n;
    printf("Enter the loop: "); scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        printf("Enter the numbers: ");
        scanf("%d", &num);
        push(num);
    }

    display();
}