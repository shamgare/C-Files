#include <stdio.h>

int main()
{
	int a,b,c,d,e;
	float avg;
	
	printf("Enter five integers: ");
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	
	avg = (float) (a+b+c+d+e) / 5;
	printf("The average of those numbers is: %.2f\n", avg);
	
	if (a>=b && a>=c && a>=d && a>=e) {
		printf("The largest number is %d\n", a);
	} else if (b>=a && b>=c && b>=d && b>=e) {
		printf("The largest number is %d\n", b);
	} else if (c>=a && c>=b && c>=d && c>=e) {
		printf("The largest number is %d\n", c);
	} else if (d>=a && d>=b && d>=c && d>=e) {
		printf("The largest number is %d\n", d);
	} else {
		printf("The largest number is %d\n", e);
	}
	
	if (a<=b && a<=c && a<=d && a<=e) {
		printf("The smallest number is %d\n", a);
	} else if (b<=a && b<=c && b<=d && b<=e) {
		printf("The smallest number is %d\n", b);
	} else if (c<=a && c<=b && c<=d && c<=e) {
		printf("The smallest number is %d\n", c);
	} else if (d<=a && d<=b && d<=c && d<=e) {
		printf("The smallest number is %d\n", d);
	} else {
		printf("The smallest number is %d\n", e);
	}
	
	return 0;
}
