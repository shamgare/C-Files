#include <stdio.h>
#include <string.h>

void palin(), empatBelas();

int main()
{
    palin();
    // empatBelas();
}

// step 1 : cari semua substring
// step 1.5 : gaperlu tes tiap huruf, cari subsstring sesuai urutan katanya
// step 2 : cek apakah tiap substring palindrome
// step 2.5 : counter jika ad substring palindrome yg udh pernah muncul

void palin()
{
    char str[255] = {};
    char arr[255][255] = {};
    int sub = 0;

    scanf("%s", str);
    for (int i = 0; i < strlen(str); i++) {
        int len = strlen(str);

        for (int j = 0; j < len - i; j++) {
            char temp[255] = {};
            char reverse[255] = {};
            int z = 0;

            for (int k = j; k < i+j+1; k++) {
                temp[z] = str[k];
                z++;
            }

            printf("%s\n", temp);

            int len2 = strlen(temp) - 1;
            for (int l = 0; l < strlen(temp); l++) {
                reverse[l] = temp[len2];
                len2--;
            }

            // printf(" %s", reverse);

            if (strcmp(reverse, temp) == 0) {
                int sama = 0;
                for (int x = 0; x < sub; x++) {
                    if (strcmp(arr[x], temp) == 0) {
                        sama = 1;
                    }
                }
                if (sama == 0) {
                    strcpy(arr[sub], temp);
                    sub++;
                }

                //printf(" %d", sub); 
            }
        }
    }
    printf("%d\n", sub);
}

void empatBelas()
{
    char kata[255] = {};
    char subs[255][255] = {};
    scanf("%s", kata);

    int n = 0, z = 0;
    int l = strlen(kata);
    for (int i = 1; i <= l; i++) {
        for (int j = 0; j <= l - i; j++) {
            char temp[255];
            strncpy(temp, kata+j, i);
            temp[j+i] = 0;
            
            int flag = 0;
            for (int k = 0, m = i - 1; k <= m; k++, m--) {
                if (temp[k] != temp[m]) flag = 1;
            }

            if (flag == 0) {
                int flag2 = 0;
                for (int k = 0; k < n; k++) {
                    printf("%s %s || ", temp, subs[k]);
                    if(strcmp(temp, subs[k]) == 0) {
                        flag2 = 1;
                    }
                }
                if (flag2 == 0) {
                    strcpy(subs[n], temp);
                    n++;
                }
            }
        }
    }
    printf("%d\n", n);
}