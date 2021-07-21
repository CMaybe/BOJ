#include <iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#include <functional>
using namespace std;

typedef struct EDGE{
    int node;
    int weight;
}Edge;


struct compare{
    bool operator()(Edge &a,Edge &b){
        if(a.weight==b.weight) return a.node<b.node;
        return a.weight<b.weight;
    }
};

int dp[20001];

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int V, E;
	cin >> V >> E;
	int s,e;
	
	vector<vector<Edge>> arr(V + 1);
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[a].push_back({ b,c });
	}
	cin>>s>>e;
	
	for (int i = 1; i <= V; i++) dp[i] = 1e9;
	dp[s] = 0;
	priority_queue<Edge,vector<Edge>,compare> pq;
	pq.push({ s,0 });
	while (!pq.empty()) {
		int node = pq.top().node;
		if(node==e) break;
		int val = -pq.top().weight;
		pq.pop();
		for (auto x : arr[node]) {
			int next = x.node;
			int nWeight = val + x.weight;
			if (dp[next] > nWeight ) {
				dp[next] = nWeight;
				pq.push({next, -nWeight });
			}
		}
	}
	cout<<dp[e];

	return 0;
}
