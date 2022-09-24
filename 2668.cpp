#include <iostream>
#include <algorithm>


using namespace std;

int arr[101];
bool visit[101];
int ans = 0;
int n;
bool dfs(int x, int end){
    if(arr[x] == end){
        visit[x] = true;
        return true;
    }
    if(visit[x]==false){
        visit[x] = true;
        if(dfs(arr[x],end)){
            return true;
        }
        visit[x] = false;
        return false;
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i = 1;i<=n;i++){
        dfs(i,i);
    }
    
    for(int i = 1;i<=n;i++){
        if(visit[i]) ans++;
    }
    
    cout << ans <<'\n';
    for(int i = 1;i<=n;i++){
        if(visit[i]) cout << i <<'\n';
    }
    
}
