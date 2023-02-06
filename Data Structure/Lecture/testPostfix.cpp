#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

typedef struct stack {
    int val;
    struct stack* next;
} stack;

stack* head = NULL;

void push(int val)
{
    stack* temp = (stack*)malloc(sizeof(stack));
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

void pop(int val)
{
    stack* curr = head;

    if (curr->val == val) {
        head = curr->next;
        free(curr);
    }
    else {
        while (curr->next->val != val) {
            curr = curr->next;
            if (curr->next == NULL) break;
        }
        
        stack* del;

        if (curr->next != NULL) {
            del = curr->next;
            curr->next = del->next;
        }
        
        free(del);
    }
}

void print()
{
    stack* curr = head;
    while (curr != NULL) {
        printf("%d\n", curr->val);
        curr = curr->next;
    }
}

int main(int argc, char const* argv[])
{
    char str[100]; scanf("%s", str);
    int len = strlen(str);
    
    for (int i = 0; i < len; i++) {
        if (isdigit(str[i])) {
            push(str[i] - 48);
        }
        else {
            int a = head->val;
            pop(head->val);
            int b = head->val;
            pop(head->val);

            // printf("%d %d\n", a, b);

            if (str[i] == '+') {
                push(b + a);
            }
            else if (str[i] == '-') {
                push(b - a);
            }
            else if (str[i] == '/') {
                push(b / a);
            }
            else if (str[i] == '*') {
                push(b * a);
            }
            else {
                push(pow(b, a));
            }
        }
    }
    
    print();
    
    return 0;
}

// 4652-*3/+
