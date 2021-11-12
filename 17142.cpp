#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;

int arr[52][52];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

typedef struct POINT{
	int x;
	int y; 
	int t;
}Point;

int main()
{
	
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	memset(arr,-1,sizeof(arr));
	int ans = 1e9;
	int n, m;
	int z = 0;
	cin >> n >> m;
	vector<Point> v;
	vector<int> mask;
	int cnt = 0;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			cin>>arr[i][j];
			if(arr[i][j]==2){
				cnt++;
				v.push_back({j,i,0});
			}
			else if(arr[i][j]==0) z++;
		}
	}
	if(z==0){
		cout<<0;
		return 0;
	}
	for(int i = m;i<cnt;i++) mask.push_back(0);
	for(int i = 0;i<m;i++) mask.push_back(1);
	int arr2[52][52];
	do{
		int tz = z;
		memcpy(arr2,arr,sizeof(arr));
		queue<Point> q;
		for(int i = 0;i<cnt;i++){
			if(mask[i]==1){
				q.push(v[i]);
				arr2[v[i].y][v[i].x] = 3;
			}
		}
		int _time = 0;

		while(!q.empty()){
			auto cur = q.front();
			q.pop();
			if(cur.t >= ans) break;
			if(_time < cur.t)_time = cur.t;
			
			int x = cur.x;
			int y = cur.y;
			for(int i = 0;i<4;i++){
				int nx = x+dx[i];
				int ny = y+dy[i];
				if(arr2[ny][nx]==0 || arr2[ny][nx]==2){
					if(arr2[ny][nx]==0) tz--;
					arr2[ny][nx] = 3;
					q.push({nx, ny,cur.t+1});
				}
			}
			if(tz==0) break;
		}
		
		if(tz==0){
			while(!q.empty()){
				_time = max(_time, q.front().t);
				q.pop();
			}
			ans = min(ans, _time);
		}
		
	}while(next_permutation(mask.begin(),mask.end()));
	if(ans!=1e9) cout << ans;
	else cout << -1;
	return 0;
	
}
