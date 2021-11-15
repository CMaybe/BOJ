#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;


int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	
	long long int n;
	cin >> n;
	long long int ans = n;
	for (long long int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			ans -= ans / i;
			while (n % i == 0) n /= i;
		}
	}
	if (n > 1) ans -= ans / n;

	cout << ans;

	return 0;
}
