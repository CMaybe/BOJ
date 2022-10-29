#include <iostream>
#include <vector>

using namespace std;


int n, m;
int a, b, d;
vector<pair<int, int>> tree[40001];
int depth[40001];
bool visit[40001];
int dist[40001];
int parent[40001][100];

void getDepth(int cur, int dep, int dis) {
	visit[cur] = true;
	depth[cur] = dep;
	dist[cur] = dis;

	int size = tree[cur].size();
	for (int i = 0; i < size; i++) {
		if (!visit[tree[cur][i].first]) {
			parent[tree[cur][i].first][0] = cur;
			getDepth(tree[cur][i].first, dep + 1, dis + tree[cur][i].second);
		}
	}
}

void Union() {
	for (int i = 1; i < 100; i++) {
		for (int j = 1; j <= n; j++) {
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
		}
	}
}

int LCA(int a, int b)
{
	if (depth[a] < depth[b]) swap(a, b);
	int diff = depth[a] - depth[b];

	for (int i = 0; diff > 0; i++) {
		if (diff % 2 == 1) a = parent[a][i];
		diff /= 2;
	}

	if (a != b) {
		for (int i = 99; i >= 0; i--) {
			if (parent[a][i] != 0 && parent[a][i] != parent[b][i]) {
				a = parent[a][i];
				b = parent[b][i];
			}
		}
		a = parent[a][0];
	}

	return a;
}

int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;

		cin >> a >> b >> c;
		tree[a].push_back({ b,c });
		tree[b].push_back({ a,c });


	}

	getDepth(1, 0, 0);
	Union();
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		int lca = LCA(a, b);
		cout << dist[a] + dist[b] - 2 * dist[lca] << '\n';
	}
}
