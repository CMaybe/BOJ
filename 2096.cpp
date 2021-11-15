#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[3];
int dp_max[2][3];
int dp_min[2][3];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[0] >> arr[1] >> arr[2];

		dp_max[1][0] = arr[0] + max(dp_max[0][0], dp_max[0][1]);
		dp_max[1][1] = arr[1] + max(max(dp_max[0][0], dp_max[0][2]), dp_max[0][1]);
		dp_max[1][2] = arr[2] + max(dp_max[0][2], dp_max[0][1]);

		dp_max[0][0] = dp_max[1][0];
		dp_max[0][1] = dp_max[1][1];
		dp_max[0][2] = dp_max[1][2];

		dp_min[1][0] = arr[0] + min(dp_min[0][0], dp_min[0][1]);
		dp_min[1][1] = arr[1] + min(min(dp_min[0][0], dp_min[0][2]), dp_min[0][1]);
		dp_min[1][2] = arr[2] + min(dp_min[0][2], dp_min[0][1]);

		dp_min[0][0] = dp_min[1][0];
		dp_min[0][1] = dp_min[1][1];
		dp_min[0][2] = dp_min[1][2];

	}


	int _max = max(max(dp_max[0][0], dp_max[0][2]), dp_max[0][1]);
	int _min = min(min(dp_min[0][0], dp_min[0][2]), dp_min[0][1]);
	cout << _max << ' ' << _min;
	return 0;
}
