#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

long long int arr[40][40];
long long int dp[40][40][40][40];

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);


	
	int n;
	long long int ans = 0;

	cin >> n;
	memset(arr, 1, sizeof(arr));
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	dp[1][1][2][1] = 1;
	for (int x1 = 1; x1 <= n; x1++) {
		for (int y1 = 1; y1 <= n; y1++) {
			for (int x2 = x1 - 1; x2 <= x1 + 1; x2++) {
				for (int y2 = y1 - 1; y2 <= y1 + 1; y2++) {
					if (x2 != x1 && y1 == y2) {
						if (arr[y2][x2 + 1] == 0) dp[x1 + 1][y1][x2 + 1][y2] += dp[x1][y1][x2][y2];
						if (arr[y2][x2 + 1] == 0 && arr[y2 + 1][x2] == 0 && arr[y2 + 1][x2 + 1] == 0) dp[x1 + 1][y1][x2 + 1][y2+1] += dp[x1][y1][x2][y2];
					}
					if (x2 == x1 && y1 != y2) {
						if (arr[y2 + 1][x2] == 0) dp[x1][y1+1][x2][y2+1] += dp[x1][y1][x2][y2];
						if (arr[y2 + 1][x2] == 0 && arr[y2][x2 + 1] == 0 && arr[y2 + 1][x2 + 1] == 0) dp[x1][y1+1][x2 + 1][y2+1] += dp[x1][y1][x2][y2];
					}
					if (x2 != x1 && y1 != y2) {
						if (arr[y2][x2 + 1] == 0) dp[x1 + 1][y1+1][x2 + 1][y2] += dp[x1][y1][x2][y2];
						if (arr[y2 + 1][x2] == 0) dp[x1 + 1][y1+1][x2][y2+1] += dp[x1][y1][x2][y2];
						if (arr[y2 + 1][x2] == 0 && arr[y2][x2 + 1] == 0 && arr[y2 + 1][x2 + 1] == 0) dp[x1 + 1][y1+1][x2 + 1][y2+1] += dp[x1][y1][x2][y2];
					}
				}
			}
		}
	}
	cout << dp[n - 1][n - 1][n][n] + dp[n - 1][n][n][n] + dp[n][n - 1][n][n];
	return 0;
}
