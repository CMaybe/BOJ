#include<cstdio>

int main()
{
	int n, a, b, c, cnt = 99;
	scanf("%d", &n);
	if (n < 100) {
		printf("%d", n);
	}
	for (int i = 100; i <= n; i++) {
		a = i % 10;
		b = i / 10 % 10;
		c = i / 100;
		if (c - b == b - a) cnt++;
	}
	printf("%d", cnt);
}
