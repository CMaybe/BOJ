#include<iostream>
using namespace std;
int arr[100];
int n, k;
int dp[10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int idx = 0, t = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> t;
		if (t> 10000) {
			continue;
		}
		arr[idx] = t;
		dp[arr[idx]] = 1;
		idx++;
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < idx; j++) {
			if (arr[j] == i) {
				break;
			}
			if (i - arr[j] > 0 && dp[i - arr[j]] != 0) {
				if (dp[i] == 0)dp[i] = dp[i - arr[j]] + 1;
				else if (dp[i] > dp[i - arr[j]] + 1) {
					dp[i] = dp[i - arr[j]] + 1;
				}
			}
		}
	}
    if(dp[k]==0) dp[k]=-1;
	cout << dp[k];

}
