#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

typedef struct Point {
	int x;
	int y;
	int z;
}Point;
int arr[102][102][102];
vector<Point> bfs[102][102][102];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	queue<Point> q;

	int n, m, h, max = -1;
	cin >> m >> n >> h;
	memset(arr, -2, sizeof(arr));
	for (int k = 1; k <= h; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> arr[k][i][j];
				if (arr[k][i][j] == 1) {
					q.push(Point{ j,i,k });
				}
			}
		}
	}
	for (int k = 1; k <= h; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (arr[k][i - 1][j] > -1) {
					bfs[k][i][j].push_back(Point{ j,i - 1,k });
				}
				if (arr[k][i + 1][j] > -1) {
					bfs[k][i][j].push_back(Point{ j,i + 1 ,k });
				}
				if (arr[k][i][j - 1] > -1) {
					bfs[k][i][j].push_back(Point{ j - 1,i,k });
				}
				if (arr[k][i][j + 1] > -1) {
					bfs[k][i][j].push_back(Point{ j + 1,i,k });
				}
				if (arr[k - 1][i][j] > -1) {
					bfs[k][i][j].push_back(Point{ j ,i, k - 1 });
				}
				if (arr[k + 1][i][j] > -1) {
					bfs[k][i][j].push_back(Point{ j ,i,k + 1 });
				}
			}
		}
	}

	while (!q.empty())
	{
		Point point = q.front();
		q.pop();
		for (Point p : bfs[point.z][point.y][point.x]) {

			if (arr[p.z][p.y][p.x] < 0) continue;
			if (arr[p.z][p.y][p.x] == 0) {
				q.push(p);
				arr[p.z][p.y][p.x] = arr[point.z][point.y][point.x] + 1;
				if (max < arr[p.z][p.y][p.x]) max = arr[p.z][p.y][p.x];
			}
			else if (arr[p.z][p.y][p.x] > arr[point.z][point.y][point.x] + 1) {
				arr[p.z][p.y][p.x] = arr[point.z][point.y][point.x] + 1;
				q.push(p);
				if (max < arr[p.z][p.y][p.x]) max = arr[p.z][p.y][p.x];
			}
		}
	}
	for (int k = 1; k <= h; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (arr[k][i][j] == 0) {
					printf("-1");
					return 0;
				}
			}
		}
	}
	if (max == -1)printf("0");
	else printf("%d", max - 1);
	return 0;
}
