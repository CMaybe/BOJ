#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

vector<int> v[50001];

int depth[50001];
int parent[50001];
bool visit[50001];

void make(int pre, int cur, int cnt) {
	parent[cur] = pre;
	depth[cur] = cnt;

	for (int next : v[cur]) {
		if (visit[next]) continue;
		visit[next] = true;
		make(cur, next, cnt + 1);
	}
}

int find(int a, int b) {
	if (depth[a] > depth[b]) swap(a, b);
	
	if (a == b) return a;
	if (parent[a] == parent[b]) return parent[a];
	if (a == 1 || b == 1) return 1;
	if (depth[a] == depth[b]) return find(parent[a], parent[b]);
	return find(a, parent[b]);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n;

	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v[a].emplace_back(b);
		v[b].emplace_back(a);
	}
	visit[1] = true;
	make(0, 1, 0);

	cin >> m;

	for(int i = 0;i<m;i++){
		int a, b;
		cin >> a >> b;
		cout << find(a, b) << "\n";
	}

	return 0;
}
