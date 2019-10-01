#include<cstdio>
#include<cmath>
void hanoi(int s, int e, int t, int n) {
	if (n == 1) {
		printf("%d %d\n", s, e);
		return;
	}
	hanoi(s, t, e, n - 1);
	printf("%d %d\n", s, e);
	hanoi(t, e, s, n - 1);
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", (int)pow(2, n) - 1);
	hanoi(1, 3, 2, n);
	return 0;
}
