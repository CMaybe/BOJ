#include <iostream>
#include <cmath>

using namespace std;

int visit[16]; //visit[y]=x;
int inv[16];//inv[x]=y;
int n,cnt;

void dfs(int r){
    if(r==n+1){
        cnt++;
        return;
    }
    
    bool flag  =  true;
    for(int i = 1;i<=n ;i++){
        flag= true;
        if(inv[i]>0) continue;
        for(int j =1;j<r;j++){
            if(abs(visit[j]-i) == abs(j-r)){
                flag = false;
                break;
            }
        }
        if(flag){
            visit[r]=i;
            inv[i] = r;
            dfs(r+1);
            visit[r]=0;
            inv[i]=0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    
    for(int i = 1;i<=n;i++){
        visit[1]=i;
        inv[i]=1;
        dfs(2);
        visit[1]=0;
        inv[i]=0;
    }

    cout <<cnt;
	return 0;
}
