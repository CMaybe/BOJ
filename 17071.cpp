#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;

int visit[500001][2];

int main()
{
	
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	int n, k, ans = -1;
	cin >> n >>k;
	if(n==k){
		cout << 0;
		return 0;
	}
	memset(visit,-1, sizeof(visit));
	queue<pair<int, int>> q;
	q.push(make_pair(n, 0));
	visit[n][0] = 0;
	while(!q.empty()){
	    auto cur = q.front();
	    q.pop();
	    if(k+(cur.second+1)*cur.second/2 + cur.second+ 1 > 500000) continue;
	    if(cur.first > 0 && visit[cur.first-1][(cur.second+1)%2]<0){
			visit[cur.first-1][(cur.second+1)%2] = cur.second+1;
	        q.push(make_pair(cur.first-1, cur.second+ 1));
	    }
	    
	    if(cur.first <500000 && visit[cur.first+1][(cur.second+1)%2]<0){
			visit[cur.first+1][(cur.second+1)%2] = cur.second+1;
	        q.push(make_pair(cur.first+1, cur.second+ 1));
	    }
	    
	    
	    if(cur.first*2 <= 500000 && visit[cur.first*2][(cur.second+1)%2]<0){
			visit[cur.first*2][(cur.second+1)%2] = cur.second+1;
	        q.push(make_pair(cur.first*2, cur.second+ 1));
	    }
	}
	
	int t = 1;
	for(int i = k+1;i<=500000;i+=t){
		for(int j=0;j<2;j++){
			if(visit[i][j]>=0 && visit[i][j] <= t){
				if((t-visit[i][j]) % 2 == 0){
					if(ans==-1 || ans>t) ans = t;
				}
			}
		}
		t++;
	}
	cout << ans;
	return 0;
	
}
