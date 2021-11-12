#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;

bool visit[51];

int main()
{
	int n, m, k;
	cin >>n >>m>>k;
	vector<vector<int>> v1(n+1);
	vector<vector<int>> v2(m+1);
	queue<int> q;
	int t;
	for(int i = 0;i<k;i++){
		cin >> t;
		q.push(t);
	}
	for(int i = 1;i<=m;i++){
		int c;
		cin >> c;
		for(int j=0;j<c;j++){
			cin >> t;
			v2[i].push_back(t);
			v1[t].push_back(i);
		}
	}
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		for(int i : v1[cur]){
			if(visit[i]==false){
				visit[i]=true;
				for(int j : v2[i]) q.push(j);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=m;i++){
		if(visit[i]==false) ans++;
	}
	cout << ans;
	return 0;
	
}
