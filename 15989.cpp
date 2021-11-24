#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;


int dp[10002];

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);

	int n, t;
	cin >> t;
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	dp[4] = 4;
	dp[5] = 5;
	for (int i = 5; i <= 10000; i++) {
		dp[i] = 1 + (i / 2) + dp[i - 3];
	}
	while (t--) {
		cin >> n;
		cout << dp[n] << '\n';
	}

	return 0;
}
