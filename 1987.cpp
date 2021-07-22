#include <iostream>
#include<vector>
#include <cmath>
#include<algorithm>
#include<string>
using namespace std;

char arr[20][20];
int r,c;
int _max=-1;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
bool visit[30];

void dfs(int cnt,int x,int y){
	if(cnt>_max) _max = cnt;
	for(int i = 0;i<4;i++){
		int tx = x+dx[i];
		int ty = y+dy[i];
		if(tx<0 || ty<0 || ty>=r || tx>=c) continue;
		if(visit[arr[ty][tx]-'A']==false){
			visit[arr[ty][tx]-'A']=true;
			dfs(cnt+1,tx,ty);
			visit[arr[ty][tx]-'A']=false;
		}
	}
}


int main(int argc, char* argv[]) {
	vector<char> list;
	
	cin>>r>>c;
	for(int i = 0;i<r;i++){
		for(int j=0;j<c;j++){
			scanf(" %1c",&arr[i][j]);
		}
	}
	visit[arr[0][0]-'A']=true;
	dfs(1,0,0);
	std::cout<<_max;
	
	return 0;
}
