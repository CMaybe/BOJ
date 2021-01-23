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
char arr[101][101];
int visit[101][101];
deque<point> dq;
int r,c;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void print(){
    cout<<'\n';
    for(int i =1;i<=r;i++){
        for(int j =1;j<=c;j++){
            cout<<visit[i][j]<<'\t';
        }
        cout<<'\n';
    }
    cout<<"=========================================\n";
    for(int i =1;i<=r;i++){
        for(int j =1;j<=c;j++){
            cout<<arr[i][j]<<'\t';
        }
        cout<<'\n';
    }
}

void bfs(){
    while(!dq.empty()){
        point p =dq.back();
        dq.pop_back();
        if(arr[p.y][p.x]=='D'){
            cout<<visit[p.y][p.x];
            return;
        }
        for(int i =0;i<4;i++){
            int nx = p.x+dx[i];
            int ny = p.y+dy[i];
            if(visit[ny][nx]!=-1) continue;
            if(nx <1 || nx>c || ny <1 || ny>r) continue;
            
            if(p.flag==1){
                if(arr[ny][nx]=='.'){
                    dq.push_front({nx,ny,1});
                    arr[ny][nx]='*';
                }
            }
            else if(p.flag==0){
                if(arr[ny][nx]== '.' || arr[ny][nx]== 'D'){
                    dq.push_front({nx,ny,0});
                    visit[ny][nx]=visit[p.y][p.x]+1;
                }    
            }
            
        }
    }
    cout<<"KAKTUS";
}

int main()
{
    memset(visit,-1,sizeof(visit));
    
    cin >>r>>c;
    for(int i =1;i<=r;i++){
        for(int j =1;j<=c;j++){
            scanf(" %1c",&arr[i][j]);
            if(arr[i][j]=='S'){
                dq.push_front({j,i,0});
                visit[i][j]=0;
            }
            if(arr[i][j]=='*') dq.push_back({j,i,1});
        }
    }
    bfs();
    
    return 0;
}
