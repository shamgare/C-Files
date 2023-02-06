#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct nama {
    char names[100];
    char asal[100];
};

struct kelompok {
    char namakel[100];
    struct nama n1[100];
} kel[100];

//b a
//kel[1] kel[0]

int partition(int low, int high)
{
    int i = low - 1;
    int j = low;
    char pivot[100];
    strcpy(pivot, kel[high].namakel);

    while (j < high) {
        if (strcmp(pivot, kel[j].n1[j].names) == 1) {
            i++;
            char temp[100];
            strcpy(temp, kel[j].n1[i].names);
            strcpy(kel[j].n1[i].names, kel[j].n1[j].names);
            strcpy(kel[j].n1[j].names, temp);
        }
        j++;
    }

    strcpy(kel[j].n1[high].names, kel[j].n1[i+1].names);
    strcpy(kel[j].n1[i+1].names, pivot);

    return i+1;
}

void quickSort(int low, int high)
{
    if (high == low || high == -1 || low == -1) return;

    int pos = partition(low, high);

    quickSort(low, pos-1);
    quickSort(pos, high);
}

int main()
{
    // struct nama kel[j].n1[5];
    
    for (int i = 0; i < 5; i++) {
        scanf("%s %s", kel[i].n1[i].names, kel[j].n1[i].asal);
    }
    int size = 5;
    quickSort(0, size - 1);

    for (int i = 0; i < 5; i++) {
        printf("%s %s\n", kel[i].n1[i].names, kel[j].n1[i].asal);
    }

}
