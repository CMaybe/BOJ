#include <iostream>
#include <vector>
#include<string>
#include <algorithm>
#include<functional>

using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);

	int m, n,t;
	vector<int> v,mask,temp,c;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> t;
		v.push_back(t);
	}
	for (int i = m; i < n; i++) {
		mask.push_back(0);
	}

	for (int i = 0; i < m; i++) {
		mask.push_back(1);
	}
	sort(v.begin(),v.end());

	do {
		c.clear();
		c.push_back(v[0]);
		for (int i = 1; i <m; i++) {
			if (v[i] < v[i - 1]) {
				c.clear();
				break;
			}
			c.push_back(v[i]);
		}
		if (c.empty()) continue;
		if (temp != c) {
			for (int i : c)
				cout << i << " ";
			cout << "\n";
			temp = c;
		}
	} while (next_permutation(v.begin(), v.end()));

	return 0;

}
