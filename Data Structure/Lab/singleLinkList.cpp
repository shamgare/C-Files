#include <stdio.h>
#include <stdlib.h>

// define the data
typedef struct food {
    int price;
    struct food* next;
} food;

food* head = NULL;
food* tail = NULL;

// function to create
food* create(int price)
{
    food* foods = (food*)malloc(sizeof(food));
    foods->price = price;
    foods->next = NULL;
    return foods;
}

void pushHead(int price)
{
    food* newFood = create(price);
    
    if (!head) {
        head = tail = newFood;
    }
    else {
        newFood->next = head;
        head = newFood;
    }
}

void pushTail(int price)
{
    food* newFood = create(price);
    if (!head) {
        head = tail = newFood;
    }
    else {
        tail->next = newFood;
        tail = newFood;
    }
}

void pushMid(int price)
{
    if (!head || price < head->price) {
        pushHead(price);
    }
    else if (price >= tail->price) {
        pushTail(price);
    }
    else {
        food* newFood = create(price);

        food* curr = head;

        while (curr->next != NULL && curr->next->price < price) {
            curr = curr->next;
        }

        newFood->next = curr->next;
        curr->next = newFood;
    }
}

void deleteFood(int price)
{
    food* curr = head;
    if (head) {
        if (head == tail && head->price == price) {
            free(head);
            head = tail = NULL;
        }
        else if (head->price == price) {
            food* temp = head->next;
            free(head);
            head = temp;
        }
        else if (tail->price == price) {
            while (curr->next != tail) {
                curr = curr->next;
            }

            free(tail);
            curr->next = NULL;
            tail = curr;
        }
        else {
            while (curr->next != NULL && curr->next->price != price) {
                curr = curr->next;
            }
            if (curr->next == NULL || curr->next->price != price) {
                printf("NOT FOUND\n");
            }
            else {
                food* temp = curr->next->next;
                free(curr->next);
                curr->next = temp;
            }
        }
    }
}

void print()
{
    food* curr = head;

    while (curr != NULL) {
        printf("%d ", curr->price);
        curr = curr->next;
    }
}

int main(int argc, char const* argv[])
{
    // food* foods = create(377);
    pushTail(3000);
    pushTail(8000);
    pushTail(10000);
    pushMid(11000);
    pushMid(5000);
    deleteFood(1000);
    print();
    
    return 0;
}
