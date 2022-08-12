#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<vector<int>> v(n, vector<int>(k));
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		map<int, int> m;

		for (int j = 0; j < k; j++) {
			int t,c = 1;
			cin >> t;
			while (m.find(c) != m.end()) {
				if (m[c] < t) {
					c *= 2;
					c += 1;
				}
				else {
					c *= 2;
				}
			}
			m[c] = t;
		}

		int idx = 0;
		for (auto &t : m) v[i][idx++] = t.first;
		sort(v[i].begin(), v[i].end());
		
		bool flag = true;
		for (int j = 0; j < i; j++) {
			int t = 0;
			while (t < k && v[j][t] == v[i][t]) t++;
			if (t == k) {
				flag = false;
				break;
			}
		}
		cnt += flag ? 1 : 0;
	}

	cout << cnt;
	

	return 0;

}
