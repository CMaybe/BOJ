#include<iostream>
#include<deque>
#include<cstring>
#include<cstdio>
using namespace std;

typedef struct POINT{
    int x;
    int y;
}point;
int arr[101][101];
int visit[101][101];
deque<point> dq;
int n,m;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
void bfs(){
    while(!dq.empty()){
        point c =dq.back();
        dq.pop_back();
        if(c.x==n && c.y==m){
            cout<<visit[c.y][c.x];
            return;
        }
        for(int i =0;i<4;i++){
            int nx = c.x+dx[i];
            int ny = c.y+dy[i];
            if(visit[ny][nx]!=-1) continue;
            if(nx <1 || nx>n || ny <1 || ny>m) continue;
            if(arr[ny][nx]==0){
                dq.push_back({nx,ny});
                visit[ny][nx]=visit[c.y][c.x];
            }
            else if(arr[ny][nx]==1){
                dq.push_front({nx,ny});
                visit[ny][nx]=visit[c.y][c.x]+1;
            }
        }
    }
}

int main()
{
    memset(visit,-1,sizeof(visit));
    
    cin >>n>>m;
    visit[1][1]=0;
    dq.push_back({1,1});
    for(int i =1;i<=m;i++){
        for(int j =1;j<=n;j++){
            scanf("%1d",&arr[i][j]);
        }
    }
    bfs();
    
    return 0;
}
