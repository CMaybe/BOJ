#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int tree[3001];
int arr[3001];

typedef struct POINT {
	int x;
	int y;
	bool operator<(const POINT p) const {
		if (x == p.x) return y < p.y;
		return x < p.x;
	}
	bool operator<=(const POINT p) const {
		if (x == p.x) return y <= p.y;
		return x <= p.x;
	}
}Point;

vector<pair<Point, Point>> points;



int ccw(Point a, Point b, Point c) {
	long long int t1 = a.x * b.y + b.x * c.y + c.x * a.y;
	long long int t2 = a.y * b.x + b.y * c.x + c.y * a.x;
	if (t2 - t1 < 0) return -1;
	if (t2 - t1 > 0) return 1;
	return 0;
}

int check(Point a, Point b, Point c, Point d) {
	int ab = ccw(a, b, c) * ccw(a, b, d);
	int cd = ccw(c, d, a) * ccw(c, d, b);
	if (ab == 0 && cd == 0) {
		if (b < a) swap(a, b);
		if (d < c) swap(c, d);
		return c <= b && a <= d;
	}
	return ab <= 0 && cd <= 0;
}

int find(int x) {
	if (tree[x] == x) return x;
	return tree[x] = find(tree[x]);
}

void Union(int a, int b) {
	a = find(a);
	b = find(b);
	tree[a] = b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) tree[i] = i;

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		Point a, b;
		cin >> a.x >> a.y >> b.x >> b.y;
		for (int j = 0; j < cnt; j++) {
			Point c = points[j].first;
			Point d = points[j].second;
			if (check(a, b, c, d)) {
				Union(j, cnt);
			}
		}
		points.push_back(make_pair(a, b));
		cnt++;
	}

	int ans = 0;
	for (int i = 0; i < cnt; i++) {
		if (arr[find(i)]++ == 0) {
			ans++;
		}
	}
	int _max = -1;
	for (int i = 0; i < cnt; i++) {
		_max = max(_max, arr[i]);
	}

	cout << ans << '\n' << _max;

	return 0;
}
