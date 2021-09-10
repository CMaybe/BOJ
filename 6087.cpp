#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<deque>
#include<algorithm>


enum Dir{
	right,
	left,
	down,
	up,
};


typedef struct NODE{
	int x;
	int y;
	int cost;
	Dir dir;
}Node;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
char arr[101][101];
bool visit[101][101];
int main()
{
	int w,h;
	std::deque<Node> dq;
	bool flag = false;
	int gx,gy;
	scanf("%d %d",&w,&h);
	for(int i = 0;i<h;i++){
		for(int j = 0; j<w;j++){
			scanf(" %1c",&arr[i][j]);
			if(arr[i][j]=='C'){
				if(flag == false){
					flag = true;
					dq.push_back({j,i,0,right});
					dq.push_back({j,i,0,left});
					dq.push_back({j,i,0,up});
					dq.push_back({j,i,0,down});
				}
				else{
					gx=j;
					gy=i;	
				}
				
			} 
		}
	}
	
	
	while(!dq.empty()){
		Node cur = dq.front();
		visit[cur.y][cur.x]= true;
		dq.pop_front();
		if(cur.x == gx && cur.y == gy){
			printf("%d",cur.cost);
			return 0;
		}
		for(int i = 0;i<4;i++){
			int tx = cur.x + dx[i];
			int ty = cur.y + dy[i];
			if(tx >= 0 && tx < w && ty>=0 && ty<h 
			  && visit[ty][tx] == false && arr[ty][tx]!='*'){
				if(static_cast<Dir>(i)==cur.dir){
					dq.push_front({tx,ty,cur.cost,cur.dir});
				}
				else{
					dq.push_back({tx,ty,cur.cost+1,static_cast<Dir>(i)});
				}
			}
		}
		std::sort(dq.begin(), dq.end(),[](Node a,Node b) -> bool
        {
            return a.cost < b.cost;
        });
		
	}
	
	return 0;
	
}
