#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;
char arr[22][22];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

bool visit[21][21][21][21];

typedef struct COIN{
	int x1;
	int y1;
	int x2;
	int y2;
	int t;
}Coin;



int main()
{
	int n,m;
	memset(arr,'-',sizeof(arr));
	Coin coin;
	coin.x1=-1;
	coin.t = 0;
	scanf("%d %d",&n,&m);
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			scanf(" %1c",&arr[i][j]);
			if(arr[i][j]=='o'){
				if(coin.x1==-1){
					coin.x1 = j;
					coin.y1 = i;
				}
				else{
					coin.x2 = j;
					coin.y2 = i;
				}
			}
		}
	}
	queue<Coin> q;
	q.push(coin);
	visit[coin.y1][coin.x1][coin.y2][coin.x2] = true;
	while(!q.empty()){
		Coin c = q.front();
		q.pop();
		if(c.t>10){
			printf("-1");
			return 0;
		}
		if(arr[c.y1][c.x1]=='-' && arr[c.y2][c.x2]!='-'){
			printf("%d",c.t);
			return 0;
		}
		
		if(arr[c.y1][c.x1]!='-' && arr[c.y2][c.x2]=='-'){
			printf("%d",c.t);
			return 0;
		}
		for(int i = 0;i<4;i++){
			int nx1 = c.x1 + dx[i];
			int nx2 = c.x2 + dx[i];
			int ny1 = c.y1 + dy[i];
			int ny2 = c.y2 + dy[i];
			if(visit[ny1][nx1][ny2][nx2]) continue;
			if(arr[ny1][nx1]=='-' && arr[ny2][nx2]=='-') continue;
			if(arr[ny1][nx1]=='#' && arr[ny2][nx2]=='#') continue;
			
			
			
			if(arr[ny1][nx1]=='.' && arr[ny2][nx2]=='.' && visit[ny1][nx1][ny2][nx2] == false){
				visit[ny1][nx1][ny2][nx2] = true;
				q.push({nx1,ny1,nx2,ny2,c.t+1});
			}	
		
			
			
			if(arr[ny1][nx1]=='-' && arr[ny2][nx2]!='#' && visit[ny1][nx1][ny2][nx2] == false){
				visit[ny1][nx1][ny2][nx2] = true;
				q.push({nx1,ny1,nx2,ny2,c.t+1});
			}	
		
			if(arr[ny1][nx1]!='#' && arr[ny2][nx2]=='-' && visit[ny1][nx1][ny2][nx2] == false){
				visit[ny1][nx1][ny2][nx2] = true;
				q.push({nx1,ny1,nx2,ny2,c.t+1});
			}
			
			
			
			
			if(arr[ny1][nx1]=='o' && arr[ny2][nx2]!='#' && visit[ny1][nx1][ny2][nx2] == false) {
				visit[ny1][nx1][ny2][nx2] = true;
				q.push({nx1,ny1,nx2,ny2,c.t+1});
				
			}
			if(arr[ny1][nx1]!='#' && arr[ny2][nx2]=='o' && visit[ny1][nx1][ny2][nx2] == false){
				visit[ny1][nx1][ny2][nx2] = true;
				q.push({nx1,ny1,nx2,ny2,c.t+1});
			}
			
			
			
			
			if(arr[ny1][nx1]=='#' && (arr[ny2][nx2]=='.' || arr[ny2][nx2]=='-') && visit[c.y1][c.x1][ny2][nx2] == false){
				visit[c.y1][c.x1][ny2][nx2] = true;
				q.push({c.x1,c.y1,nx2,ny2,c.t+1});
			}
			if((arr[ny1][nx1]=='.' || arr[ny1][nx1]=='-') && arr[ny2][nx2]=='#' && visit[ny1][nx1][c.y2][c.x2] == false){
				visit[ny1][nx1][c.y2][c.x2] = true;
				q.push({nx1,ny1,c.x2,c.y2,c.t+1});
			}
			
			
			
		}
	}
	printf("-1");
}
