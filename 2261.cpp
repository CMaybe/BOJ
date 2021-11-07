#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <string>

using namespace std;

typedef struct POINT{
	int x;
	int y;
}Point;

bool sortX(const Point&a,const Point&b){
	if(a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

bool sortY(const Point&a,const Point&b){
	if(a.y == b.y) return a.x < b.x;
	return a.y < b.y;
}

int dist(const Point&a,const Point&b){
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

int func(vector<Point>::iterator it, int n){
	if(n==2) return dist(it[0], it[1]);
	if(n==3) return min({dist(it[0], it[1]), dist(it[0], it[2]), dist(it[1], it[2])});
	int line = (it[n/2-1].x + it[n/2].x) / 2;
	int d = min(func(it, n/2), func(it+n/2, n-n/2));
	
	vector<Point> m;
	for(int i = 0;i<n;i++){
		int t = line - it[i].x;
		if(t*t<d) m.push_back(it[i]);
	}
	sort(m.begin(), m.end(), sortY);
	
	int len = m.size();
	for(int i = 0;i<len;i++){
		for(int j = i+1;j<len && (m[j].y - m[i].y) * (m[j].y - m[i].y) <d;j++){
			d = min(d,dist(m[i],m[j]));
		}
	}
	return d;
}

int main()
{
	
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	Point p;
	
	int n;
	cin >> n;
	vector<Point> v(n);
	for(int i = 0;i<n;i++){
		cin >> v[i].x >> v[i].y;
	}
	sort(v.begin(), v.end(), sortX);
	cout << func(v.begin(), n);
	return 0;
	
}
