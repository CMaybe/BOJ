#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
 
 
using namespace std;
 
#define SIZE 20001
vector<vector<int>> vec;
int check[SIZE];
int visit[SIZE];
int v, e;
bool bfs() {
    memset(check,0,sizeof(check));
    memset(visit,0,sizeof(visit));
    queue<int> q;
    int flag = 1;
    for (int i=1; i<=v; i++) {
        if (visit[i] != 0) continue;
        if (vec[i].size()==0) continue;
        q.push(i);
        
        while (!q.empty()) {
            int size = q.size();
            for (int j=0; j<size; j++) {
                int idx = q.front();
                q.pop();
                visit[idx]=1;
                check[idx]  = flag;
                for (int to: vec[idx]) {
                    if (visit[to] == 0) q.push(to);
                    else if (flag == check[to]){
                        return false;
                    }
                }
            }
            flag *=-1;
        }
    }
    
    return true;
}
 
 
int main(void) {
    int n;
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(0);
    cin >> n;
    for (int i=0;i<n;i++) {
        
        cin >> v >> e;
        vec.clear();
        vec.resize(SIZE);
        for (int j=0; j<e; j++) {
            int a,b;
            cin>>a>>b;
            vec[a].push_back(b);
            vec[b].push_back(a);
        }

        if (bfs()) cout << "YES\n";
        else cout <<"NO\n";
    }
    
    return 0;
}
