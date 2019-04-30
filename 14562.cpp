#include<iostream>
#include<cstring>
using namespace std;
int minv = 1e9;
void func(int s, int t, int cnt) {
	if (cnt >= minv) return;
	if (s > t)return;
	if (s == t) {
		minv = cnt;
		return;
	}
	func(s + 1, t, cnt + 1);
	func(s + s, t+3, cnt + 1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, s = 0, t = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		minv = 1e9;
		cin >> s >> t;
		func(s, t, 0);
		cout << minv << endl;
	}

	return 0;
}
