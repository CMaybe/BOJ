#include <iostream>

using namespace std;

bool visit[201][201];



int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	int cnt = 0;
	int n, m, a, b;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		visit[a][b] = true;
		visit[b][a] = true;
	}
	if (n < 3) {
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (visit[i][j] == true)continue;
			for (int k = j + 1; k <= n; k++) {
				if (visit[k][i] == true || visit[k][j] == true) continue;
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}
