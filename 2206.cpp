#include<iostream>
#include<deque>
#include<cstring>
#include<cstdio>
using namespace std;

typedef struct POINT{
    int x;
    int y;
    int flag;
}point;
int arr[1001][1001];
int visit[1001][1001][2];
deque<point> dq;
int n,m;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void print(){
    cout<<'\n';
    for(int i =1;i<=m;i++){
        for(int j =1;j<=n;j++){
            cout<<visit[i][j][0]<<'\t';
        }
        cout<<'\n';
    }
    cout<<"=========================================\n";
    for(int i =1;i<=m;i++){
        for(int j =1;j<=n;j++){
            cout<<visit[i][j][1]<<'\t';
        }
        cout<<'\n';
    }
}

void bfs(){
    while(!dq.empty()){
        point c =dq.back();
        dq.pop_back();
        if(c.x==n && c.y==m){
            cout<<visit[c.y][c.x][c.flag];
            return;
        }
        for(int i =0;i<4;i++){
            int nx = c.x+dx[i];
            int ny = c.y+dy[i];
            if(ny*nx==1) continue;
            if(visit[ny][nx][c.flag]!=-1) continue;
            if(nx <1 || nx>n || ny <1 || ny>m) continue;
            if(arr[ny][nx]==0){
                dq.push_front({nx,ny,c.flag});
                visit[ny][nx][c.flag]=visit[c.y][c.x][c.flag]+1;
            }
            else if(arr[ny][nx]==1 && c.flag ==0){
                
                dq.push_back({nx,ny,1});
                visit[ny][nx][1]=visit[c.y][c.x][c.flag]+1;
            }
        }
    }
    cout<<-1;
}

int main()
{
    memset(visit,-1,sizeof(visit));
    
    cin >>m>>n;
    visit[1][1][0]=1;
    dq.push_back({1,1,0});
    for(int i =1;i<=m;i++){
        for(int j =1;j<=n;j++){
            scanf("%1d",&arr[i][j]);
        }
    }
    bfs();
    return 0;
}
