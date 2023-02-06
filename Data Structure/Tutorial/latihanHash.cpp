#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

const int maxArrSize = 20;

// linear probing
typedef struct data {
    char name[20];
} data;

data* dataArr[maxArrSize];

int hashFunc(const char* name) // division hash func
{
    char first = name[0];
    char first2 = name[1];
    char last = name[strlen(name) - 1];
    char last2 = name[strlen(name) - 2];

    int key = ceil((float) (first * first2) / (float) (last + last2));

    return key % maxArrSize;
}

void insert(const char* name)
{
    data* temp = (data*)malloc(sizeof(data));
    strcpy(temp->name, name);

    // get hash value (key) from hash func
    int idx = hashFunc(name);
    printf("%d\n", idx);
    
    // if curr idx is null
    if (dataArr[idx] == 0) {
        dataArr[idx] = temp;
    }
    // else
    else {
        int currIdx = idx + 1;
        // loop until empty spot
        while (dataArr[currIdx] != 0) {
            currIdx++;
            if (currIdx >= maxArrSize) currIdx = 0;
            if (currIdx == idx) break;
        }
        // if arr is full
        if (currIdx == idx) printf("Array is full!\n");
        // if found
        else {
            dataArr[currIdx] = temp;
        }
    }
}

void display()
{
    for (int i = 0; i < maxArrSize; i++) {
        // printf("%s\n", dataArr[i]->name);
    }
}

int main()
{
    insert("Youtube21"); // 0
    insert("noobmaster96"); // 10
    insert("xTyranx"); // 4
    insert("Revan789"); // 14
    insert("Mario");//14
    insert("RoboFox"); // 19
    insert("SnakeyBoy"); // 19
    insert("Derp"); // 10
    insert("Herpina"); // 15
    insert("DonChef"); // 17

    display();
}
/*
19 

*/