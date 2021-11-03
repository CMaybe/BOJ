#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <queue>

using namespace std;

bool visit[10001];
typedef struct LEC{
	int d;
	int p;
}lecture;

bool cmp(const lecture&a, const lecture&b){
	return a.p>b.p;
}

int main()
{
	
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	int n;
	cin >> n;
	vector<lecture> v(n);
	for(int i = 0;i<n;i++){
		cin>>v[i].p>>v[i].d;
	}

	sort(v.begin(), v.end(), cmp);
	int date = 0;
	int sum = 0;
	for(lecture l : v){
		for(int i = l.d;i>=1;i--){
			if(visit[i]==false){
				sum+=l.p;
				visit[i] = true;
				break;
			}
		}
	}
	cout<<sum;
	
	
	
	return 0;
	
}
