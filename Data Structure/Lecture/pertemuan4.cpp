#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int maxArrSize = 20;

// hashing
typedef struct data {
    char heroName[20];

    struct data* next;
} data;

data* dataArr[maxArrSize];

int hashFunc(const char* heroName) // division hash func
{
    char first = heroName[0];
    char first2 = heroName[1];
    char last = heroName[strlen(heroName) - 1];
    char last2 = heroName[strlen(heroName) - 2];;
    int key = ((first * first2) / (last + last2)) % maxArrSize;

    return key;
}

void insert(const char* heroName)
{
    data* temp = (data*)malloc(sizeof(data));
    strcpy(temp->heroName, heroName);
    temp->next = 0;

    // get hash value (key) from hash func
    int idx = hashFunc(heroName);
    // printf("%d\n", idx);

    // insert to hash table, apply chaining if needed

    // if curr idx in hash table is empty
    data* curr = dataArr[idx];
    if (dataArr[idx] == 0) {
        dataArr[idx] = temp;
    }
    else if (strcmp(temp->heroName, curr->heroName) < 0) {
        temp->next = curr;
        dataArr[idx] = temp;
    }
    // else
    else {
        while (curr->next && strcmp(temp->heroName, curr->next->heroName) >= 0) {
            curr = curr->next;
        }
        temp->next = curr->next;
        curr->next = temp;
    }
}

void display()
{
    for (int i = 0; i < maxArrSize; i++) {
        if (dataArr[i] != 0) {
            data* curr = dataArr[i];
            while (curr) {
                printf("%s -> ", curr->heroName);
                curr = curr->next;
            }
            printf("\n");
        }
    }
}

int main()
{
    insert("Youtube21");
    insert("noobmaster96");
    insert("xTyranx");
    insert("Revan789");
    insert("Mario");
    insert("RoboFox");
    insert("SnakeyBoy");
    insert("Derp");
    insert("Herpina");
    insert("DonChef");

    display();
}

/*




*/