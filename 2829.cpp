#include <iostream>
#include <algorithm>

using namespace std;

int arr[402][402];


int arr1[402][402];
int arr2[402][402];

int main()
{

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			arr1[i][j] = arr[i][j] + arr1[i-1][j-1];
			arr2[i][j] = arr[i][j];
		}
		for (int j = n; j >= 1; j--) {
			arr2[i][j] = arr2[i][j] + arr2[i-1][j+1];
		}
	}
	int _max = -1e9;
	for (int k = 2; k <= n; k++) {
		for (int i = 0; i <= n - k; i++) {
			for (int j = 0; j <= n - k; j++) {
				int _main = arr1[i + k][j + k] - arr1[i][j];
				int _sub = arr2[i + k][j + 1] - arr2[i][j + k + 1];
				_max = max(_max, _main - _sub);
			}
		}
	}
	
	cout << _max;
	return 0;

}
