#include <iostream>
using namespace std;
int arr[101][101]; //i->j
bool v[101][101];
int n;


void DFS(int a, int b)
{
	arr[a][b] = 1;
	v[a][b] = true;
	for (int i = 1; i <= n; i++) {
		if (arr[b][i] && !v[a][i]) {
			DFS(a,i);
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] && !v[i][j])
				DFS(i, j);
		}
	}


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << arr[i][j]<<" ";
		}
		cout<< "\n";
	}
}
