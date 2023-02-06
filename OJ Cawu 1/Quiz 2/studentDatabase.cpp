#include <stdio.h>

struct student {
    char id[21];
    char name[101];
    int age;
} student[1001];

int main()
{
    int stud; scanf("%d", &stud); getchar();

    for (int i = 0; i < stud; i++) {
        scanf("%s", student[i].id); getchar();
        scanf("%[^\n]", student[i].name);
        scanf("%d", &student[i].age); getchar();
    }

    int query; scanf("%d", &query); getchar();

    for (int i = 0; i < query; i++) {
        int pick; scanf("%d", &pick); pick -= 1;
        
        printf("Query #%d:\n", i + 1);
        printf("ID: %s\n", student[pick].id);
        printf("Name: %s\n", student[pick].name);
        printf("Age: %d\n", student[pick].age);
    }
}
/*


2
01337
Lili Lili
18
69420
Bibi
20
2
2
1



*/