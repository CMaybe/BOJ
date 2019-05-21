#include<iostream>

using namespace std;
int arr[1000];
int dp[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i * i <= 100000; i++) {
		arr[i - 1] = i * i;
		dp[i*i] = 1;
	}


	for (int i = 1; i <= n; i++) {
		for (int j = 0; arr[j] < n; j++) {
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
	cout << dp[n];


}
