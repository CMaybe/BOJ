#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;


bool arr[1001][1001];
int visit[1001][1001][11];
typedef struct POINT{
    int x;
    int y;
    int cnt;
}point;

int main()
{
	queue<point> dq;
	int n,m,k,a;
	int dx[]={0,0,1,-1};
	int dy[]={1,-1,0,0};

    memset(visit,-1,sizeof(visit));
    
    cin >>m>>n>>k;
    visit[1][1][0]=1;
    dq.push({1,1,0});
    for(int i =1;i<=m;i++){
        for(int j =1;j<=n;j++){
            scanf("%1d",&a);
			arr[i][j] = static_cast<bool>(a);
        }
    }
    while(!dq.empty()){
        point c =dq.front();
        dq.pop();
        if(c.x==n && c.y==m){
            cout<<visit[c.y][c.x][c.cnt];
            return 0;
        }
        for(int i =0;i<4;i++){
            int nx = c.x+dx[i];
            int ny = c.y+dy[i];
            if(ny*nx==1) continue;
            if(nx <1 || nx>n || ny <1 || ny>m) continue;
            if(arr[ny][nx]==0){
	            if(visit[ny][nx][c.cnt]!=-1) continue;
                dq.push({nx,ny,c.cnt});
                visit[ny][nx][c.cnt]=visit[c.y][c.x][c.cnt]+1;
            }
            else if(arr[ny][nx]==1 && c.cnt < k){
	            if(visit[ny][nx][c.cnt+1]!=-1) continue;
                dq.push({nx,ny,c.cnt + 1});
                visit[ny][nx][c.cnt+1]=visit[c.y][c.x][c.cnt]+1;
            }
        }
    }
    cout<<-1;
    return 0;
}
