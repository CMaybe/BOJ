#include <iostream>
#include <queue>
#include<cstring>
using namespace std;

int arr[100001];
bool visit[100001];

typedef struct POINT{
    int n;
    int cnt;
}Point;

int k,n,cnt = 0;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    queue<Point> q;
    cin>>n>>k;
    q.push({n,0});
    while(q.empty()==false){
        Point t = q.front();
        q.pop();
        if(arr[t.n]==0){
            arr[t.n]=t.cnt;
        }
        else if(t.cnt <= arr[t.n]){
            arr[t.n]=t.cnt;
        }
        else{
            continue;
        }
        if(t.n==k){
            cnt++;
            continue;
        }
        if(t.n-1>=0) q.push({t.n-1,t.cnt + 1});
        if(t.n+1<=100000) q.push({t.n+1,t.cnt + 1});
        if(t.n>0 &&t.n*2<=100000) q.push({t.n*2,t.cnt + 1});
    }
    
    cout <<arr[k]<<'\n'<<cnt;;
	return 0;
}
