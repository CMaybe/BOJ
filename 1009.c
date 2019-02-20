#include<stdio.h>

int main()
{
	int a,b,n,tmp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		tmp = 1;
		for (int j = 0; j < b; j++) {
			tmp *= a;
			tmp %= 100;
		}
		if (tmp % 10 == 0) {
			tmp = 10;
		}
		else {
			tmp %= 10;
		}
		printf("%d\n", tmp);
	}

}
