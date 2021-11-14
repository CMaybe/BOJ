#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;


long long int arr[100001];

int main() {
	int n=1;
	while (true) {
		cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++) cin >> arr[i];
		long long int ans = 0;
		stack<long long int> s;
		for (long long int i = 0; i < n; i++) {
			while (!s.empty() && arr[s.top()] > arr[i]) {
				long long int h = arr[s.top()];
				s.pop();
				long long int w = i;
				if (!s.empty()) w = i - s.top() - 1;
				ans = max(ans, h * w);
			}
			s.push(i);
		}
		while (!s.empty()) {
			long long int h = arr[s.top()];
			s.pop();
			long long int w = n;
			if (!s.empty()) w = n - s.top() - 1;
			ans = max(ans, h * w);
		}
		cout << ans << '\n';
	}

	return 0;
}
