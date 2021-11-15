#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

using ll = long long;

ll arr[2001][2001];
ll n, k, m;

// 뤼카의 정리
void func() {
	memset(arr, 0, sizeof(arr));
	arr[0][0] = arr[1][0] = arr[1][1] = 1;

	for (int i = 2; i <= 2000; i++) {
		arr[i][0] = 1;
		arr[i][i] = 1;
		for (int j = 1; j < i; j++) {
			arr[i][j] = (arr[i - 1][j] + arr[i - 1][j - 1]) % m;
		}
	}

	return;
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);

	cin >> n >> k >> m;

	func();
 	ll ans = 1;
	while (n > 0 || k > 0) {
		ll N, K;
		N = n % m;
		K = k % m;

		ans *= arr[N][K];
		ans %= m;

		n -= N;
		k -= K;

		n /= m;
		k /= m;
	}
	cout << ans;
	return 0;
}
