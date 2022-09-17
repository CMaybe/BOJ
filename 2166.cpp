#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct POINT {
	double x;
	double y;
}Point;

vector<Point> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	double x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		v.push_back({ x,y });
	}
	double ans = 0;
	for (int i = 0; i < n - 1; i++) {
		ans += v[i].x * v[i + 1].y;
		ans -= v[i].y * v[i + 1].x;
	}
	ans += v[n - 1].x * v[0].y;
	ans -= v[n - 1].y * v[0].x;


	cout << fixed;
	cout.precision(1);
	cout << abs(ans/2);

	return 0;
}	
