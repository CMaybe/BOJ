#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
bool prime[4000001];
int n, sum, ans;
int s, e;

void init() {
	for (int i = 2; i * i <= 4000000; i++) {
		if (!prime[i]) {
			for (int j = i * i; j <= 4000000; j += i) {
				prime[j] = true;
			}
		}
	}	

	for (int i = 2; i <= n; i++) {
		if (!prime[i]) v.push_back(i);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	s = 0;
	e = 0;
	init();
	while (true) {
		if (sum >= n) {
			sum -= v[s];
			s++;
		}
		else {
			if (e == v.size())break;
			sum += v[e];
			e++;
		}
		if (sum == n) ans++;
	}

	cout << ans;
	return 0;
}
