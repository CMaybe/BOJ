#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

using ll = long long;

bool prime[4000001];



int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	ll n, r, m;
	cin >> n >> r >> m;
	prime[0] = prime[1] = true;
	for (int i = 2; i * i <= n; i++) {
		if (prime[i])continue;
		for (int j = i * i; j <= n; j += i) prime[j] = true;
	}
 	
	vector<ll> primes;
	for (int i = 2; i <= n; i++) {
		if (prime[i] == false) primes.push_back(i);
	}
	vector<ll> v(primes.size());
	for (int i = 0; i < v.size(); i++) {
		for (ll j = primes[i]; j <= n; j *= primes[i]) {
			v[i] += (n / j) - (r / j) - ((n - r) / j);
		}
	}

	ll ans = 1;
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i]; j++) {
			ans *= primes[i];
			ans %= m;
			if (ans == 0) {
				cout << 0;
				return 0;
			}
		}

	}

	cout << ans;

	return 0;
}
