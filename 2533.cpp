#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> visit;
vector<vector<int>> tree;
int dp[1000001][2];

void func(int node) {
	visit[node] = true;
	dp[node][1] = 1;
	for (int next : tree[node]) {
		if (visit[next] == false) {
			func(next);
			dp[node][1] += min(dp[next][0], dp[next][1]);
			dp[node][0] += dp[next][1];
		}
	}
}

int main() {
	int n;
	cin >> n;
	tree.resize(n + 1);
	visit.resize(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	func(1);
	cout << min(dp[1][0], dp[1][1]);
	
}
