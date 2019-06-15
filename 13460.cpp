#include<cstdio>
#include<queue>
#include<cmath>
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

#define RED 0
#define BLUE 1

typedef struct POINT {
	int x;
	int y;
}Point;


using namespace std;


bool flag[8];
int m, n, _min = 11;
char arr[13][13];
int cnt[13][13][13][13];
Point bfs[12][12][5] = { 0, };
Point goal;

Point sr, sb;

queue<Point> red;
queue<Point> blue;


int main(void)
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %1c", &arr[i][j]);
			if (arr[i][j] == 'B') {
				sb.x = j;
				sb.y = i;
				blue.push(Point{ j,i });
			}
			else if (arr[i][j] == 'R') {
				sr.x = j;
				sr.y = i;
				red.push(Point{ j,i });
			}
			else if (arr[i][j] == 'O') {
				goal.x = j;
				goal.y = i;
			}

		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] != '#') {
				int k = 0;
				for (k = 0; arr[i - k][j] != '#' && arr[i - k][j] != 'O'; k++) {}
				if (arr[i - k][j] == '#')k--;
				bfs[i][j][UP] = (Point{ j,i - k });
				for (k = 0; arr[i + k][j] != '#' && arr[i + k][j] != 'O'; k++) {}
				if (arr[i + k][j] == '#')k--;
				bfs[i][j][DOWN] = (Point{ j,i + k });
				for (k = 0; arr[i][j + k] != '#' && arr[i][j + k] != 'O'; k++) {}
				if (arr[i][j+k] == '#')k--;
				bfs[i][j][RIGHT] = (Point{ j + k ,i });
				for (k = 0; arr[i][j - k] != '#' && arr[i][j - k] != 'O'; k++) {}
				if (arr[i][j - k] == '#')k--;
				bfs[i][j][LEFT] = (Point{ j - k ,i });
			}

		}
	}

	while (!red.empty())
	{
		Point r = red.front();
		Point b = blue.front();
		red.pop();
		blue.pop();

		if (cnt[r.x][r.y][b.x][b.y] >=10) {
			continue;
		}
		if (r.x == b.x) {
			if (bfs[r.y][r.x][UP].y == bfs[b.y][b.x][UP].y) {
				r.y > b.y ? bfs[r.y][r.x][UP].y++ : bfs[b.y][b.x][UP].y++;
			}
			if (bfs[r.y][r.x][DOWN].y == bfs[b.y][b.x][DOWN].y)
				r.y < b.y ? bfs[r.y][r.x][DOWN].y-- : bfs[b.y][b.x][DOWN].y--;
		}
		if (r.y == b.y) {
			if (bfs[r.y][r.x][LEFT].x == bfs[b.y][b.x][LEFT].x)
				r.x > b.x ? bfs[r.y][r.x][LEFT].x++ : bfs[b.y][b.x][LEFT].x++;
			if (bfs[r.y][r.x][RIGHT].x == bfs[b.y][b.x][RIGHT].x)
				r.x < b.x ? bfs[r.y][r.x][RIGHT].x-- : bfs[b.y][b.x][RIGHT].x--;
		}

		for (int i = 1; i <= 4; i++) {
			Point rt = bfs[r.y][r.x][i];
			Point bt = bfs[b.y][b.x][i];
			if (bt.x == goal.x && bt.y == goal.y) {
				continue;
			}
			else if (rt.x == sr.x && rt.y == sr.y && bt.x == sb.x && bt.y == sb.y) {
				continue;
			}
			else if (rt.x == goal.x && rt.y == goal.y) {
				switch (i)
				{
				case UP:
					if (bt.x == goal.x && bt.y-1 == goal.y) {
						continue;
					}
					break;
				case DOWN:
					if (bt.x == goal.x && bt.y+1 == goal.y) {
						continue;
					}
					break;
				case RIGHT:
					if (bt.x+1 == goal.x && bt.y == goal.y) {
						continue;
					}
					break;
				case LEFT:
					if (bt.x-1 == goal.x && bt.y == goal.y) {
						continue;
					}
					break;
				}
				if (_min > cnt[r.x][r.y][b.x][b.y] + 1) {
					_min = cnt[r.x][r.y][b.x][b.y] + 1;
					continue;
				}
			}
			else if (cnt[rt.x][rt.y][bt.x][bt.y] == 0) {
				cnt[rt.x][rt.y][bt.x][bt.y] = cnt[r.x][r.y][b.x][b.y] + 1;
				red.push(Point{ rt.x,rt.y });
				blue.push(Point{ bt.x,bt.y });

			}
			else if (cnt[rt.x][rt.y][bt.x][bt.y] > cnt[r.x][r.y][b.x][b.y] + 1) {
				cnt[rt.x][rt.y][bt.x][bt.y] = cnt[r.x][r.y][b.x][b.y] + 1;
				red.push(Point{ rt.x,rt.y });
				blue.push(Point{ bt.x,bt.y });


			}
		}

		if (r.x == b.x) {
			if (abs(bfs[r.y][r.x][UP].y-bfs[b.y][b.x][UP].y)==1) {
				r.y > b.y ? bfs[r.y][r.x][UP].y-- : bfs[b.y][b.x][UP].y--;
			}
			if (abs(bfs[r.y][r.x][DOWN].y- bfs[b.y][b.x][DOWN].y)==1)
				r.y < b.y ? bfs[r.y][r.x][DOWN].y++ : bfs[b.y][b.x][DOWN].y++;
		}
		if (r.y == b.y) {
			if (abs(bfs[r.y][r.x][LEFT].x- bfs[b.y][b.x][LEFT].x)==1)
				r.x > b.x ? bfs[r.y][r.x][LEFT].x-- : bfs[b.y][b.x][LEFT].x--;
			if (abs(bfs[r.y][r.x][RIGHT].x-bfs[b.y][b.x][RIGHT].x)==1)
				r.x < b.x ? bfs[r.y][r.x][RIGHT].x++ : bfs[b.y][b.x][RIGHT].x++;
		}
	}

	if (_min == 11)_min = -1;
	printf("%d", _min);
}
