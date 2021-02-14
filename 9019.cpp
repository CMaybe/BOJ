#include <iostream>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

bool visit[10001];

typedef struct DUMP{
    int n;
    int cnt;
    string cmd;
}Dump;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int s;
    cin >> s;
    for(int i = 0;i<s;i++){
        int a,b;
        queue<Dump> q;
        cin>>a>>b;
        memset(visit,0,sizeof(visit));
        visit[a]=true;
        q.push({a,0,""});
        while(q.empty()==false){
            Dump t=q.front();
            q.pop();
            if(t.n==b){
                cout<<t.cmd<<'\n';
                break;
            }
            int temp = t.n*2%10000;
            if(visit[temp]==false){
                visit[temp]=true;
                q.push({temp,t.cnt+1,t.cmd+"D"});
            }
            
            temp = t.n -1 ;
            if(temp==-1)temp=9999;
            if(visit[temp]==false){
                visit[temp]=true;
                q.push({temp,t.cnt+1,t.cmd+"S"});
            }
            
            int d1,d2,d3,d4;
            temp = t.n;
            d4=temp%10;
            temp/=10;
            d3=temp%10;
            temp/=10;
            d2=temp%10;
            temp/=10;
            d1=temp%10;
            temp/=10;
            temp = d2*1000+d3*100+d4*10+d1;
            if(visit[temp]==false){
                visit[temp]=true;
                q.push({temp,t.cnt+1,t.cmd+"L"});
            }
            
            temp = t.n;
            d4=temp%10;
            temp/=10;
            d3=temp%10;
            temp/=10;
            d2=temp%10;
            temp/=10;
            d1=temp%10;
            temp/=10;
            temp = d4*1000+d1*100+d2*10+d3;
            if(visit[temp]==false){
                visit[temp]=true;
                q.push({temp,t.cnt+1,t.cmd+"R"});
            }
            
        }
    }
    
    return 0;
}
