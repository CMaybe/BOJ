#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;


int arr[102][2];

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);

	int h, w, n;
	cin >> h >> w;
	cin >> n;
	int ans = 0;
	vector<int> v;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}
	for (int i = 2; i < n; i++) v.push_back(0);
	for (int i = 0; i < 2; i++) v.push_back(1);
	if (n == 1) {
		cout << 0;
		return 0;
	}
	do
	{
		int r1 = 0, c1 = 0, r2 = 0, c2 = 0;
		for (int i = 1; i <= v.size(); i++) {
			if (v[i - 1] == 0) continue;
			if (r1 == 0) {
				r1 = arr[i][0];
				c1 = arr[i][1];
			}
			else {
				r2 = arr[i][0];
				c2 = arr[i][1];
			}
		}
		if (r1 + r2 > h && c1 + c2 > w) {}
		else if (r1 > h || c1 > w || r2 > h || c2 > w) {}
		else ans = max(ans, (r1 * c1) + (r2 * c2));
		swap(r1, c1);
		if (r1 + r2 > h && c1 + c2 > w) {}
		else if (r1 > h || c1 > w || r2 > h || c2 > w) {}
		else ans = max(ans, (r1 * c1) + (r2 * c2));
		swap(r2, c2);
		if (r1 + r2 > h && c1 + c2 > w) {}
		else if (r1 > h || c1 > w || r2 > h || c2 > w) {}
		else ans = max(ans, (r1 * c1) + (r2 * c2));
		swap(r1, c1);
		if (r1 + r2 > h && c1 + c2 > w) {}
		else if (r1 > h || c1 > w || r2 > h || c2 > w) {}
		else ans = max(ans, (r1 * c1) + (r2 * c2));
	} while (next_permutation(v.begin(), v.end()));


	cout << ans;

	return 0;
}
