#include <cstdio>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

// int main()
// {
//     srand(time(0));

//     char az[63] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"};
//     char arr[11] = {};

//     for (int j = 0; j<=9; j++) {
//         arr[j] = az[rand() % 63];
//     }
    
//     printf("%s\n", arr);
//     printf("%d\n", 999 / 10);
// }

// int main()
// {
//     int num[110] = {};
//     char arr[110][110] = {};
//     char str[110] = {};
//     int count = 0;
//     scanf("%s", &str);
//     for (int i = 0; i < strlen(str); i++)
//     {
//         if(num[str[i] - 'a'] == 0)
//         {
//             num[str[i] - 'a'] = 1;
//             count++;
//         }
//         for (int j = 0; j < strlen(str) - i; j++)
//         {
//             for (int k = j; k <i + j + 1 ; k++)
//             {
//                 arr[j][k] = str[k];
//                 printf("%c", arr[j][k]);
//             }
//             printf("\n");
//         }
//     }
// }

int main()
{
    
    char str[110] = {};
    char substrings[110][110] = {};
    int count = 0;
    scanf("%s", &str);
    for (int i = 0; i < strlen(str); i++)
    {
        for (int j = 0; j < strlen(str) - i; j++)
        {
            char temp[110]= {};
            char rev[110] = {};
            int x = 0;
            for (int k = j; k <i + j + 1 ; k++)
            {
                // temp[k - j] = str[k];
                temp[x++] = str[k];
            }
            printf("%s", temp);
            for (int l = 0; l < strlen(temp); l++)
            {
                rev[l] = temp[strlen(temp)-l-1];
            }
            printf(" %s", rev);
            if(strcmp(rev,temp) == 0)
            {
                int check = 0;
                for (int m = 0; m < count;m++)
                {
                    if(strcmp(rev,substrings[m]) == 0)
                    {
                        check = 1;
                        break;
                    }
                }
                if(check == 0)
                {
                    strcpy(substrings[count], rev);
                    count++;
                }
            }
            printf(" %d", count);
            printf("\n");
        }
    }
    printf("banyak : %d", count);
}
