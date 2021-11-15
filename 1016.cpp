#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

using ll = long long;

bool arr[1000001];



int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	ll _min, _max;
	cin >> _min >> _max;

	ll ans = _max - _min + 1;
	for (ll i = 2; i * i <= _max; i++) {
		ll num = _min / (i * i);
		if (_min % (i * i) != 0) num++;
		while (num * (i * i) <= _max) {
			ll t = num * (i * i) - _min;
			if (arr[t] == false) {
				arr[t] = true;
				ans -= 1;
			}
			num++;
		}
	}

	cout << ans;

	return 0;
}
