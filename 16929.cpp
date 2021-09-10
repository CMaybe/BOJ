#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

char arr[60][60];
bool visit[60][60];
int n,m;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
bool flag = false;
int sx=0,sy=0;
void dfs(int x,int y, int len, char c){
	if(flag) return;
	
	for(int i = 0;i<4;i++){
		int tx = x + dx[i];
		int ty = y + dy[i];
		if( tx >= 0 && tx < m && ty >= 0 && ty < n){
			if(arr[ty][tx] != c) continue;
			if(visit[ty][tx]==true){
				if(len>=3 && sx==tx && sy==ty){
					flag = true;
					return;
				}	
			}
			if(visit[ty][tx]==false){
				visit[ty][tx] = true;
				dfs(tx,ty,len+1,c);
				visit[ty][tx] = false;
			}
		}
		
	}
}

int main()
{
	scanf("%d %d",&n,&m);
	for(int i = 0;i<n;i++){
		for(int j = 0; j<m;j++){
			scanf(" %1c",&arr[i][j]);
		}
	}
	for(int i = 0;i<n;i++){
		for(int j = 0; j<m;j++){
			flag = false;
			sy = i;
			sx = j;
			visit[i][j] = true;
			dfs(j,i,1,arr[i][j]);
			visit[i][j] = false;
			if(flag){
				printf("Yes");
				return 0;
			}
		}
	}
	

	printf("No");
	return 0;
	
}
