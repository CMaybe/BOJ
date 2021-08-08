#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

typedef struct NODE{
	int next;
	int time;
}Node;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
	
	int tc;
	cin>>tc;
	while(tc--){
		int dist[2501] = {0,};
		int n,m,w,s,e,t;
		bool flag = false;
		cin>>n>>m>>w;
		for(int i = 0;i<=m;i++)dist[i] = 1e9;
		vector<vector<Node>> node;
		node.resize(n+1);
		for(int i = 0;i<m;i++){  // road
			cin>>s>>e>>t;
			node[e].push_back({s,t});
			node[s].push_back({e,t});
		}
			
		for(int i = 0;i<w;i++){ // w
			cin>>s>>e>>t;
			node[s].push_back({e,-t});
		}
		dist[1]=0;
		for(int i = 1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(auto& p : node[j]){
					if(dist[p.next]>p.time + dist[j]){
						dist[p.next] = p.time + dist[j];
						if (i == n)	flag = true;
					}
				}
			}
		}
		if(flag)cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}
