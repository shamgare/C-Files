#include <stdio.h>
#include <string.h>

int part(char arr[][110], int low, int high)
{
    int i = low - 1;
    int j = low;
    char pivot[110];
    strcpy(pivot, arr[high]);

    while (j < high) {
        if (strcmp(pivot, arr[j]) > 0) {
            i++;
            char temp[110];
            strcpy(temp, arr[j]);
            strcpy(arr[j], arr[i]);
            strcpy(arr[i], temp);
        }
        j++;
    }
    strcpy(arr[high], arr[i+1]);
    strcpy(arr[i+1], pivot);

    return i+1;
}

void qs(char arr[][110], int low, int high)
{
    if (low < high) {
        int pos = part(arr, low, high);

        qs(arr, low, pos - 1);
        qs(arr, pos + 1, high);
    }
}

int main()
{
    int kasus; scanf("%d", &kasus);

    for (int j = 0; j < kasus; j++) {
        int orang, find; scanf("%d %d", &orang, &find);

        char people[orang][110] = {};

        for (int i = 0; i < orang; i++) {
            scanf("%s", people[i]);
        }

        qs(people, 0, orang - 1);

        // for (int i = 0; i < orang; i++) {
        //     printf("%s ", people[i]);
        // }

        printf("Case #%d: %s\n", j+1, people[find - 1]);
    }
}