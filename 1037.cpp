#include<cstdio>
int main()
{
	int t, n, min = 1e9, max = -1;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		if (n < min)min = n;
		if (n > max)max = n;
	}
	printf("%lld", (long long)min * max);

}
