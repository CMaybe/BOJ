#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

typedef struct NODE{
	int next;
	int weight;
}Node;

bool com(const Node&a, const Node& b){
	return a.weight > b.weight;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n, m, a, b, c;
	cin >> n >> m;
	vector<vector<Node>> v(n+1);
	for(int i = 0;i < m;i++){
		cin >> a >> b >> c;
		v[a].push_back({b,c});
		v[b].push_back({a,c});
	}
	for(int i = 1;i<=n;i++) sort(v[i].begin(), v[i].end(), com);
	cin >> a >> b;
	int s = 1,e=1000000000;
	bool visit[10001];
	int ans;
	while(s<=e){
		memset(visit, false, sizeof(visit));
		int m = (s+e)/2;
		queue<int> q;
		q.push(a);
		visit[a] = true;
		bool flag = false;
		while(!q.empty()){
			int cur = q.front();
			q.pop();
			if(cur==b){
				flag = true;
				break;
			}
			for(Node node : v[cur]){
				if(visit[node.next] || node.weight < m) continue;
				visit[node.next]=true;
				q.push(node.next);
			}
		}
		if(flag){
			ans = m;
			s=m+1;
		}
		else e=m-1;
	}
	cout << ans;
	return 0;
}
