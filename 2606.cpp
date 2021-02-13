#include <iostream>
#include<queue>
using namespace std;

int arr[101][101];
bool visit[101];


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int n,m,a,b;
    queue<int> q;
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        cin>>a>>b;
        arr[a][b]=1;
        arr[b][a]=1;
    }
    q.push(1);
    visit[1]=true;
    int ans=0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        ans++;
        for(int i = 1;i<=n;i++){
            if(visit[i])continue;
            if(arr[cur][i]==1){
                visit[i]=true;
                q.push(i);
            }
            
        }
    }
    cout<<ans-1;
    return 0;
}
