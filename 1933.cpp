#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <queue>

using namespace std;

typedef struct LINE{
	int x1;
	int h;
	int x2;
}Line;

struct cmp {
    bool operator()(const Line& a, const Line& b){
		if(a.h==b.h){
			return a.x2 < b.x2;
		}
		return a.h < b.h;
	}
};
 

int main()
{
	
	std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
	
	vector<Line> lines;
	map<int, int> m;
	
	int n, x1, h, x2;
	cin >> n;
	for(int i = 0;i<n;i++){
		cin>> x1 >> h >> x2;
		lines.push_back({x1,h,x2});
		m[x1] = 1;
		m[x2] = 1;
	}
	
	
	sort(lines.begin(), lines.end(), [](const Line& a, const Line& b)-> bool {return a.x1 < b.x1;});
	
	priority_queue<Line, vector<Line>, cmp> pq;
	int cur = 0;
	int idx = 0;
	for(auto iter = m.begin(); iter!=m.end(); iter++){
		int x = iter->first;
		for(;idx<lines.size();idx++){
			if(x < lines[idx].x1) break;
			pq.push(lines[idx]);	
		}
		int temp = 0;
		while (!pq.empty()){
			if (pq.top().x2 > x){
				temp = pq.top().h;
				break;
			}
			pq.pop();
		}
		if(cur != temp){
			cur = temp;
			cout<< x << ' '<< cur <<' ';
		}
		
	}
	
	
	return 0;
	
}
