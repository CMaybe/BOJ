#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

typedef struct POINT {
	int x;
	int y;
}Point;

using namespace std;

char map[102][102];
int h, w;
int arr[102][102][3];

vector<Point> v;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void bfs() {
	v.push_back({ 0,0 });
	for (int i = 0; i < 3; i++) {
		int x1 = v[i].x, y1 = v[i].y;
		deque<Point> dq;
		dq.push_back({ x1,y1 });
		arr[y1][x1][i] = 0;
		while (!dq.empty()) {
			int cx = dq.front().x, cy = dq.front().y;
			dq.pop_front();
			for (int j = 0; j < 4; j++) {
				int nx = cx + dx[j];
				int ny = cy + dy[j];
				if (nx < 0 || ny > h + 1 || ny < 0 || nx > w + 1) continue;
				if (arr[ny][nx][i] >= 0 || map[ny][nx] == '*') continue;
				if (map[ny][nx] == '.') {
					arr[ny][nx][i] = arr[cy][cx][i];
					dq.push_front({ nx,ny });
				}
				else if (map[ny][nx] == '#') {
					arr[ny][nx][i] = arr[cy][cx][i] + 1;
					dq.push_back({ nx,ny });
				}
			}
		}
	}
}


int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);

	int n;
	scanf("%d", &n);
	while (n--) {
		memset(arr, -1, sizeof(arr));
		scanf("%d %d", &h, &w);
		v.clear();
		for (int i = 0; i <= h + 1; i++) {
			for (int j = 0; j <= w + 1; j++) {
				if (i == 0 || i == h + 1 || j == 0 || j == w + 1) {
					map[i][j] = '.';
					continue;
				}
				scanf(" %1c", &map[i][j]);
				if (map[i][j] == '$') {
					map[i][j] = '.';
					v.push_back({ j,i });
				}
			}
		}
		bfs();

		int ans = 1e9;
		int x, y;
		for (int i = 0; i <= h + 1; i++) {
			for (int j = 0; j <= w + 1; j++) {
				if (map[i][j] == '*') continue;
				if (arr[i][j][0] == -1 || arr[i][j][1] == -1 || arr[i][j][2] == -1) continue;
				int k = arr[i][j][0] + arr[i][j][1] + arr[i][j][2];
				if (map[i][j] == '#') k -= 2;
				if (k < ans) {
					ans = k;
					x = j;
					y = i;
				}
			}
		}

		printf("%d\n", ans);

	}

	return 0;
}
