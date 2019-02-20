#include <stdio.h>
int a[1001], b[1001];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		for (int j = 1; j <= i; j++)
		{
			if (b[i] < b[i - j] + a[j])
				b[i] = b[i - j] + a[j];
		}
	}
	printf("%d", b[n]);
	return 0;
}
