#include <stdio.h>

int main()
{
	int num;
	scanf("%d", &num);
	int count = 0;
	long long int roomNum;
	long long int satisfied[num];

	for (int i = 0; i < num; i++) {
		int check = 1;
		scanf("%lld", &roomNum);
		for (int j = 0; j < count; j++) {
			if (roomNum == satisfied[j]) check = 0;
		}
		if (check == 1) {
			satisfied[count] = roomNum;
			count++;
		}
	}
	printf("%d\n", count);
	return 0;
}