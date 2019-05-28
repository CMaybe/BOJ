#include<iostream>

using namespace std;

int arr[1001][1001] = { 1 };

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		arr[i][0] = 1;
		arr[i][1] = i;
		for (int j = 2; j <= k; j++) {
			arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j])%10007;
		}
	}
	cout << (arr[n][k]% 10007);
}
