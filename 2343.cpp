#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

int arr[100001];


int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n, m, sum = 0;
	int ans;
	int s = 1, e = sum;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		s = max(s, arr[i]);
		sum += arr[i];
	}
	e = sum;
	while (s <= e) {
		int mid = (s + e) / 2;
		int cnt = 1;
		sum = arr[1];
		for (int i = 2; i <= n; i++) {
			if (sum + arr[i] > mid) {
				cnt++;
				sum = 0;
			}
			sum += arr[i];
		}
		if (cnt > m) {
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}
	
	cout << s;

	return 0;
}
