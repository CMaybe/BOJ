#include<iostream>
#include<queue>
using namespace std;
int arr[2001][2001];

typedef struct E{
    int a,b;
}emo;
int n;
void bfs(){
    queue<emo> q;
    q.push({1,0});
    while(!q.empty()){
        int a=q.front().a;
        int b=q.front().b;
        q.pop();
        if(a==n){
            cout<<arr[a][b];
            return;
        }
        int na[]={a,a+b,a-1};
        int nb[]={a,b,b};
        
        for(int i =0;i<3;i++){
            if (na[i] < 0 || na[i] > 2*n) continue;
            if (arr[na[i]][nb[i]]>0) continue;
            q.push({na[i], nb[i]});
            arr[na[i]][nb[i]] = arr[a][b]+1;
        }
        
    }
}

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(0);
    cin >>n;
    bfs();
    
    return 0;
}

