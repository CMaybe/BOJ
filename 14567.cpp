#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

bool arr[1001][1001];
int result[1001];
bool visit[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	queue<int> q;
	int n, m, cnt = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = true;
	}
	for (int i = 1; i <= n; i++) {
		result[i] = 1;
		for (int j = 1; j < i; j++) {
			if (arr[j][i]) {
				result[i] = result[i] > result[j] + 1 ? result[i] : result[j] + 1;
			}
		}

	}
	for (int k = 1; k <= n; k++) {
		cout << result[k] << " ";
	}

	return 0;
}
