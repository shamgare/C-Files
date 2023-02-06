#include <stdio.h>

int main()
{
	int a[10], b[10], c[10], d[10], i;
	float sum[10];
	
	for(i=0;i<3;i++) {
		scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
		//scanf("%f %f %f %f", &a[i], &b[i], &c[i], &d[i]);
		sum[i] = (float) 2*(a[i]/1) + 4*(b[i]/2) + 6*(c[i]/3) + 4*(d[i]/4);
		//sum[i] = a[i]*2 + b[i]*2 + c[i]*2 + d[i];
		printf("%.2f\n", sum[i]);
	}
	return 0;
}
