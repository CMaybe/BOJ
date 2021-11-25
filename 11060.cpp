#include <iostream>
#include <algorithm>
using namespace std;


int dp[2000];

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);

	int n, t;
	cin >> n;
	dp[0] = 0;
	dp[1] = 0;
	if (n <= 1) {
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		cin >> t;
		if (i != 1 && dp[i] == 0) continue;
		for (int j = 1; j <= t; j++) {
			if (dp[i + j] == 0) dp[i + j] = dp[i] + 1;
			else dp[i + j] = min(dp[i + j], dp[i] + 1);
		}
	}
	if (dp[n] == 0)dp[n] = -1;
	cout << dp[n];

	return 0;
}
