#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;


typedef struct NODE{
	int node;
	int weight;
}Node;

vector<Node> arr[10001];
int _max = -1;
int sub=0;
void bfs(int t,int _len){
	bool visit[10001] = {false,};
	queue<Node> q;
	q.push({t,_len});
	while(!q.empty()){
		Node cur = q.front();
		visit[cur.node]=true;
		q.pop();
		if(_max < cur.weight){
			_max= cur.weight;
			sub = cur.node;
		}
		for(Node next : arr[cur.node]){
			if(visit[next.node]) continue;
			q.push({next.node,cur.weight + next.weight});
		}
	}
	
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
	int n,a,b,w;
	cin>>n;
	for(int i = 0;i<n-1;i++){
		cin>>a>>b>>w;
		arr[a].push_back({b,w});
		arr[b].push_back({a,w});
	}
	bfs(1,0);
	bfs(sub,0);
	cout<<_max;
    return 0;
}

/*
12
1 2 3
1 3 2
2 4 5
3 5 11
3 6 9
4 7 1
4 8 7
5 9 15
5 10 4
6 11 6
6 12 10
*/
