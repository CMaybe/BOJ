#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

typedef struct Point {
	int x;
	int y;
}Point;

int arr[1002][1002];
vector<Point> bfs[1002][1002];
queue<Point> q;

int main()
{
	int n, m, max = -1;
	scanf("%d %d", &m, &n);
	memset(arr, -2, sizeof(arr));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 1) {
				q.push(Point{ j,i });
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i - 1][j]>-1) {
				bfs[i][j].push_back(Point{ j,i - 1 });
			}
			if (arr[i + 1][j]>-1) {
				bfs[i][j].push_back(Point{ j,i + 1 });
			}
			if (arr[i][j - 1] >-1) {
				bfs[i][j].push_back(Point{ j - 1,i });
			}
			if (arr[i][j + 1] >-1) {
				bfs[i][j].push_back(Point{ j + 1,i });
			}
		}
	}

	while (!q.empty())
	{
		Point point = q.front();
		q.pop();
		for (Point i : bfs[point.y][point.x]) {

			if (arr[i.y][i.x] < 0) continue;
			if (arr[i.y][i.x] == 0) {
				q.push(i);
				arr[i.y][i.x] = arr[point.y][point.x] + 1;
				if (max < arr[i.y][i.x]) max = arr[i.y][i.x];
			}
			else if (arr[i.y][i.x] > arr[point.y][point.x] + 1) {
				arr[i.y][i.x] = arr[point.y][point.x] + 1;
				q.push(i);
				if (max < arr[i.y][i.x]) max = arr[i.y][i.x];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] == 0) {
				printf("-1");
				return 0;
			}
		}
	}
	if (max == -1)printf("0");
	else printf("%d", max-1);
	return 0;
}
