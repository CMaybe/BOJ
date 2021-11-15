#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dist[801][801];

typedef struct NODE {
	int next;
	int weight;
}Node;


int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	vector<vector<Node>> v;
	int v1, v2;
	int n, e, a, b, c;
	cin >> n >> e;
	v.resize(n + 1);
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
		v[b].push_back({ a, c });
	}

	cin >> v1 >> v2;
	for (int i = 0; i <= 800; i++) {
		for (int j = 0; j <= 800; j++) {
			if (i == j) dist[i][j] = 0;
			else dist[i][j] = 1e9;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (Node node : v[i]) {
			if (i == node.next) dist[i][node.next] = 0;
			else if (node.weight > 0) dist[i][node.next] = node.weight;
			else dist[i][node.next] = 1e9;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
			}
		}
	}
	int ans = min(dist[1][v1] + dist[v1][v2] + dist[v2][n], dist[1][v2] + dist[v2][v1] + dist[v1][n]);
	if (ans >= 1e9 || ans < 0) cout << -1;
	else cout << ans;


	return 0;
}
