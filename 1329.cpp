#include <iostream>
#include<string>
#include<queue>
#include<cmath>
#include<cstring>
using namespace std;
int arr[101][101];
bool visit[101];

typedef struct DUMP{
    int n;
    int cnt;
}Dump;
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int n,m,a,b,idx;
    cin>>n>>m;
    for(int i= 0;i<m;i++){
        cin>>a>>b;
        arr[a][b]=1;
        arr[b][a]=1;
    }
    
    int ans=1e9;
    for(int i =1;i<=n;i++){
        queue<Dump> q;
        int v=0;
        memset(visit,0,sizeof(visit));
        q.push({i,0});
        while(q.empty()==false){
            Dump t= q.front();
            v+=t.cnt;
            q.pop();
            for(int i =1;i<=n;i++){
                if(visit[i])continue;
                if(arr[t.n][i]==1){
                    visit[i]=true;
                    q.push({i,t.cnt+1});
                }
            }
        }
        if(ans>v){
            ans = v;
            idx=i;
        }
    }
    cout<<idx;
    
    return 0;
}
