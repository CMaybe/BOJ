#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int arr[102][102];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
bool visit[102][102];
typedef struct NODE {
	int x;
	int y;
}Node;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n, m, c = 0;
	cin >> n >> m;
	memset(arr, -1, sizeof(arr));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) c++;
		}
	}
	int t = 0;
	while (c > 0) {
		memset(visit, false, sizeof(visit));
		queue<Node> q;
		q.push({ 1,1 });
		while (!q.empty()) {
			Node cur = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = cur.x + dx[i];
				int ny = cur.y + dy[i];
				if (visit[ny][nx] == true) continue;
				if (arr[ny][nx] == 0) {
					q.push({ nx,ny });
					visit[ny][nx] = true;
				}
				else if(arr[ny][nx]>=1) arr[ny][nx]++;
			}
		}
		bool flag = false;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (arr[i][j] >= 3) {
					flag = true;
					arr[i][j] = 0;
					c--;
				}
				else if (arr[i][j] >= 1) arr[i][j] = 1;
			}
		}
		if (flag) t++;

	}

	cout << t;
	
	return 0;
}
