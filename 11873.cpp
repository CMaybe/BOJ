#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	while (true) {
		cin >> n >> m;
		if (n + m == 0) break;
		vector<int> v;
		int ans = 0, height[1001] = { 0, };
		for (int i = 1; i <= n; i++) {
			v.push_back(0);
			for (int j = 1; j <= m; j++) {
				int t;
				cin >> t;
				height[j] = (height[j] + 1) * t;
				while (height[v.back()] > height[j]) {
					ans = max(ans, (j - v[v.size() - 2] - 1) * height[v.back()]);
					v.pop_back();
				}
				v.push_back(j);
			}
			while (v.size() > 1) {
				ans = max(ans, (m - v[v.size() - 2]) * height[v.back()]);
				v.pop_back();
			}

		}
		cout << ans << '\n';
	}
	return 0;
}
