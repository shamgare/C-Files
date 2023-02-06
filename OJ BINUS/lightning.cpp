#include <stdio.h>

int main()
{
    FILE* file = fopen("testdata.in", "r");

    int t;

    fscanf(file, "%d\n", &t);

    int n, a, b;
    for (int i = 0; i < t; i++) {
        fscanf(file, "%d %d %d\n", &n, &a, &b);
        char str[n + 1];
        fscanf(file, "%s\n", str);

        int count = 1;
        int counter = 0;
        
        for (int j = 0; j < n - 1; j++) {
            if (str[j] == '1') {
                if (str[j + 1] == '1') {
                    count++;
                }
                else {
                    if (count < a || count > b) count = 1;
                    else {
                        counter++;
                        count = 1;
                    }
                }
            }
        }
        
        if (count < a || count > b) count = 1;
        else {
            counter++;
            count = 1;
        }
        printf("Case #%d: %d\n", i + 1, counter);
    }   
}