#include<iostream>

using namespace std;

long long int arr[1001][3] = { 0 };
long long int d[1001] = { 0 };

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n;
	long long int max = -1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i][0];
		d[i] = arr[i][0];
		long long int t = 0;
		for (int j = 1; j < i; j++) {
			if (arr[j][0] < arr[i][0] && d[j]>t) {
				t = d[j];
			}
		}
		d[i] += t;
		if (d[i] > max) max = d[i];
	}

	cout << max;
}
