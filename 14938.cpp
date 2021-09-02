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

int arr[101];
int dp[101];
	
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	int _max=-1;
	int n,m,r,a,b,c;
	cin>>n>>m>>r;
	vector<vector<Edge>> v(n+1);
	for(int i = 0;i<n;i++){
		cin>>arr[i+1];
	}
	for(int i = 0;i<r;i++){
		cin>>a>>b>>c;
		v[a].push_back({b,c});
		v[b].push_back({a,c});
	}
	for(int i  = 1;i<=n;i++){
		int sum = 0;
		for(int j = 0;j<n;j++){
			dp[j+1]=1e9;
		}
		dp[i]=0;
		priority_queue<Edge,vector<Edge>,compare> pq;
		pq.push({i,0});
		while(!pq.empty()){
			int node = pq.top().node;
			int weight = pq.top().weight;
			pq.pop();
			for(auto x: v[node]){
				int next = x.node;
				int nWeight = weight+x.weight;
				if(dp[next]>nWeight){
					dp[next] = nWeight;
					pq.push({next,nWeight});
				}
			}
		}
		for(int j = 1;j<=n;j++){
			if(dp[j]<=m)sum+=arr[j];
		}
		_max = max(_max,sum);
	}
	cout<<_max;
	
	return 0;
	
}
