#include <iostream>
#include<vector>
using namespace std;
int n,m;
int visit[2001];
vector<int> v[2001];
int flag = 0;
void dfs(int to,int len){
    visit[to]=true;
    if(len == 4){
        flag = 1;
        return;
    }
    for(int i : v[to]){
        if(flag == 1) return;
        if(visit[i]==false){
            dfs(i,len+1);
            
        }
    }
    visit[to]=false;
    
}

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(0);
    cin >>n>>m;
    int a,b;
    for(int i =0;i<m;i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i =0;i<n;i++){
        if(flag == 1) {
            cout<<1;
            return 0;
        };
        dfs(i,0);
    }
    cout<<0;
    return 0;
}
