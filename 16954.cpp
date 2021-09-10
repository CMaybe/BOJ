#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

typedef struct NODE{
	int x;
	int y;
	int t;
}Node;

int dir[3] ={-1,0,1};
bool visit[10000][8][8];

char arr[10000][8][8];
void down(int t){
	for(int i = 7;i>=0;i--){
		for(int j = 0;j<8;j++){
			arr[t+1][i][j]='.';
			if(arr[t][i][j]=='#'){
				if(i!=7) arr[t+1][i+1][j] = '#';
			}
		}
	}
}




int main()
{
	for(int i = 0;i<8;i++){
		for(int j = 0; j<8;j++){
			scanf(" %1c",&arr[0][i][j]);
		}
	}
	for(int t = 0;t<10000;t++){
		down(t);

	}
	queue<Node> q;
	q.push({0,7,0});
	while(!q.empty()){
		Node cur = q.front();
		q.pop();
		visit[cur.t][cur.y][cur.x]=true;
		if(cur.x==7 && cur.y==0){
			printf("1");
			return 0;
		}
		if(arr[cur.t][cur.y][cur.x]=='#') continue;
		for(int i = 0;i<3;i++){
			for(int j = 0;j<3;j++){
				if(cur.x + dir[i]>= 0 && cur.x + dir[i]< 8 
				   && cur.y + dir[j]>= 0 && cur.y + dir[j]< 8 
				   && visit[cur.t+1][cur.y + dir[j]][cur.x + dir[i]] == false
				   && arr[cur.t][cur.y + dir[j]][cur.x + dir[i]] == '.')
					q.push({cur.x + dir[i],cur.y + dir[j],cur.t+1});
			}
		}
	}
	printf("0");
	return 0;
	
}
