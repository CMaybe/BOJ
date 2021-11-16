#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

using ll = long long;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int arr[102][102];
bool visit[102][102];

typedef struct POINT {
	int x;
	int y;
}Point;


int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> v;
	memset(arr, -1, sizeof(arr));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			if (find(v.begin(), v.end(), arr[i][j]) == v.end()) v.push_back(arr[i][j]);
		}
	}

	sort(v.begin(), v.end());
	int s = 0;
	int e = v[v.size() - 1];
	int ans = v[v.size() - 1];
	int len = v.size();

	int p1 = 0, p2 = 0;
	bool flag = false;
	while (p1 < len && p2 < len) {
		flag = false;
		if (v[p1] <= arr[1][1] && arr[1][1] <= v[p2]) {
			memset(visit, false, sizeof(visit));
			queue<Point> q;
			q.push({ 1,1 });
			visit[1][1] = true;
			while (!q.empty()) {
				Point cur = q.front();
				q.pop();
				if (cur.x == n && cur.y == n) {
					flag = true;
					break;
				}
				for (int i = 0; i < 4; i++) {
					int nx = cur.x + dx[i];
					int ny = cur.y + dy[i];
					if (arr[ny][nx] == -1) continue;
					if (visit[ny][nx] == true) continue;
					if (v[p1] > arr[ny][nx] || arr[ny][nx] > v[p2]) continue;
					visit[ny][nx] = true;
					q.push({ nx,ny });
				}
			}
			while (!q.empty()) q.pop();
		}
		if (flag) {
			ans = min(v[p2] - v[p1], ans);
			p1++;
		}
		else p2++;

	}
	cout << ans;



	return 0;
}
