#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    cin.tie(0);
	cin.sync_with_stdio(false);

    int n,k;
    cin >> n >> k;
    vector<vector<int>> graph(n+1);
    vector<int> idx(n+1);
    for(int i = 0;i<k;i++){
        int x, y;
        cin >> x>> y;
        graph[x].push_back(y);
        idx[y]++;
    }
    queue<int> q;
    for(int i  = 1;i<=n;i++){
        if(idx[i]==0) q.push(i);
    }
    vector<int> result(n+1);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout << cur << ' ';
        for(int next : graph[cur]){
            idx[next] -= 1;
            if(idx[next]==0) q.push(next);
        }
    }

	    


    return 0;
}
