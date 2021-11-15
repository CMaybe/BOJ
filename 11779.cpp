#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int dist[1001];
int arr[1001];

typedef struct NODE {
	int idx;
	int cost;
	NODE(int idx, int cost) :idx(idx), cost(cost) {}
	bool operator<(const NODE& a) const { return a.cost > cost; }
}Node;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	for (int i = 0; i <= 1000; i++) dist[i] = 1e9;

	int n, m;
	cin >> n >> m;
	vector<vector<Node>> v(n + 1);

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
	int s, e;
	cin >> s >> e;
	dist[s] = 0;
	priority_queue<Node> pq;
	pq.push({ s,0 });

	while (!pq.empty()) {
		Node cur = pq.top();
		pq.pop();

		if (cur.cost > dist[cur.idx]) continue;

		for (Node next : v[cur.idx]) {
			if (dist[next.idx] > next.cost + cur.cost) {
				dist[next.idx] = next.cost + cur.cost;
				arr[next.idx] = cur.idx;
				pq.push({ next.idx, dist[next.idx] });
			}
		}
	}

	vector<int> ans;
	int temp = e;
	while (temp > 0) {
		ans.push_back(temp);
		temp = arr[temp];
	}
	cout << dist[e] << '\n' << ans.size() << '\n';
	for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << ' ';

	return 0;
}
