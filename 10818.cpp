#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, t, max = -1e9, min = 1e9;
	cin >> t;
	while (t--)
	{
		cin >> n;
		if (max < n)max = n;
		if (min > n)min = n;
	}
	cout << min << " " << max;

}s
