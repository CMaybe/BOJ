#include<stdio.h>

int main()
{
	int n,min=10000000;
	scanf("%d", &n);
	for (int i = n/5; i >= 0; i--) {
		for (int j = 0; j <= n / 3; j++) {
			if ((j * 3 + i * 5 == n) && min>i+j) {
				min = i + j;
			}
		}
	}
	if (min == 10000000) min = -1;
	printf("%d", min);
}
