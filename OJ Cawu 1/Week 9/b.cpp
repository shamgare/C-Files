#include <stdio.h>
#include <string.h>

struct test {
    char name[120] = {};
    char tree[120] = {};
} t1[105];

int main()
{
    FILE* file = fopen("testdata.in", "r");
    int kasus;
    fscanf(file, "%d\n", &kasus);
    for (int i = 0; i < kasus; i++) {
        fscanf(file, "%[^#]#%[^\n]\n", t1[i].name, t1[i].tree);
    }
    int orang;
    fscanf(file, "%d\n", &orang);
    char name[120] = {};
    for (int i = 0; i < orang; i++) {
        fscanf(file, "%s\n", name);
        for (int j = 0; j < kasus; j++) {
            if (strcmp(name, t1[j].name) == 0) {
                printf("Case #%d: %s\n", i+1, t1[j].tree);
                break;
            }
            if (j == kasus - 1) printf("Case #%d: N/A\n", i+1);
        }
    }
    fclose(file);
}
