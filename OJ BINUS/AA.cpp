#include <stdio.h>
// soal ular tangga

int main()
{
    int kasus, num, sum = 0;
    scanf("%d", &kasus);

    for (int i = 0; i < kasus; i++) {
        scanf("%d", &num);
        sum += num;
        if (sum == 9) {
            sum += 21-9;
        } else if (sum == 33) {
            sum += 42-33;
        } else if (sum == 76) {
            sum += 92-76;
        } else if (sum == 53) {
            sum -= 53-37;
        } else if (sum == 80) {
            sum -= 80-59;
        } else if (sum == 97) {
            sum -= 97-88;
        }
    }
    printf("%d\n", sum);
    return 0;
}