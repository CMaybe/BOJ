#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;


typedef struct POINT{
    int x;
    int y;
}point;

typedef struct NODE{
	int n;
	int id;
}Node;

Node arr[1001][1001];
bool visit[1001][1001];
int ans[1001][1001];
int arr2[1000001];


int n,m,k,a;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int cnt = 0;


int main()
{
    
    scanf("%d %d",&n,&m);
    for(int i =1;i<=n;i++){
        for(int j =1;j<=m;j++){
            scanf("%1d",&arr[i][j].n);
        }
    }
	int id = 0;

	for(int i =1;i<=n;i++){
        for(int j =1;j<=m;j++){
			if(arr[i][j].n==0 && arr[i][j].id==0){
				cnt = 0;
				id++;
				queue<point> q;
				q.push({j,i});
				visit[i][j] = true;
				while(!q.empty()){
					point c = q.front();
					q.pop();
					cnt++;
					arr[c.y][c.x].id = id;
					for(int idx =0;idx<4;idx++){
						int nx = c.x+dx[idx];
						int ny = c.y+dy[idx];
						if(visit[ny][nx]) continue;
						if(nx <1 || nx>m || ny <1 || ny>n ) continue;
						if(arr[ny][nx].n==0){
							visit[ny][nx] = true;
							q.push({nx,ny});
						}
					}
				}
				arr2[id] = cnt;
			}	
        }
    }
	
	for(int i =1;i<=n;i++){
        for(int j =1;j<=m;j++){
			if(arr[i][j].n==1){
				ans[i][j] = 1;
				int idxs[4];
				for(int idx =0;idx<4;idx++){
					int nx = j + dx[idx];
					int ny = i + dy[idx];
					idxs[idx] = arr[ny][nx].id;
					if(nx <1 || nx>m || ny <1 || ny>n ) continue;
					bool flag = true;
					for(int k=0;k<idx;k++){
						if(arr[ny][nx].id == idxs[k]){
							flag = false;
							break;
						}
					}
					if(flag) ans[i][j]+=arr2[arr[ny][nx].id];
	
				}
			}	
        }
    }
	
	for(int i =1;i<=n;i++){
        for(int j =1;j<=m;j++){
            printf("%d",ans[i][j] % 10);
        }
		printf("\n");
    }
	
    return 0;
}
