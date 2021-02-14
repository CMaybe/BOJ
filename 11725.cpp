#include <iostream>
#include<vector>
using namespace std;

vector<vector<int>> v;
vector<int> p;

void dfs(int n){
    for(int t : v[n]){
        if(!p[t]){
            p[t]=n;
            dfs(t);
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    int **arr;
    cin>>n;
    
    v.resize(n+1);
    p.resize(n+1);
    
    for(int i =0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    p[1]=1;
    dfs(1);
    for(int i =2;i<=n;i++){
        cout<<p[i]<<'\n';
    }
    
    
    
    return 0;
}
