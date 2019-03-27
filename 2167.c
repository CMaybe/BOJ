#include<stdio.h>
int arr[301][301];

int main()
{
	int n, m,x,y,a,b;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &arr[i][j]);
			arr[i][j] += arr[i][j - 1];
		}
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d%d", &x, &y, &a, &b);
		int sum = 0;
		for (int j = x; j <= a; j++) {
			sum += arr[j][b] - arr[j][y - 1];
		}
		printf("%d\n", sum);
	}

}
