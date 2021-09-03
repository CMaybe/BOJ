#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

typedef struct EDGE{
    int node;
    int weight;
}Edge;


struct compare{
    bool operator()(Edge &a,Edge &b){
        if(a.weight==b.weight) return a.node>b.node;
        return a.weight>b.weight;
    }
};

int dp2[1001];
int dp[1001][1001];
	
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	int _max=-1;
	int n,m,x,a,b,c;
	cin>>n>>m>>x;
	vector<vector<Edge>> v(n+1);
	for(int i = 0;i<m;i++){
		cin>>a>>b>>c;
		v[a].push_back({b,c});
	}
	for(int j = 0;j<n;j++){
		for(int k = 0;k<n;k++){
			dp[k+1][j+1]=1e9;
		}
	}
	for(int i = 1;i<=n;i++){
		dp[i][i]=0;
		priority_queue<Edge,vector<Edge>,compare> pq;
		pq.push({i,0});
		while(!pq.empty()){
			int node = pq.top().node;
			int weight = pq.top().weight;
			pq.pop();
			for(auto t: v[node]){
				int next = t.node;
				int nWeight = weight+t.weight;
				if(dp[i][next]>nWeight){
					dp[i][next] = nWeight;
					pq.push({next,nWeight});
				}
			}
		}
	}
	
	for(int i = 0;i<n;i++){
		dp2[i+1]=1e9;
	}
	dp2[x]=0;
	priority_queue<Edge,vector<Edge>,compare> pq;
	pq.push({x,0});
	while(!pq.empty()){
		int node = pq.top().node;
		int weight = pq.top().weight;
		pq.pop();
		for(auto t: v[node]){
			int next = t.node;
			int nWeight = weight+t.weight;
			if(dp2[next]>nWeight){
				dp2[next] = nWeight;
				pq.push({next,nWeight});
			}
		}
	}
	int ans = -1;
	for(int i = 1;i<=n;i++){
		ans = max(ans,dp2[i]+dp[i][x]);
	}
	cout<<ans;
	return 0;
	
}
