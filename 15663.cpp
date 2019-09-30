#include <iostream>
#include <vector>
#include<string>
#include <algorithm>
#include<functional>

using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);

	int m, n, t;
	vector<int> v;
	string temp = "";

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> t;
		v.push_back(t);
	}

	sort(v.begin(), v.end());

	do {
		string c = "";
		for (int i = 0; i < m; i++) {
			c += to_string(v[i]) + " ";
		}
		if (temp != c) {
			cout << c + "\n";
			temp = c;
		}
	} while (next_permutation(v.begin(), v.end()));

	return 0;

}
