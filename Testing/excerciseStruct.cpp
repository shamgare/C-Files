#include <stdio.h>

struct address {
    char street[255] = {};
    int streetnum;
    char city[255] = {};
    char prov[255] = {};
};

struct DOB {
    char date[10] = {};
    char month[15] = {};
    int year;
};

struct stud {
    int num;
    char name[255] = {};
    struct address add;
    struct DOB dob;
} s1[5];

int main()
{   
    int a, b;
    scanf("%d %d", &a, &b);
    getchar();

    for (int i = 0; i < a; i++) {
        scanf("%d %s %s %d %s %s %s %s %d", &s1[i].num, s1[i].name, s1[i].add.street, &s1[i].add.streetnum, s1[i].add.city, s1[i].add.prov, s1[i].dob.date, s1[i].dob.month, &s1[i].dob.year);
        getchar();
    }
    for (int j = 0; j < 1; j++) {
        printf("%d %s %s %d %s %s %s %s %d", s1[b].num, s1[b].name, s1[b].add.street, s1[b].add.streetnum, s1[b].add.city, s1[b].add.prov, s1[b].dob.date, s1[b].dob.month, s1[b].dob.year);
    }

    return 0;
}