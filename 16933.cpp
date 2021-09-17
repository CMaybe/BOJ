#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;


bool arr[1001][1001];
int visit[1001][1001][11][2];
typedef struct POINT{
    int x;
    int y;
    int cnt;
	bool t;
}point;

int main()
{
	queue<point> dq;
	int n,m,k,a;
	int dx[]={0,0,1,-1};
	int dy[]={1,-1,0,0};

    memset(visit,-1,sizeof(visit));
    
    cin >>n>>m>>k;
    visit[1][1][0][1]=1;
    dq.push({1,1,0,true});
    for(int i =1;i<=n;i++){
        for(int j =1;j<=m;j++){
            scanf("%1d",&a);
			arr[i][j] = static_cast<bool>(a);
        }
    }
    while(!dq.empty()){
        point c =dq.front();
        dq.pop();
        if(c.x==m && c.y==n){
            cout<<visit[c.y][c.x][c.cnt][c.t];
            return 0;
        }
		if(visit[c.y][c.x][c.cnt][!c.t]==-1){
			dq.push({c.x,c.y,c.cnt, !c.t});
            visit[c.y][c.x][c.cnt][!c.t]=visit[c.y][c.x][c.cnt][c.t]+1;
		}
        for(int i =0;i<4;i++){
            int nx = c.x+dx[i];
            int ny = c.y+dy[i];
            if(ny*nx==1) continue;
            if(nx <1 || nx>m || ny <1 || ny>n) continue;
            if(arr[ny][nx]==0){
	            if(visit[ny][nx][c.cnt][!c.t]!=-1) continue;
                dq.push({nx,ny,c.cnt, !c.t});
                visit[ny][nx][c.cnt][!c.t]=visit[c.y][c.x][c.cnt][c.t]+1;
            }
            else if(arr[ny][nx]==1 && c.cnt < k && c.t){
	            if(visit[ny][nx][c.cnt+1][!c.t]!=-1) continue;
                dq.push({nx,ny,c.cnt + 1, !c.t});
                visit[ny][nx][c.cnt+1][!c.t]=visit[c.y][c.x][c.cnt][c.t]+1;
            }
        }
    }
    cout<<-1;
    return 0;
}
