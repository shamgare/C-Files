#include <stdio.h>
#include <string.h>

struct student {
    char name[35];
    int submit;
    int score[105];
} stud[10010];

int binary(int left, int right, char* name)
{
    while (left <= right) {
        int mid = (left + right) / 2;
        if (strcmp(stud[mid].name, name) == 0) {
            return mid;
        } else if (strcmp(name, stud[mid].name) < 0) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int main()
{
    FILE* file = fopen("testdata.in", "r");

    int student; fscanf(file, "%d\n", &student);

    for (int i = 0; i < student; i++) {
        fscanf(file, "%[^\n]\n", stud[i].name);
        fscanf(file, "%d\n", &stud[i].submit);
        for (int j = 0; j < stud[i].submit; j++) {
            if (j != stud[i].submit - 1) fscanf(file, "%d", &stud[i].score[j]);
            else fscanf(file, "%d\n", &stud[i].score[j]);
        }
    }

    int check = 0; fscanf(file, "%d\n", &check);
    char name[35] = {};
    for (int i = 0; i < check; i++) {
        fscanf(file, "%[^\n]\n", name);

        double avg = 0;
        int index = binary(0, student-1, name);

        if (index != -1) {
            for (int j = 0; j < stud[index].submit; j++) {
                avg += stud[index].score[j];
            }
            
            avg /= stud[index].submit;

            printf("Case #%d: %.2lf\n", i+1, avg);
        } else {
            printf("Case #%d: Invalid Name\n", i+1);
        }
    }
}