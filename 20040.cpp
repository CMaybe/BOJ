#include <iostream>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;

int arr[500001];

int find(int x) {
	if (x == arr[x]) return x;
	else return arr[x] = find(arr[x]);
}

void Union(int x, int y) {
	x = find(x);
	y = find(y);
	if (x < y) arr[y] = x;
	else arr[x] = y;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int m, n;
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		arr[i] = i;
	}
	bool flag = true;
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		if (find(a) == find(b)) {
			cout << i;
			flag = false;
			break;
		}
		Union(a, b);
	}
	if (flag) cout << 0;
	return 0;
}
