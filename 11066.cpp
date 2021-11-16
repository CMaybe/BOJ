#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;


int arr[501];
int dp[501][501];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);

	int t,k,c;
	cin >> t;
	while (t--) {
		cin >> k;
		memset(arr, 0, sizeof(arr));
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= k; i++) {
			cin >> c;
			if (i == 1) arr[i] = c;
			else arr[i] = arr[i - 1] + c;
		}

		for (int i = 1; i < k; i++) {
			for (int s = 1; s + i <= k; s++) {
				int e = s + i;
				int sum = arr[e] - arr[s - 1];
				dp[s][e] = 1e9;
				for (int l = s; l <= e; l++) {
					dp[s][e] = min(dp[s][e], dp[s][l] + dp[l + 1][e] + sum);
				}
			}
		}

		cout << dp[1][k]<<'\n';
	}



	return 0;
}
