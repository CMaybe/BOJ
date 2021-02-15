#include <iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

long long _max = 1e9;
typedef struct DATA{
    long long num;
    int cnt;
}Data;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n,m,ans;
    
    cin >>n>>m;
    queue<Data> q;
    q.push({n,0});
    bool flag = false;
    while(q.empty()==false){
        Data data= q.front();
        long long t = data.num;
        q.pop();
        if(t==m){
            ans = data.cnt;
            flag = true;
            break;
        }
        if(t*2<=_max){
            q.push({t*2,data.cnt+1});
        }
        if(stoll(to_string(t)+"1")<=_max){
            q.push({stoll(to_string(t)+"1"),data.cnt+1});
        }
    }
    ans++;
    if(flag == false)ans=-1;
    cout<<ans;
   
    return 0;
}
