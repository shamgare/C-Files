#include <stdio.h>
#include <string.h>

// int main()
// {
//     int kasus;
//     char num[100001] = {};
//     int sum, sum2;

//     scanf("%d", &kasus);
//     for (int i = 0; i < kasus; i++) {
//         sum = 0;
//         sum2 = 0;
//         scanf("%s", num);

//         for (int j = 0; j < strlen(num); j++) {
//             if (j % 2 == 0) {
//                 sum2 += (num[j] - 48);
//             } else {
//                 sum += (num[j] - 48);
//             }
//         }

//         if ((sum2-sum) % 11 == 0) {
//             printf("Case #%d: Yeah\n", i+1);
//         } else {
//             printf("Case #%d: Nah\n", i+1);
//         }
//     }
// }

// algo jackys
int main()
{
    int input, i; 
    scanf("%d", &input); 
    getchar();

    for (i = 1; i <= input; i++)
    {
        char value = '0';
        int temp = 0, index = 0;
        while (value != '\n')
        {
            if (index % 2 == 0)
            {
                temp += (value - 48);
            }
            else
            {
                temp -= (value - 48);
            }
            scanf("%c", &value);
        }
        printf("Case #%d: %s\n", i, temp % 11 == 0 ? "Yeah" : "Nah");
    }
    return 0;
}

