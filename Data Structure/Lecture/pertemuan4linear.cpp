#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int maxArrSize = 12;

// linear probing
typedef struct data {
    char heroName[20];
    char heroType[15];  // str agi int
    int lvl;
} data;

data* dataArr[maxArrSize];

int hashFunc(const char* heroName) // division hash func
{
    char first = heroName[0];
    // char last = heroName[strlen(heroName) - 1];

    // int key = (first + last) % maxArrSize;
    int key = first - 97;

    return key;
}

void insert(const char* heroName, const char* heroType, int lvl)
{
    data* temp = (data*)malloc(sizeof(data));
    strcpy(temp->heroName, heroName);
    strcpy(temp->heroType, heroType);
    temp->lvl = lvl;

    // get hash value (key) from hash func
    int idx = hashFunc(heroName);

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
        if (dataArr[i] != 0) printf("%s\n", dataArr[i]->heroName);
    }
}

int main()
{
    // insert("Brimstone", "Controller", 1);
    // insert("Viper", "Controller", 1);
    // insert("Omen", "Controller", 1);
    // insert("Phoenix", "Duelist", 1);
    // insert("Jett", "Duelist", 1);
    // insert("Neon", "Duelist", 1);
    // insert("Reyna", "Duelist", 1);
    // insert("Killjoy", "Sentinel", 1);
    // insert("Chamber", "Sentinel", 1);
    // insert("Cypher", "Sentinel", 1);
    // insert("Yoru", "Duelist", 1);
    // insert("Fade", "Initiator", 1);
    // insert("Sova", "Initiator", 1);
    // insert("Breach", "Initiator", 1);
    insert("axe", "str", 1);
    insert("axe", "str", 1);
    insert("lion", "str", 1);
    insert("invoker", "str", 1);
    

    display();
}

/*




*/