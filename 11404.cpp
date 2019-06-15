#include<iostream>
#include<algorithm>
using namespace std;

int arr[101][101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int m, n,a,b,c;
	cin >> n >> m;
	while (m--)
	{
		cin >> a >> b >> c;
		if (arr[a][b] == 0) arr[a][b] = c;
		else arr[a][b] = min(arr[a][b], c);
	}

	for (int i = 1; i <= n; i++) { // m
		for (int j = 1; j <= n; j++) { //s

			for (int k = 1; k <= n; k++) {//e
				if (j == k) continue;
				if (arr[j][i] * arr[i][k] == 0)continue;
				if (arr[j][k] == 0) {
					arr[j][k] = arr[j][i] + arr[i][k];
				}
				else arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}
