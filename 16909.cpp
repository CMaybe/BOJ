#include <iostream>
#include <stack>

using namespace std;
using ll = long long int;
int n;
stack<int> st;
ll ans, s[1000001], e[1000001], d[1000001];

void func() {
	for (int i = 0; i < n; i++) {
		s[i] = 0;
		e[i] = n - 1;
	}	
	for (int i = 0; i < n; i++) {
		while (!st.empty() && d[st.top()] <= d[i]) {
			e[st.top()] = i - 1;
			st.pop();
		}
		st.push(i);
	}
	st = stack<int>();
	for (int i = n - 1; i >= 0; i--) {
		while (!st.empty() && d[st.top()] < d[i]) {
			s[st.top()] = i + 1;
			st.pop();
		}
		st.push(i);
	}
	st = stack<int>();
	for (int i = 0; i < n; i++) {
		ans += d[i] * ((e[i] - i) * (i - s[i]) + e[i] - s[i] + 1);
	}

	return;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> d[i];
	func();
	for (int i = 0; i < n; i++) d[i] *= -1;
	func();
	
	cout << ans;
	return 0;
}
