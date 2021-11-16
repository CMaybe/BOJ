#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

using ll = long long;

ll arr[10001];


int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	ll n, m, t;
	ll ans;
	cin >> n >> m;
	for (ll i = 1; i <= m; i++) {
		cin >> arr[i];
	}
	ll s = 0LL, e = 60000000000LL;

	if (n <= m) {
		cout << n;
		return 0;
	}
	
	while (s <= e) {
		ll mid = (s + e) / 2;
		ll cnt = m;
		for (ll i = 1; i <= m; i++) cnt += (mid / arr[i]);
		if (cnt < n) {
			s = mid + 1;
		}
		else {
			e = mid - 1;
			t = mid;
		}
	}

	ll cnt = m;
	for (ll i = 1; i <= m; i++) cnt += (t - 1) / arr[i];
	for (ll i = 1; i <= m; i++) {
		if (t % arr[i] == 0)cnt++;
		if (cnt == n) {
			cout << i;
			break;
		}
	}


	return 0;
}
