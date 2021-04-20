#include <iostream>
#include <queue>
#include<stack>
#include<cstring>
using namespace std;

int arr[100001];
int path[100001];

typedef struct POINT{
    int n;
    int cnt;
    int pre;
}Point;

int k,n,cnt = 0;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    queue<Point> q;
    cin>>n>>k;
    q.push({n,0,-1});
    while(q.empty()==false){
        Point t = q.front();
        q.pop();
        if(arr[t.n]==0){
            arr[t.n]=t.cnt;
            path[t.n] = t.pre;
        }
        else if(t.cnt <= arr[t.n]){
            arr[t.n]=t.cnt;
            path[t.n] = t.pre;
        }
        else{
            continue;
        }
        if(t.n==k){
            cnt++;
            continue;
        }
        if(t.n-1>=0) q.push({t.n-1,t.cnt + 1, t.n});
        if(t.n+1<=100000) q.push({t.n+1,t.cnt + 1, t.n});
        if(t.n>0 &&t.n*2<=100000) q.push({t.n*2,t.cnt + 1, t.n});
    }
    int temp;
    stack<int> s;
    temp = k;
    for(int i = 0;i<=arr[k];i++){
        s.push(temp);
        temp = path[temp];
    }
    
    cout <<arr[k]<<'\n';
    while(!s.empty()){
        cout<<s.top()<<' ';
        s.pop();
    }
    
	return 0;
}
