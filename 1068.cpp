#include <iostream>
#include <vector>

using namespace std;

vector<int> tree[50];
bool visit[50];
int ans;

void dfs(int x) {
	if (visit[x]) return;
	visit[x] = true;
	bool flag = true;
	for (int i = 0; i < tree[x].size(); i++) {
		int next = tree[x][i];
		if (!visit[next]) {
			dfs(next);
			flag = false;
		}
	}
	if (flag) ans++;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int root = 0, n, k;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		if (t == -1) root = i;
		else tree[t].push_back(i);
	}
	cin >> k;
	visit[k] = true;
	dfs(root);
	cout << ans << "\n";
}
