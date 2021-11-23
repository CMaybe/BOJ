#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct POINT {
	int a;
	int b;
}Point;

bool visit[201][201];

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);

	int a, b, c;
	cin >> a >> b >> c;
	queue<Point> q;
	q.push({ 0,0 });
	visit[0][0] = true;
	vector<int> v;
	while (!q.empty()) {
		Point cur = q.front();
		q.pop();
		int x = cur.a;
		int y = cur.b;
		int z = c - x - y;
		if (x == 0) v.push_back(z);

		int w = min(x, b - y);
		if (visit[x - w][y + w] == false) {
			visit[x - w][y + w] = true;
			q.push({ x - w, y + w });
		}

		w = min(x, c - z);
		if (visit[x - w][y] == false) {
			visit[x - w][y] = true;
			q.push({ x - w, y });
		}

		w = min(y, a - x);
		if (visit[x + w][y - w] == false) {
			visit[x + w][y - w] = true;
			q.push({ x + w, y - w });
		}

		w = min(y, c - z);
		if (visit[x][y - w] == false) {
			visit[x][y - w] = true;
			q.push({ x,  y - w });
		}

		w = min(z, a - x);
		if (visit[x + w][y] == false) {
			visit[x + w][y] = true;
			q.push({ x + w, y });
		}

		w = min(z, b - y);
		if (visit[x][y + w] == false) {
			visit[x][y + w] = true;
			q.push({ x, y + w });
		}
	}

	sort(v.begin(), v.end());
	for (int i : v) cout << i << ' ';

	return 0;
}
