#include<cstdio>
#include<algorithm>
#include<string.h>


int n, m;
int arr[501][501];
int dp[501][501];
int a[4] = { 1, 0, -1, 0 };
int b[4] = { 0, 1, 0, -1 };
int dfs(int x, int y)
{
	if (dp[x][y] != -1) return dp[x][y];
	if (x < 0 || x >= n || y < 0 || y >= m) return 0;
	if (x == 0 && y == 0) return 1;

	dp[x][y] = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + a[i];
		int ny = y + b[i];

		if (arr[nx][ny] > arr[x][y])
			dp[x][y] += dfs(nx, ny);
	}

	return dp[x][y];
}

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	memset(dp, -1, sizeof(dp));
	printf("%d", dfs(n - 1, m - 1));
	return 0;
}
