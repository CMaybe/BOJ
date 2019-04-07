#include<cstdio>
#include<string>
#include<queue>
#include<iostream>
using namespace std;

typedef struct Point {
	int x;
	int y;
}Point;

int v[101][101];
vector<Point> bfs[101][101];
queue<Point> q;


int arr[102][102];
int main()
{
	int n, m;
	string s;
	scanf("%d %d", &n, &m);
	cin.ignore(256, '\n');
	for (int i = 1; i <= n; i++) {
		getline(cin, s);
		for (int j = 0; j < m; j++) {
			arr[i][j + 1] = s[j] - '0';
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i - 1][j] * arr[i][j]) {
				bfs[i][j].push_back(Point{ j,i - 1 });
			}
			if (arr[i + 1][j] * arr[i][j]) {
				bfs[i][j].push_back(Point{ j,i + 1 });
			}
			if (arr[i][j - 1] * arr[i][j]) {
				bfs[i][j].push_back(Point{ j - 1,i });
			}
			if (arr[i][j + 1] * arr[i][j]) {
				bfs[i][j].push_back(Point{ j + 1,i });
			}
		}
	}
	v[1][1] = 1;
	q.push(Point{ 1,1 });
	while (!q.empty())
	{
		Point point = q.front();
		q.pop();
		for (Point i : bfs[point.y][point.x]) {
			if (v[i.y][i.x]==0) {
				q.push(i);
				v[i.y][i.x] = v[point.y][point.x] + 1;	
			}
			else if (v[i.y][i.x] > v[point.y][point.x] + 1) {
				v[i.y][i.x] = v[point.y][point.x] + 1;
				q.push(i);
			}
		}
	}
	printf("%d", v[n][m]);
}