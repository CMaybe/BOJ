#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;


typedef struct POINT {
	long long int x, y;
	long long int p, q;
}Point;

long long int ccw(const Point& a, const Point& b, const Point& c) {
	return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

bool comp(const Point& a, const Point& b) {
	
	if (a.q * b.p != a.p * b.q) return a.q * b.p < a.p * b.q;
	if (a.y != b.y) return a.y < b.y;
	return a.x < b.x;

}

vector<Point> v;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long int x, y;
		cin >> x >> y;
		v.push_back({ x,y,0,0 });
	}

	sort(v.begin(), v.end(), comp);
	for (int i = 1; i < n; i++) {
		v[i].p = v[i].x - v[0].x;
		v[i].q = v[i].y - v[0].y;
	}
	sort(v.begin() + 1, v.end(), comp);

	stack<int> s;
	s.push(0);
	s.push(1);

	int c = 2;
	while (c < n) {
		while (s.size() >= 2) {
			int a, b;
			a = s.top();
			s.pop();
			b = s.top();
			if (ccw(v[b], v[a], v[c]) > 0) {
				s.push(a);
				break;
			}
		}
		s.push(c++);
	}

	cout << s.size();
}
